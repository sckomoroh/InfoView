#ifndef RECOVERYPOINTSPARSER_H
#define RECOVERYPOINTSPARSER_H

#include <QObject>

#include <QString>
#include <QFileInfo>
#include <QDomElement>
#include <QMap>

#include "RecoveryPointRecord.h"
#include "IRecoveryPointsParserListener.h"
#include "RecoveryPointsStorage.h"

#include "ILogClient.h"

class RecoveryPointsParser
{
private:
	IRecoveryPointsParserListener*	m_pListener;
	RecoveryPointsStorage*			m_pStorage;
	ILogClient* m_logClient;

public:
	RecoveryPointsParser();
	~RecoveryPointsParser();

	void setListener(IRecoveryPointsParserListener* pListener);

	void parse(const QString& filePath);

	RecoveryPointsStorage* storage();

private:
	void						parseAgentFolder(const QFileInfo& fileInfo);
	RecoveryPointRecord*		parseRecoveryPointFile(const QFileInfo& fileInfo);
	
	void						parseGeneralInfo(const QDomElement& element, RecoveryPointRecord* record);
	void						parseVolumes(const QDomElement& element, RecoveryPointRecord* record);
	void						parseVolumeImageSummaries(const QDomElement& element, RecoveryPointRecord* record);
	
	Volume*						parseVolume(const QDomElement& element);
	VolumeImageSummary*			parseVolumeImageSummary(const QDomElement& element);

	Exchange*					parseExchangeComponentInfo(const QDomElement& element);
	MailStore*					parseMailStore(const QDomElement& element);

	SqlInstance*				parseSqlInstance(const QDomElement& element);
	SqlDatabase*				parseSqlDatabase(const QDomElement& element);
	SqlLogFile*					parseSqlLogFile(const QDomElement& element);
	SqlFileGroup*				parseFileGroup(const QDomElement& element);
	SqlDataFile*				parseDataFile(const QDomElement& element);

	LegacyStorageGroup*			parseLegacyStorageGroup(const QDomElement& element);
	LegacyMailStore*			parseLegacyMailStore(const QDomElement& element);
};

#endif // RECOVERYPOINTSPARSER_H
