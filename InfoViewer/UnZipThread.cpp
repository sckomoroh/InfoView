#include "UnZipThread.h"

#include <QDebug>

UnZipThread::UnZipThread(QObject *parent)
	: QThread(parent)
{
	m_pZipInstance = getZipInstance();
}

UnZipThread::~UnZipThread()
{

}

void UnZipThread::run()
{
	emit unzipStarted();
	qDebug() << "[UNZIP-THREAD] Unzip started";

	std::wstring stdZipFileName = m_zipFileName.toStdWString();

	m_pZipInstance->setName(stdZipFileName);
	if (m_pZipInstance->openZip() == false)
	{
		qDebug() << "[UNZIP-THREAD] Unable to open the ZIP file to extract a logs";
		
		emit unzipComplete();

		return;
	}

	uint iItemsCount = m_pZipInstance->getItemsCount();

	for (uint i = 0; i < iItemsCount; i++)
	{
		QString itemName = QString::fromStdWString(m_pZipInstance->getItemName(i));
		
		qDebug() << "[UNZIP-THREAD] Try to unzip the item: " << itemName;

		QString targetName = m_targetFolder + "\\" + itemName;
		std::wstring stdTargetName = targetName.toStdWString();

		if (m_pZipInstance->unzipItem(i, stdTargetName) == false)
		{
			qDebug() << "[UNZIP-THREAD] Unable to unzip item #" << i << " name: " << itemName << " To: '" << targetName;
		}

		emit unzipProgress(i + 1, iItemsCount);
	}

	m_pZipInstance->closeZip();

	qDebug() << "[UNZIP-THREAD] Unzip complete";

	emit unzipComplete();
}
