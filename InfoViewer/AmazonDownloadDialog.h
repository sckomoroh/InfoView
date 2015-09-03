#ifndef AMAZONDOWNLOADDIALOG_H
#define AMAZONDOWNLOADDIALOG_H

#include <QDialog>
#include "ui_AmazonDownloadDialog.h"

#include "BucketModel.h"
#include "IAmazon.h"
#include "UnZipThread.h"

class AmazonDownloadDialog
	: public QDialog
	, public IAmazonListener
{
	Q_OBJECT
private:
	Ui::AmazonDownloadDialog ui;
	IAmazon*				m_amazon;
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

private:
	// Amazon handlers
	virtual void onStartRetrievingList();
	virtual void onObjectListRetrieved(const QList<AmazonObject>& objects);
	virtual void onDownloadingStarted();
	virtual void onDownloadingProgress(qint64 iCurrent, qint64 iTotal);
	virtual void onDownloadingCompleted();

private slots:
	void onSearchClicked();
	void onDownloadClicked();
	void onBrowseButtonClicked();

	void onCurrentLinkChanged(const QModelIndex& iCurrent, const QModelIndex& iPrevious);

	// UnZip thread handlers
	void onUnZipStarted();
	void onUnZipProgress(uint iCurrent, uint iTotal);
	void onUnZipComplete();

	void startRetrievingListHandler();
	void objectListRetrievedHandler(const QList<AmazonObject>& objects);
	void downloadingStartedHandler();
	void downloadingProgressHandler(qint64 iCurrent, qint64 iTotal);
	void downloadingCompletedHandler();

signals:
	void logsCompleted();

	void startRetrievingList();
	void objectListRetrieved(const QList<AmazonObject>& objects);
	void downloadingStarted();
	void downloadingProgress(qint64 iCurrent, qint64 iTotal);
	void downloadingCompleted();
};

#endif // AMAZONDOWNLOADDIALOG_H
