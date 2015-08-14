#pragma once

#include <QString>
#include <QDateTime>

#include "Exchange.h"
#include "SqlInstance.h"
#include "CheckStates.h"

class RecoveryPointsParser;

class VolumeImageSummary
{
private:
	bool m_bHasExchange;
	bool m_bHasSql;
	QString m_id;
	QString m_status;
	QString m_guidName;
	QString m_displayName;
	CheckStatesParser::CheckState m_state;
	QDateTime m_timestamp;
	qlonglong m_iSize;
	Exchange* m_pExchange;
	QList<SqlInstance*> m_sqlInstances;

public:
	VolumeImageSummary();
	~VolumeImageSummary();

	bool hasExchange();

	bool hasSql();

	const QString& id() const;

	const QString& status() const;

	const QString& guidName() const;

	const QString& displayName() const;

	CheckStatesParser::CheckState state();

	const QDateTime& timestamp() const;

	qlonglong size();

	Exchange* exchange();

	QList<SqlInstance*>& sqlInstances();

private:
	friend class RecoveryPointsParser;
};

