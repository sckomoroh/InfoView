#include "RecoveryPointsParser.h"

#include <QDir>
#include <QDomDocument>
#include <QDebug>

RecoveryPointsParser::RecoveryPointsParser()
	: m_pListener(NULL)
{
	m_pStorage = new RecoveryPointsStorage;
}

RecoveryPointsParser::~RecoveryPointsParser()
{
}

void RecoveryPointsParser::setListener(IRecoveryPointsParserListener* pListener)
{
	m_pListener = pListener;
}

RecoveryPointsStorage* RecoveryPointsParser::storage()
{
	return m_pStorage;
}

void RecoveryPointsParser::parse(const QString& filePath)
{
	if (m_pListener != NULL)
	{
		m_pListener->onStartParsing();
	}

	m_pStorage->clear();

	QDir rpFolder(filePath);
	QFileInfoList rpAgentFolders = rpFolder.entryInfoList(QDir::Dirs);

	uint index = 0;
	uint foldersCount = rpAgentFolders.count();
	for each (QFileInfo rpAgentFolder in rpAgentFolders)
	{
		if (index < 2)
		{
			index++;
			continue;
		}

		index++;

		parseAgentFolder(rpAgentFolder);

		if (m_pListener != NULL)
		{
			m_pListener->onAgentParsed(index, foldersCount);
		}
	}

	qDebug() << "Parsing complete!";

	if (m_pListener != NULL)
	{
		m_pListener->onCompleteParsing();
	}
}

void RecoveryPointsParser::parseAgentFolder(const QFileInfo& fileInfo)
{
	QList<RecoveryPointRecord*> result;
	
	if (!fileInfo.isDir())
	{
		//qDebug() << "WARNING: The file is not folder.";
		return;
	}

	QDir agentDir(fileInfo.absoluteFilePath());
	QFileInfoList rpFiles = agentDir.entryInfoList(QDir::Files);
	uint index = 0;
	uint filesCount = rpFiles.count();
	int oldProgress = 0;
	for each(QFileInfo rpFile in rpFiles)
	{
		index++;
		//qDebug() << "INFO: Recovery point file: " << rpFile.fileName();
		RecoveryPointRecord* record = parseRecoveryPointFile(rpFile);
		result.append(record);

		int progress = (int)(100.0 / (double)filesCount * (double)index);

		if (progress != oldProgress)
		{
			oldProgress = progress;
			//qDebug() << "    File processed " << progress << " %";
		}

		if (m_pListener != NULL)
		{
			m_pListener->onRecoveryPointParsed(index, filesCount);
		}
	}

	if (!result.isEmpty())
	{
		m_pStorage->appendAgent(result);
	}
	else
	{
		qDebug() << "result is empty";
	}
}

RecoveryPointRecord* RecoveryPointsParser::parseRecoveryPointFile(const QFileInfo& fileInfo)
{
	QDomDocument rpDocument;
	QFile rpFile(fileInfo.absoluteFilePath());
	if (!rpFile.open(QIODevice::ReadOnly))
	{
		//qDebug() << "WARNING: Unable to open XML file";
		return NULL;
	}

	if (!rpDocument.setContent(&rpFile)) 
	{
		//qDebug() << "WARNING: Unable to parse XML file";
		rpFile.close();
		return NULL;
	}

	rpFile.close();

	RecoveryPointRecord* record = new RecoveryPointRecord;

	QDomElement rootElement = rpDocument.documentElement();
	
	QDomElement volumeImagesElement = rootElement.firstChildElement("agentVolumes");
	parseVolumes(volumeImagesElement, record);

	QDomElement agentVolumesElement = rootElement.firstChildElement("volumeImages");
	parseVolumeImageSummaries(agentVolumesElement, record);

	parseGeneralInfo(rootElement, record);

	return record;
}

