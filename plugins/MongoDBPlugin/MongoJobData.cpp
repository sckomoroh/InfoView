#include "MongoJobData.h"


MongoJobData::MongoJobData()
	: m_pParent(NULL)
{
}

MongoJobData::~MongoJobData()
{
}

MongoJobData* MongoJobData::emptyObject()
{
	return new MongoJobData();
}

void MongoJobData::setParent(MongoJobData* pParent)
{
	m_pParent = pParent;
}

MongoJobData* MongoJobData::parseFromContent(const QString& content)
{
	QDomDocument document;
	
	document.setContent(content);
	QDomElement element = document.documentElement();

	MongoJobData* result = MongoJobData::parseFromElement(element);

	QDomElement childJobsElement = element.firstChildElement("childJobs");
	if (!childJobsElement.isNull() && childJobsElement.hasChildNodes())
	{
		QDomElement childJobElement = childJobsElement.firstChildElement("job");

		while (!childJobElement.isNull())
		{
			MongoJobData* pChildJob = MongoJobData::parseFromElement(childJobElement);
			pChildJob->m_pParent = result;
			result->m_childJobs.append(pChildJob);
			childJobElement = childJobElement.nextSiblingElement("job");
		}
	}

	return result;
}

MongoJobData* MongoJobData::parseFromElement(QDomElement element)
{
	MongoJobData* object = new MongoJobData();
	object->m_summary = element.firstChildElement("summary").text();
	object->m_creationTime = QDateTime::fromString(element.firstChildElement("creationTime").text(), Qt::ISODate);
	object->m_startTime = QDateTime::fromString(element.firstChildElement("startTime").text(), Qt::ISODate);
	object->m_endTime = QDateTime::fromString(element.firstChildElement("endTime").text(), Qt::ISODate);
	object->m_id = element.firstChildElement("id").text();
	object->m_phase = element.firstChildElement("phase").text();
	QString jobStatus = element.firstChildElement("status").text();
	object->m_status = (MongoJobData::MongoJobType)(MongoJobData::parseJobStatus(jobStatus));
    object->m_status = (MongoJobData::MongoJobType)((int)object->m_status | (int)(element.firstChildElement("jobKind").text() == "ServiceJob" ? MongoJobData::ServiceJob : MongoJobData::UserJob));

	QDomElement failureElement = element.firstChildElement("failureReason");
	if (failureElement.hasChildNodes())
	{
		object->m_errorDetails = failureElement.firstChildElement("detail").text();
		object->m_errorMessage = failureElement.firstChildElement("message").text();
		object->m_errorStackTrace = failureElement.firstChildElement("stackTrace").text();
	}

	return object;
}

MongoJobData::MongoJobType MongoJobData::parseJobStatus(QString jobStatus)
{
	if (jobStatus == "Succeeded")
	{
        return MongoJobData::Success;
	}

	if (jobStatus == "Failed")
	{
        return MongoJobData::Fail;
	}

	if (jobStatus == "Canceled")
	{
        return MongoJobData::Cancel;
	}

    return MongoJobData::Unknown;
}

bool MongoJobData::acsByMessage(MongoJobData* item1, MongoJobData* item2)
{
	return item1->summary() < item2->summary();
}

bool MongoJobData::decsByMessage(MongoJobData* item1, MongoJobData* item2)
{
	return item1->summary() > item2->summary();
}

bool MongoJobData::acsByTime(MongoJobData* item1, MongoJobData* item2)
{
	return item1->creationTime() < item2->creationTime();
}

bool MongoJobData::decsByTime(MongoJobData* item1, MongoJobData* item2)
{
	return item1->creationTime() > item2->creationTime();
}
