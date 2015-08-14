#pragma once

#include <QString>

#include "RegKeyData.h"
#include "RegValueData.h"
#include "RegStorage.h"
#include "IRegParserListener.h"

class RegParser
{
private:
	bool m_bNeedNextLine;
	RegStorage* m_pStorage;
	IRegParserListener* m_pListener;

public:
	RegParser();
	~RegParser();

	inline const RegStorage* storage() const
	{
		return m_pStorage;
	}

	void parseFolder(const QString& folderName);
	void setListener(IRegParserListener* pListener);

private:
	RegKeyData*			parseFile(QString fileName);
	
	RegValueData*		parseDefaultValue(QString line);
	RegValueData*		parseNamedValue(QString line);

	void				addLineToValue(QString line, RegValueData* pValue);

	RegKeyData*			parseRegistryKey(QString line, RegKeyData* pParent);

	RegValueData::RegValueDataType	parseValueType(QString line, RegValueData* pValue);

	void				parseValue(QString line, RegValueData* pValue);
	void				parseStringValue(QString line, RegValueData* pValue);
	void				parseDWordValue(QString line, RegValueData* pValue);
	void				parseBinHexValue(QString line, RegValueData* pValue);

	QString				parentName(QString name);
	RegKeyData*			findParent(RegKeyData* key);

	QString				parentFullName(QString name);

	void				fireParseStart();
	void				fireParseComplete();
};

