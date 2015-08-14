#pragma once

#include <QString>
#include <QDomDocument>
#include <QDomElement>
#include <QList>
#include <QDateTime>


class MongoJobData
{
public:
	enum MongoJobType
	{
		ServiceJob	= 0x1,
		UserJob		= 0x2,
		Success		= 0x4,
		Fail		= 0x8,
		Cancel		= 0x10,
		Unknown		= 0x20
	};

private:
	QString					m_summary;
	QDateTime				m_startTime;
	QDateTime				m_creationTime;
	QDateTime				m_endTime;
	MongoJobType			m_status;
	QString					m_id;
	QString					m_phase;
	QString					m_errorMessage;
	QString					m_errorDetails;
	QString					m_errorStackTrace;
	QList<MongoJobData*>	m_childJobs;
	MongoJobData*			m_pParent;

public:
	~MongoJobData();

	static MongoJobData* parseFromContent(const QString& content);
	static MongoJobData* emptyObject();

	inline const QString& summary() const
	{
		return m_summary;
	}

	inline const QString& id() const
	{
		return m_id;
	}

	inline const QString& phase() const
	{
		return m_phase;
	}

	inline const QString& errorMessage() const
	{
		return m_errorMessage;
	}

	inline const QString& errorDetails() const
	{
		return m_errorDetails;
	}

	inline const QString& errorStackTrace() const
	{
		return m_errorStackTrace;
	}

	inline const QDateTime& startTime() const
	{
		return m_startTime;
	}

	inline const QDateTime&	creationTime() const
	{
		return m_creationTime;
	}

	inline const QDateTime&	endTime() const
	{
		return m_endTime;
	}

	inline MongoJobType	jobType()
	{
		return m_status;
	}

	inline QList<MongoJobData*>& childJobs()
	{
		return m_childJobs;
	}

	inline MongoJobData* parent()
	{
		return m_pParent;
	}

	void setParent(MongoJobData* pParent);

	static bool acsByMessage(MongoJobData* item1, MongoJobData* item2);
	static bool decsByMessage(MongoJobData* item1, MongoJobData* item2);

	static bool acsByTime(MongoJobData* item1, MongoJobData* item2);
	static bool decsByTime(MongoJobData* item1, MongoJobData* item2);

private:
	MongoJobData();
	static MongoJobData* parseFromElement(QDomElement element);
	static MongoJobType parseJobStatus(QString jobStatus);
};

