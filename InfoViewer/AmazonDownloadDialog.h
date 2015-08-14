#ifndef AMAZONDOWNLOADDIALOG_H
#define AMAZONDOWNLOADDIALOG_H

#include <QDialog>
#include "ui_AmazonDownloadDialog.h"

#include "BucketModel.h"
#include "Amazon.h"
#include "UnZipThread.h"

class AmazonDownloadDialog : public QDialog
{
	Q_OBJECT
private:
	Ui::AmazonDownloadDialog ui;
	Amazon					m_amazon;
	BucketModel*			m_pBucketModel;
	UnZipThread*			m_pUnZipThread;
	QString					m_targetFolder;

public:
	AmazonDownloadDialog(QWidget *parent = 0);
	~AmazonDownloadDialog();

	inline QString& targetFolder()
	{
		return m_targetFolder;
	}

private:
    void enableControls(bool bEnable = true);
	void unzip();

private slots:
	void onSearchClicked();
	void onDownloadClicked();
	void onBrowseButtonClicked();

	void onCurrentLinkChanged(const QModelIndex& iCurrent, const QModelIndex& iPrevious);

	// UnZip thread handlers
	void onUnZipStarted();
	void onUnZipProgress(uint iCurrent, uint iTotal);
	void onUnZipComplete();

	// Amazon handlers
	void onStartRetrievingList();
	void onObjectListRetrieved(const QList<AmazonObject>& objects);

	void onDownloadingStarted();
	void onDownloadingProgress(qint64 iCurrent, qint64 iTotal);
	void onDownloadingCompleted();

signals:
	void logsCompleted();
};

#endif // AMAZONDOWNLOADDIALOG_H