void RecoveryPointsParser::parseGeneralInfo(const QDomElement& element, RecoveryPointRecord* record)
{
	record->m_agentHostName = element.firstChildElement("agentHostName").text();
	record->m_agentId = element.firstChildElement("agentId").text();
	record->m_recoveryPointId = element.firstChildElement("id").text();
	record->m_status = element.firstChildElement("status").text();
	record->m_timeStamp = QDateTime::fromString(element.firstChildElement("timeStamp").text(), Qt::ISODate);
	record->m_iSize = element.firstChildElement("size").text().toLongLong();
}

void RecoveryPointsParser::parseVolumes(const QDomElement& element, RecoveryPointRecord* record)
{
	QDomNodeList summaries = element.elementsByTagName("volume");
	uint nodesCount = summaries.count();

	for (uint i = 0; i < nodesCount; i++)
	{
		QDomElement summaryElement = summaries.at(i).toElement();
		Volume* volumeSummary = parseVolume(summaryElement);
		record->m_volumeList.append(volumeSummary);
	}
}

void RecoveryPointsParser::parseVolumeImageSummaries(const QDomElement& element, RecoveryPointRecord* record)
{
	QDomNodeList summaries = element.elementsByTagName("volumeImageSummary");
	uint nodesCount = summaries.count();

	for (uint i = 0; i < nodesCount; i++)
	{
		QDomElement summaryElement = summaries.at(i).toElement();
		VolumeImageSummary* volumeSummary = parseVolumeImageSummary(summaryElement);
		record->m_volumeSummaryList.append(volumeSummary);
	}
}

Volume* RecoveryPointsParser::parseVolume(const QDomElement& element)
{
	Volume* volume = new Volume;

	volume->m_deviceId = element.firstChildElement("deviceId").text();
	volume->m_bIsClean = element.firstChildElement("isClean").text() == "true" ? true : false;
	volume->m_displayName = element.firstChildElement("displayName").text();
	volume->m_driverId = element.firstChildElement("driverId").text();
	volume->m_fileSystem = element.firstChildElement("fileSystem").text();
	volume->m_iCapacity = element.firstChildElement("rawCapacity").text().toUInt();
	volume->m_iPreviousEpochNumber = element.firstChildElement("previousEpochNumber").text().toUInt();
	volume->m_iUsedCapacity = element.firstChildElement("usedCapacity").text().toUInt();
	volume->m_label = element.firstChildElement("label").text();
	volume->m_guidName = element.firstChildElement("name").firstChildElement("guidName").text();

	return volume;
}

VolumeImageSummary* RecoveryPointsParser::parseVolumeImageSummary(const QDomElement& element)
{
	VolumeImageSummary* imageSummary = new VolumeImageSummary;

	imageSummary->m_bHasExchange = element.firstChildElement("hasExchangeMetadata").text() == "true" ? true : false;
	imageSummary->m_bHasSql = element.firstChildElement("hasSqlServerMetadata").text() == "true" ? true : false;
	imageSummary->m_id = element.firstChildElement("id").text();
	imageSummary->m_status = element.firstChildElement("status").text();
	imageSummary->m_guidName = element.firstChildElement("volumeName").firstChildElement("guidName").text();
	imageSummary->m_displayName = element.firstChildElement("volumeName").firstChildElement("displayName").text();
	imageSummary->m_timestamp = QDateTime::fromString(element.firstChildElement("timeStamp").text(), Qt::ISODate);
	imageSummary->m_state = (CheckState)CheckStatesParser::parseCheckState(element.firstChildElement("state").text());

	QString strSize = element.firstChildElement("size").text();
	imageSummary->m_iSize = strSize.toLongLong();

	QDomElement volumeImageComponents = element.firstChildElement("volumeImageComponents");
	if (!volumeImageComponents.isNull() && volumeImageComponents.hasChildNodes())
	{
		QDomElement exchange = volumeImageComponents.firstChildElement("exchange");
		if (!exchange.isNull() && exchange.hasChildNodes())
		{
			Exchange* pExchage = parseExchangeComponentInfo(exchange);
			imageSummary->m_pExchange = pExchage;
		}

		QDomElement sqlServer = volumeImageComponents.firstChildElement("sqlServer");
		if (!sqlServer.isNull() && sqlServer.hasChildNodes())
		{
			QDomElement sqlInstances = sqlServer.firstChildElement("instances");
			QDomNodeList sqlInstanceList = sqlInstances.elementsByTagName("instance");
			uint instanceCount = sqlInstanceList.count();

			for (uint i = 0; i < instanceCount; i++)
			{
				SqlInstance* pSqlInstance = parseSqlInstance(sqlInstanceList.at(i).toElement());
				imageSummary->m_sqlInstances.append(pSqlInstance);
			}
		}
	}

	return imageSummary;
}

