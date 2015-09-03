#include "AmazonDownloadDialog.h"

#include <QFileDialog>
#include <QDir>
#include <QDebug>

AmazonDownloadDialog::AmazonDownloadDialog(QWidget *parent)
	: QDialog(parent)
	, m_amazon(NULL)
{
	ui.setupUi(this);

	m_amazon = getAmazonInstance();
	m_amazon->addListener(this);
	m_amazon->refreshConfig();

	m_pBucketModel = new BucketModel(this);
	m_pUnZipThread = new UnZipThread(this);

	ui.searchResultTreeView->setModel(m_pBucketModel);
	ui.progressBar->hide();
	ui.phaseLabel->hide();

	QItemSelectionModel* pSelectionModel = ui.searchResultTreeView->selectionModel();
	connect(
		pSelectionModel,
		SIGNAL(currentChanged(const QModelIndex&, const QModelIndex&)),
		SLOT(onCurrentLinkChanged(const QModelIndex&, const QModelIndex&)));

	connect(ui.searchButton, SIGNAL(clicked()), SLOT(onSearchClicked()));
	connect(ui.downloadButton, SIGNAL(clicked()), SLOT(onDownloadClicked()));
	connect(ui.browseButton, SIGNAL(clicked()), SLOT(onBrowseButtonClicked()));

	connect(this, SIGNAL(startRetrievingList()), SLOT(startRetrievingListHandler()));
	connect(this, SIGNAL(downloadingStarted()), SLOT(downloadingStartedHandler()));
	connect(this, SIGNAL(downloadingCompleted()), SLOT(downloadingCompletedHandler()));

    connect(
        this,
        SIGNAL(objectListRetrieved(const QList<AmazonObject>&)),
        SLOT(objectListRetrievedHandler(const QList<AmazonObject>&)));

    connect(
        this,
        SIGNAL(downloadingProgress(qint64, qint64)),
        SLOT(downloadingProgressHandler(qint64, qint64)));

	connect(m_pUnZipThread, SIGNAL(unzipStarted()), SLOT(onUnZipStarted()));
	connect(m_pUnZipThread, SIGNAL(unzipComplete()), SLOT(onUnZipComplete()));
	connect(m_pUnZipThread, SIGNAL(unzipProgress(uint, uint)), SLOT(onUnZipProgress(uint, uint)));
}

AmazonDownloadDialog::~AmazonDownloadDialog()
{
    delete m_pBucketModel;
}

void AmazonDownloadDialog::onDownloadClicked()
{
	qDebug() << "[UI] Start download link";

    enableControls(false);

	m_amazon->startDownload(ui.linkLineEdit->text(), ui.locationLineEdit->text());
}

void AmazonDownloadDialog::onSearchClicked()
{
    qDebug() << "[UI] Start search bucket(s)";

    enableControls(false);

	m_pBucketModel->resetModel();
	m_amazon->startListObjects();
}

void AmazonDownloadDialog::downloadingStartedHandler()
{
	qDebug() << "[UI] Download started";

	ui.phaseLabel->setText("Downloading");

	ui.progressBar->show();
	ui.phaseLabel->show();
}

void AmazonDownloadDialog::downloadingProgressHandler(qint64 iCurrent, qint64 iTotal)
{
	ui.progressBar->setMaximum(iTotal);
	ui.progressBar->setValue(iCurrent);
}

void AmazonDownloadDialog::downloadingCompletedHandler()
{
	qDebug() << "[UI] Download completed";

    enableControls();

	ui.progressBar->hide();
	ui.phaseLabel->hide();

	unzip();
}

void AmazonDownloadDialog::startRetrievingListHandler()
{
    qDebug() << "[UI] Start retrieving buckets";

    ui.phaseLabel->setText("Retrieving buckets list");

	ui.progressBar->show();
    ui.progressBar->setValue(0);
    ui.progressBar->setMaximum(0);

	ui.phaseLabel->show();
}

void AmazonDownloadDialog::objectListRetrievedHandler(const QList<AmazonObject>& objectList)
{
    qDebug() << "[UI] Complete retrieving buckets";

    enableControls();

    ui.progressBar->hide();
	ui.phaseLabel->hide();

	QList<AmazonObject> objects;
	foreach(AmazonObject object, objectList)
	{
		if (object.link.contains(ui.searchLineEdit->text()))
		{
			objects.append(object);
		}
	}

	m_pBucketModel->setModelData(objects);

	ui.searchResultTreeView->resizeColumnToContents(0);
	ui.searchResultTreeView->resizeColumnToContents(1);
}

void AmazonDownloadDialog::onBrowseButtonClicked()
{
	QString folder = QFileDialog::getExistingDirectory();

	if (folder.isEmpty() || folder.isNull())
	{
		return;
	}

	ui.locationLineEdit->setText(folder);
}

void AmazonDownloadDialog::onCurrentLinkChanged(const QModelIndex& iCurrent, const QModelIndex&/* iPrevious*/)
{
	if (!iCurrent.isValid())
	{
		return;
	}

	AmazonObject* pObject = m_pBucketModel->rawData(iCurrent);
	if (pObject == NULL)
	{
		return;
	}

	ui.linkLineEdit->setText(pObject->link);
}

void AmazonDownloadDialog::enableControls(bool bEnable)
{
    ui.browseButton->setEnabled(bEnable);
    ui.downloadButton->setEnabled(bEnable);
    ui.searchButton->setEnabled(bEnable);

    ui.linkLineEdit->setEnabled(bEnable);
    ui.locationLineEdit->setEnabled(bEnable);
    ui.searchLineEdit->setEnabled(bEnable);

    ui.searchResultTreeView->setEnabled(bEnable);
}

void AmazonDownloadDialog::unzip()
{
	QString zipFileName = m_amazon->fileName();
    m_targetFolder = m_amazon->fileFolder() + "/" + m_amazon->baseFileName();

	QDir targetFolder(m_targetFolder);
	if (!targetFolder.exists())
	{
		QDir rootDir(targetFolder.rootPath());
		rootDir.mkpath(m_targetFolder);
	}

	m_pUnZipThread->setZipFileName(zipFileName);
	m_pUnZipThread->setTargetFolder(m_targetFolder);
	m_pUnZipThread->start();
}

void AmazonDownloadDialog::onUnZipStarted()
{
	qDebug() << "[UI] Unzip started";

	ui.progressBar->show();
	ui.phaseLabel->show();

	enableControls(false);

	ui.progressBar->setMaximum(100);
	ui.progressBar->setValue(0);
	ui.phaseLabel->setText("Unzipping logs");
}

void AmazonDownloadDialog::onUnZipProgress(uint iCurrent, uint iTotal)
{
	ui.progressBar->setMaximum(iTotal);
	ui.progressBar->setValue(iCurrent);
}

void AmazonDownloadDialog::onUnZipComplete()
{
	qDebug() << "[UI] Unzip complete";

	ui.progressBar->hide();
	ui.phaseLabel->hide();

	enableControls();

	emit logsCompleted();
}

void AmazonDownloadDialog::onStartRetrievingList()
{
	emit startRetrievingList();
}

void AmazonDownloadDialog::onObjectListRetrieved(const QList<AmazonObject>& objects)
{
	emit objectListRetrieved(objects);
}

void AmazonDownloadDialog::onDownloadingStarted()
{
	emit downloadingStarted();
}

void AmazonDownloadDialog::onDownloadingProgress(qint64 iCurrent, qint64 iTotal)
{
	emit downloadingProgress(iCurrent, iTotal);
}

void AmazonDownloadDialog::onDownloadingCompleted()
{
	emit downloadingCompleted();
}
