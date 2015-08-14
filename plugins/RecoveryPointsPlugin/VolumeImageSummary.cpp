#include "VolumeImageSummary.h"


VolumeImageSummary::VolumeImageSummary()
	: m_pExchange(NULL)
{
}


VolumeImageSummary::~VolumeImageSummary()
{
	if (m_pExchange)
	{
		delete m_pExchange;
	}

	QList<SqlInstance*>::iterator iter = m_sqlInstances.begin();
	for (; iter != m_sqlInstances.end(); iter++)
	{
		SqlInstance* pData = *iter;
		delete pData;
	}

	m_sqlInstances.clear();
}

bool VolumeImageSummary::hasExchange()
{
	return m_bHasExchange;
}

bool VolumeImageSummary::hasSql()
{
	return m_bHasSql;
}

const QString& VolumeImageSummary::id() const
{
	return m_id;
}

const QString& VolumeImageSummary::status() const
{
	return m_status;
}

const QString& VolumeImageSummary::guidName() const
{
	return m_guidName;
}

const QString& VolumeImageSummary::displayName() const
{
	return m_displayName;
}

const QDateTime& VolumeImageSummary::timestamp() const
{
	return m_timestamp;
}

qlonglong VolumeImageSummary::size()
{
	return m_iSize;
}

Exchange* VolumeImageSummary::exchange()
{
	return m_pExchange;
}

QList<SqlInstance*>& VolumeImageSummary::sqlInstances()
{
	return m_sqlInstances;
}

CheckStatesParser::CheckState VolumeImageSummary::state()
{
	return m_state;
}
