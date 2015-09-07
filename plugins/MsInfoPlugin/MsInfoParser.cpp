#include "MsInfoParser.h"

#include <QFile>
#include <QDomDocument>
#include <QDebug>

#define ROOT_CATEGORY_NAME		"Ms information"
#define CATEGORY_ELEMENT_NAME	"Category"
#define DATA_ELEMENT_NAME		"Data"

MsInfoParser::MsInfoParser()
	: m_pListener(NULL)
{
	m_pStorage = new MsInfoStorage;
	m_logClient = getLogClientInstance();
}

MsInfoParser::~MsInfoParser()
{
	delete m_pStorage;
}

void MsInfoParser::parseFile(const QString& fileName)
{
	m_logClient->Info("<MS-INFO> Start parse file %s", fileName.toStdString().c_str());

	fireParsingStart();

	m_pStorage->reset();

	QFile msInfoFile(fileName);

	if (!msInfoFile.open(QIODevice::ReadOnly))
	{
		m_logClient->Error("<MS-INFO> Unable to open MS Info file");
		fireParsingComplete();
		return;
	}

	QDomDocument doc;
	if (!doc.setContent(&msInfoFile))
	{
		m_logClient->Error("<MS-INFO> Unable to parse XML content");
		msInfoFile.close();
		fireParsingComplete();
		return;
	}

	msInfoFile.close();

	QDomElement rootElement = doc.documentElement();

	MsInfoCategory* rootCategory = new MsInfoCategory();
	rootCategory->setCategoryName(ROOT_CATEGORY_NAME);

	parseCategory(rootElement, rootCategory);

	m_pStorage->setRootCategory(rootCategory);

	m_logClient->Debug("<MS-INFO> Parsing completed");

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
	QList<QDomElement> categories = allElementsByTagName(element, CATEGORY_ELEMENT_NAME);
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
	QList<QDomElement> categories = allElementsByTagName(element, DATA_ELEMENT_NAME);
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

