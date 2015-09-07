#pragma once

#include <QString>
#include <QDomElement>
#include <QList>

#include "msinfocategory.h"
#include "MsInfoStorage.h"
#include "IMsInfoParserListener.h"

#include "ILogClient.h"

class MsInfoParser
{
private:
	MsInfoStorage* m_pStorage;
	IMsInfoParserListener* m_pListener;
	ILogClient* m_logClient;

public:
	MsInfoParser();
	~MsInfoParser();

	void parseFile(const QString& fileName);

	inline const MsInfoStorage* storage() const
	{
		return m_pStorage;
	}

	void setListener(IMsInfoParserListener* pListener);

private:
	QList<QDomElement> allElementsByTagName(const QDomElement& element, const QString& tagName);
	void parseCategory(const QDomElement& element, MsInfoCategory* pParentCategory);
	void parseData(const QDomElement& element, MsInfoCategory* pCategory);

	void fireParsingStart();
	void fireParsingComplete();
};

