#ifndef RECOVERYPOINTRECORD_H
#define RECOVERYPOINTRECORD_H

#include <QObject>
#include <QList>
#include <QDateTime>

#include "Volume.h"
#include "VolumeImageSummary.h"

class RecoveryPointsParser;

class RecoveryPointRecord
{
private:
	QString m_agentHostName;
	QString m_agentId;
	QString m_recoveryPointId;
	QString m_status;
	qlonglong m_iSize;
	QDateTime m_timeStamp;
	QList<Volume*> m_volumeList;
	QList<VolumeImageSummary*> m_volumeSummaryList;

public:
	~RecoveryPointRecord();

	const QString& agentHostName() const;

	const QString& agentId() const;

	const QString& recoveryPointId() const;

	const QString& status() const;

	qlonglong size() const;

	const QDateTime& timestamp() const;

	QList<Volume*>& volumes();

	QList<VolumeImageSummary*>& volumeImageSummuries();

	const QString content() const;

private:
	friend class RecoveryPointsParser;
};

#endif // RECOVERYPOINTRECORD_H
