#include "UnZipThread.h"

#include <QDebug>

UnZipThread::UnZipThread(QObject *parent)
	: QThread(parent)
{
	m_pZipInstance = getZipInstance();
	m_logClient = getLogClientInstance();
}

UnZipThread::~UnZipThread()
{

}

void UnZipThread::run()
{
	emit unzipStarted();
	m_logClient->Info("<UNZIP-THREAD> Unzip started");

	std::wstring stdZipFileName = m_zipFileName.toStdWString();

	m_pZipInstance->setName(stdZipFileName);
	if (m_pZipInstance->openZip() == false)
	{
		m_logClient->Info("<UNZIP-THREAD> Unable to open the ZIP file to extract a logs");
		
		emit unzipComplete();

		return;
	}

	uint iItemsCount = m_pZipInstance->getItemsCount();

	for (uint i = 0; i < iItemsCount; i++)
	{
		QString itemName = QString::fromStdWString(m_pZipInstance->getItemName(i));

		m_logClient->Debug("<UNZIP-THREAD> Try to unzip the item: '%s'", itemName.toStdString().c_str());

		QString targetName = m_targetFolder + "\\" + itemName;
		std::wstring stdTargetName = targetName.toStdWString();

		if (m_pZipInstance->unzipItem(i, stdTargetName) == false)
		{
			m_logClient->Error("<UNZIP-THREAD> Unable to unzip item #%d name: %s To: %s", i, itemName.toStdString().c_str(), targetName.toStdString().c_str());
		}

		emit unzipProgress(i + 1, iItemsCount);
	}

	m_pZipInstance->closeZip();

	m_logClient->Info("<UNZIP-THREAD> Unzip complete");

	emit unzipComplete();
}