Exchange* RecoveryPointsParser::parseExchangeComponentInfo(const QDomElement& element)
{
	Exchange* pExchange = new Exchange;

	pExchange->m_displayName = element.firstChildElement("displayName").text();
	pExchange->m_version = element.firstChildElement("version").text();

	QDomNodeList mailStores = element.firstChildElement("mailStores").elementsByTagName("rpMailStore");
	uint nodeCount = mailStores.count();
	for (uint i = 0; i < nodeCount; i++)
	{
		QDomElement storeElement = mailStores.at(i).toElement();
		MailStore* pMailStore = parseMailStore(storeElement);
		pExchange->m_mailStores.append(pMailStore);
	}

	QDomNodeList legacyStorageGroups = element.firstChildElement("legacyStorageGroups").elementsByTagName("rpLegacyStorageGroup");
	uint legacyStorageGroupsCount = legacyStorageGroups.count();
	for (uint i = 0; i < legacyStorageGroupsCount; i++)
	{
		LegacyStorageGroup* pLegacyStorageGroup = parseLegacyStorageGroup(legacyStorageGroups.at(i).toElement());
		pExchange->m_legacyStorageGroups.append(pLegacyStorageGroup);
	}

	return pExchange;
}

MailStore* RecoveryPointsParser::parseMailStore(const QDomElement& element)
{
	MailStore* pMailStore = new MailStore;
	
	pMailStore->m_exchangeDatabasePath = element.firstChildElement("exchangeDatabasePath").text();
	pMailStore->m_logFilePath = element.firstChildElement("logFilePath").text();
	pMailStore->m_logPrefix = element.firstChildElement("logPrefix").text();
	pMailStore->m_name = element.firstChildElement("name").text();
	pMailStore->m_systemPath = element.firstChildElement("systemPath").text();

	QString checkResults = element.firstChildElement("checkResults").firstChildElement("flags").text();

	pMailStore->m_checkState = (CheckState)CheckStatesParser::parseCheckState(checkResults);

	return pMailStore;
}

SqlInstance* RecoveryPointsParser::parseSqlInstance(const QDomElement& element)
{
	SqlInstance* pInstance = new SqlInstance;

	pInstance->m_name = element.firstChildElement("name").text();
	pInstance->m_version = element.firstChildElement("version").text();

	QDomNodeList databases = element.firstChildElement("databases").elementsByTagName("rpDatabase");
	uint databasesCount = databases.count();

	for (uint i = 0; i < databasesCount; i++)
	{
		SqlDatabase* pDatabase = parseSqlDatabase(databases.at(i).toElement());
		pInstance->m_databases.append(pDatabase);
	}

	return pInstance;
}

SqlDatabase* RecoveryPointsParser::parseSqlDatabase(const QDomElement& element)
{
	SqlDatabase* pDatabase = new SqlDatabase;

	pDatabase->m_bIsOnline = element.firstChildElement("isOnline").text() == "true" ? true : false;

	QString sqlDatabaseCheckState = element.firstChildElement("checkResults").firstChildElement("flags").text();

	pDatabase->m_checkState = (CheckState)CheckStatesParser::parseCheckState(sqlDatabaseCheckState);
	pDatabase->m_name = element.firstChildElement("name").text();

	QDomNodeList logFiles = element.firstChildElement("logFiles").elementsByTagName("logFile");
	uint logFileCount = logFiles.count();
	for (uint i = 0; i < logFileCount; i++)
	{
		SqlLogFile* pLogFile = parseSqlLogFile(logFiles.at(i).toElement());
		pDatabase->m_logFiles.append(pLogFile);
	}

	QDomNodeList fileGroups = element.firstChildElement("fileGroups").elementsByTagName("fileGroup");
	uint fileGroupsCount = fileGroups.count();
	for (uint i = 0; i < fileGroupsCount; i++)
	{
		SqlFileGroup* pFileGroup = parseFileGroup(fileGroups.at(i).toElement());
		pDatabase->m_fileGroups.append(pFileGroup);
	}

	return pDatabase;
}

