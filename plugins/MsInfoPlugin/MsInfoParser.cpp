#include "MsInfoParser.h"

#include <QFile>
#include <QDomDocument>
#include <QDebug>

MsInfoParser::MsInfoParser()
	: m_pListener(NULL)
{
	m_pStorage = new MsInfoStorage;
}

MsInfoParser::~MsInfoParser()
{
	delete m_pStorage;
}

void MsInfoParser::parseFile(const QString& fileName)
{
	fireParsingStart();

	m_pStorage->reset();

	QFile msInfoFile(fileName);

	if (!msInfoFile.open(QIODevice::ReadOnly))
	{
		qDebug() << "Unable to open MS Info file";
		fireParsingComplete();
		return;
	}

	QDomDocument doc;
	if (!doc.setContent(&msInfoFile))
	{
		qDebug() << "Unable to set content";
		msInfoFile.close();
		fireParsingComplete();
		return;
	}

	msInfoFile.close();

	QDomElement rootElement = doc.documentElement();

	MsInfoCategory* rootCategory = new MsInfoCategory();
	rootCategory->setCategoryName("Ms information");

	parseCategory(rootElement, rootCategory);

	m_pStorage->setRootCategory(rootCategory);

	fireParsingComplete();
}

void MsInfoParser::setListener(IMsInfoParserListener* pListener)
{
	m_pListener = pListener;
}

QList<QDomElement> MsInfoParser::allElementsByTagName(const QDomElement& element, const QString& tagName)
{
	QList<QDomElement> result;

	QDomElement iter = element.firstChildElement().nextSiblingElement(tagName);
	while (!iter.isNull())
	{
		result.append(iter);
		iter = iter.nextSiblingElement(tagName);
	}

	return result;
}

void MsInfoParser::parseCategory(const QDomElement& element, MsInfoCategory* pParentCategory)
{
	QList<QDomElement> categories = allElementsByTagName(element, "Category");
	QList<QDomElement>::iterator iter = categories.begin();
	for (; iter != categories.end(); iter++)
	{
		QDomElement item = *iter;
		MsInfoCategory* pCategory = new MsInfoCategory;
		pCategory->setCategoryName(item.attribute("name"));

		pParentCategory->addCategory(pCategory);
		parseData(item, pCategory);

		if (item.hasChildNodes())
		{
			parseCategory(item, pCategory);
		}
	}
}

void MsInfoParser::parseData(const QDomElement& element, MsInfoCategory* pCategory)
{
	QList<QDomElement> categories = allElementsByTagName(element, "Data");
	QList<QDomElement>::iterator iter = categories.begin();
	bool fillHeader = true;

	for (; iter != categories.end(); iter++)
	{
		QDomElement item = *iter;
		QDomElement dataItem = item.firstChildElement();

		MsInfoDetail* pDetails = new MsInfoDetail();

		while (!dataItem.isNull())
		{
			if (fillHeader)
			{
				pCategory->addHeader(dataItem.tagName());
			}

			QDomNode data = dataItem.firstChild();
			if (data.isCDATASection())
			{
				QDomCDATASection cDataSection = data.toCDATASection();
				QString strData = cDataSection.data();
				pDetails->addValue(strData);
			}

			dataItem = dataItem.nextSiblingElement();
		}

		pCategory->addDetails(pDetails);

		fillHeader = false;
	}
}

void MsInfoParser::fireParsingStart()
{
	if (m_pListener != NULL)
	{
		m_pListener->onParsingStart();
	}
}

void MsInfoParser::fireParsingComplete()
{
	if (m_pListener != NULL)
	{
		m_pListener->onParsingComplete();
	}
}

