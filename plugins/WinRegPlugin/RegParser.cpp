#include "RegParser.h"


#include <QFile>
#include <QTextStream>
#include <QDebug>
#include <QDir>


RegParser::RegParser()
{
	m_pStorage = new RegStorage;
}

RegParser::~RegParser()
{
	delete m_pStorage;
}

void RegParser::setListener(IRegParserListener* pListener)
{
	m_pListener = pListener;
}

void RegParser::parseFolder(const QString& folderName)
{
	fireParseStart();

	m_pStorage->reset();

	QDir folder(folderName);

	RegKeyData* rootKey = new RegKeyData;
	rootKey->setFullName("ROOT");

	QStringList files = folder.entryList(QDir::Files);

	for each (QString fileName in files)
	{
		QString fullFileName = folderName + "\\" + fileName;
		RegKeyData* key = parseFile(fullFileName);
		rootKey->addKey(key);

		key->setParent(rootKey);
	}

	m_pStorage->setRootKey(rootKey);

	fireParseComplete();
}

RegKeyData* RegParser::parseFile(QString fileName)
{
	m_bNeedNextLine = false;
	RegKeyData* pRegistryKey = NULL;
	RegKeyData* pResult = NULL;
	RegValueData* pRegistryValue = NULL;

	QFile inputFile(fileName);
	if (inputFile.open(QIODevice::ReadOnly))
	{
		QTextStream in(&inputFile);
		for (int i = 0; i < 2; i++)
		{
			in.readLine();
		}

		while (!in.atEnd())
		{
			QString line = in.readLine();

			if ((line.isNull() || line.isEmpty()) && !m_bNeedNextLine)
			{
				continue;
			}

			if (m_bNeedNextLine && pRegistryValue != NULL)
			{
				addLineToValue(line, pRegistryValue);

				continue;
			}

			if (line.at(0) == '[')
			{
				pRegistryKey = parseRegistryKey(line, pRegistryKey);

				if (pResult == NULL)
				{
					pResult = pRegistryKey;
				}
			}
			else
			{
				if (pRegistryKey != NULL)
				{
					if (line.at(0) == '@')
					{
						// This is default value
						pRegistryValue = parseDefaultValue(line);
						pRegistryKey->addValue(pRegistryValue);
					}
					else
					{
						// This is named value
						pRegistryValue = parseNamedValue(line);
						pRegistryKey->addValue(pRegistryValue);
					}
				}
			}
		}

		inputFile.close();
	}

	return pResult;
}

void RegParser::addLineToValue(QString line, RegValueData* pValue)
{
	pValue->addValueLine(line);

	if (pValue->m_valueType == RegValueData::RegString)
	{
		m_bNeedNextLine = !line.endsWith("\"");
	}
	else if (pValue->m_valueType == RegValueData::RegBinary)
	{
		m_bNeedNextLine = line.endsWith("\\");
	}
}

RegKeyData* RegParser::parseRegistryKey(QString line, RegKeyData* pParent)
{
	RegKeyData* result = new RegKeyData;

	QString fullName = line.mid(1, line.length() - 2);
	result->setFullName(fullName);

	if (pParent != NULL)
	{
		QString parentName = parentFullName(result->fullName());

		QString currentParentName = pParent->fullName();
		while (pParent != NULL && parentName != currentParentName)
		{
			pParent = (RegKeyData*)pParent->parent();
			currentParentName = pParent->fullName();
		}

		if (pParent != NULL)
		{
			result->setParent(pParent);
			pParent->addKey(result);
		}
	}

	return result;
}

RegValueData* RegParser::parseDefaultValue(QString line)
{
	RegValueData* result = new RegValueData;

	result->m_valueName = "(Default)";
	QString rawLine = line.mid(2);
	parseValue(rawLine, result);

	return result;
}

RegValueData* RegParser::parseNamedValue(QString line)
{
	RegValueData* result = new RegValueData;

	int index = line.indexOf('=');

	result->m_valueName = line.mid(1, index - 2);

	QString rawLine = line.mid(index + 1);
	parseValue(rawLine, result);

	return result;
}

RegValueData::RegValueDataType RegParser::parseValueType(QString line, RegValueData* pValue)
{
	if (line.at(0) == '\"')
	{
		pValue->m_valueType = RegValueData::RegString;
		return RegValueData::RegString;
	}

	if (line.mid(0, 3) == "hex")
	{
		pValue->m_valueType = RegValueData::RegBinary;
		return RegValueData::RegBinary;
	}

	if (line.mid(0, 5) == "dword")
	{
		pValue->m_valueType = RegValueData::RegDWord;
		return RegValueData::RegDWord;
	}

	return RegValueData::RegUnknown;
}

void RegParser::parseValue(QString line, RegValueData* pValue)
{
	switch (parseValueType(line, pValue))
	{
	case RegValueData::RegBinary:
		parseBinHexValue(line, pValue);
		break;

	case RegValueData::RegDWord:
		parseDWordValue(line, pValue);
		break;

	case RegValueData::RegString:
		parseStringValue(line, pValue);
		break;
	}
}

void RegParser::parseBinHexValue(QString line, RegValueData* pValue)
{
	pValue->m_value = line.mid(6, line.length() - 3);

	m_bNeedNextLine = line.endsWith('\\');
}

void RegParser::parseDWordValue(QString line, RegValueData* pValue)
{
	pValue->m_value = line.mid(6, line.length() - 6);
}

void RegParser::parseStringValue(QString line, RegValueData* pValue)
{
	if (line.endsWith('\"'))
	{
		pValue->m_value = line.mid(1, line.length() - 2);
	}
	else
	{
		pValue->m_value = line.mid(1, line.length());
		m_bNeedNextLine = true;
	}
}

QString RegParser::parentFullName(QString name)
{
	int index = name.lastIndexOf('\\');
	QString parentName = name.mid(0, index);

	return parentName;
}

void RegParser::fireParseStart()
{
	if (m_pListener != NULL)
	{
		m_pListener->onParsingStart();
	}
}

void RegParser::fireParseComplete()
{
	if (m_pListener != NULL)
	{
		m_pListener->onParsingComplete();
	}
}