SqlLogFile* RecoveryPointsParser::parseSqlLogFile(const QDomElement& element)
{
	SqlLogFile* pSqlLogFile = new SqlLogFile;

	pSqlLogFile->m_fileName = element.firstChildElement("path").text();
	pSqlLogFile->m_iSize = element.firstChildElement("size").text().toLongLong();

	return pSqlLogFile;
}

SqlFileGroup* RecoveryPointsParser::parseFileGroup(const QDomElement& element)
{
	SqlFileGroup* pSqlFileGroup = new SqlFileGroup;
	
	pSqlFileGroup->m_bIsFileStream = element.firstChildElement("isFileStream").text() == "true" ? true : false;
	pSqlFileGroup->m_name = element.firstChildElement("name").text();

	QDomNodeList dataFiles = element.firstChildElement("dataFiles").elementsByTagName("dataFile");
	uint dataFilesCount = dataFiles.count();
	for (uint i = 0; i < dataFilesCount; i++)
	{
		SqlDataFile* pDataFile = parseDataFile(dataFiles.at(i).toElement());
		pSqlFileGroup->m_dataFiles.append(pDataFile);
	}

	return pSqlFileGroup;
}

SqlDataFile* RecoveryPointsParser::parseDataFile(const QDomElement& element)
{
	SqlDataFile* pSqlDataFile = new SqlDataFile;
	
	pSqlDataFile->m_fileName = element.firstChildElement("path").text();
	pSqlDataFile->m_iSize = element.firstChildElement("size").text().toLongLong();

	return pSqlDataFile;
}

LegacyStorageGroup* RecoveryPointsParser::parseLegacyStorageGroup(const QDomElement& element)
{
	LegacyStorageGroup* pLegacyStorageGroup = new LegacyStorageGroup;

	pLegacyStorageGroup->m_logFilePath = element.firstChildElement("logFilePath").text();
	pLegacyStorageGroup->m_logPrefix = element.firstChildElement("logPrefix").text();
	pLegacyStorageGroup->m_name = element.firstChildElement("name").text();
	pLegacyStorageGroup->m_systemPath = element.firstChildElement("systemPath").text();

	QDomNodeList mailStores = element.firstChildElement("mailStores").elementsByTagName("rpLegacyMailStore");
	uint mailStoresCount = mailStores.count();
	for (uint i = 0; i < mailStoresCount; i++)
	{
		LegacyMailStore* pLegacyMailStore = parseLegacyMailStore(mailStores.at(i).toElement());
		pLegacyStorageGroup->m_mailStores.append(pLegacyMailStore);
	}

	return pLegacyStorageGroup;
}

LegacyMailStore* RecoveryPointsParser::parseLegacyMailStore(const QDomElement& element)
{
	LegacyMailStore* pLegacyMailStore = new LegacyMailStore;

	QString checkResult = element.firstChildElement("checkResults").firstChildElement("flags").text();

	pLegacyMailStore->m_name = element.firstChildElement("name").text();
	pLegacyMailStore->m_checkState = (CheckState)CheckStatesParser::parseCheckState(checkResult);
	pLegacyMailStore->m_exchangeDatabasePath = element.firstChildElement("exchangeDatabasePath").text();
	pLegacyMailStore->m_mailStoreType = element.firstChildElement("mailStoreType").text();

	return pLegacyMailStore;
}
