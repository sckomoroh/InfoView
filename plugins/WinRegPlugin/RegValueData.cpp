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
	case RegValueDataType::RegBinary:
		return "Binary";
	case RegValueDataType::RegDWord:
		return "DWord";
	case RegValueDataType::RegString:
		return "String";
	}

	return "Unknown";
}
