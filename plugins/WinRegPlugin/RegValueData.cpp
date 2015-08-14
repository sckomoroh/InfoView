#include "RegValueData.h"


RegValueData::RegValueData()
{
}

RegValueData::~RegValueData()
{
}

void RegValueData::addValueLine(const QString& valueLine)
{
	m_value.append(QString("%1\r\n").arg(valueLine));
}

QString RegValueData::valueTypeToString()
{
	switch (m_valueType)
	{
	case RegValueData::RegBinary:
		return "Binary";
	case RegValueData::RegDWord:
		return "DWord";
	case RegValueData::RegString:
		return "String";
	}

	return "Unknown";
}
