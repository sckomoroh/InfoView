#include "BsonElement.h"
#include "BsonDocument.h"

BsonElement::BsonElement()
: m_sName(NULL)
{
	m_value.m_binaryData = NULL;
	m_value.m_boolData = false;
	m_value.m_doubleData = 0;
	m_value.m_int32Data = 0;
	m_value.m_int64Data = 0;
	m_value.m_utfStrData = NULL;
}

BsonElement::~BsonElement(void)
{
	delete[] m_sName;

	if (m_valueType == BsonType::Array || m_valueType == BsonType::BinaryData)
	{
		delete m_value.m_binaryData;
		return;
	}

	if (m_valueType == BsonType::Utf8String)
	{
		delete m_value.m_utfStrData;
	}
}

bool BsonElement::isArray()
{
	return m_valueType == BsonType::Array;
}

char* BsonElement::name()
{
	return m_sName;
}

BsonDocument* BsonElement::asArrayDocument()
{
	return (BsonDocument*)m_value.m_binaryData;
}

std::vector<BsonElement*> BsonElement::asArray()
{
	std::vector<BsonElement*> result;

	BsonDocument* pDocument = (BsonDocument*)m_value.m_binaryData;
	std::list<BsonElement*>::iterator iter = pDocument->m_elements.begin();
	for (; iter != pDocument->m_elements.end(); iter++)
	{
		result.push_back(*iter);
	}

	return result;
}

UInt BsonElement::parseElement(UChar* sDocBuffer)
{
	parseElementName(sDocBuffer);
	UInt nNameLenght = strlen(m_sName);
	UInt nValueSize = parseValue(sDocBuffer);

	if (m_valueType == BsonType::Array)
	{
		UInt valueOffset = 1 /*Type*/ + nNameLenght + 1/*Zero-end string*/;
		BsonDocument* pTempDocument = new BsonDocument(sDocBuffer + valueOffset, nValueSize - 4 - 4);
		m_value.m_binaryData = pTempDocument;
	}

	return nValueSize + 2 + nNameLenght;
}

void BsonElement::parseElementName(UChar* sDocBuffer)
{
	int nNameSize = strlen((char*)(sDocBuffer + 1));

	m_sName = new char[nNameSize + 1];
	memset(m_sName, 0, nNameSize + 1);

	strcpy_s(m_sName, nNameSize + 1, (char*)(sDocBuffer + 1));
}

BsonType BsonElement::valueType()
{
	return m_valueType;
}

BsonBinarySubtype BsonElement::valueSubType()
{
	return m_valueSubType;
}

char* BsonElement::asUtfString()
{
	return m_value.m_utfStrData;
}

double BsonElement::asDouble()
{
	return m_value.m_doubleData;
}

void* BsonElement::asBinary()
{
	return m_value.m_binaryData;
}

bool BsonElement::asBool()
{
	return m_value.m_boolData;
}

Int32 BsonElement::asInt32()
{
	return m_value.m_int32Data;
}

Int64 BsonElement::asInt64()
{
	return m_value.m_int64Data;
}

bool BsonElement::isNull()
{
	return m_valueType == BsonType::NullValue;
}

UInt BsonElement::parseValue(UChar* sBuffer)
{
	m_valueType = (BsonType)(*sBuffer);

	sBuffer += 1/*Type byte*/ + strlen(m_sName) + 1/*Zero byte*/;

	switch (m_valueType)
	{
	case BinaryData:
		return parseBinaryData(sBuffer);
		break;
	case UtcDateTime:
		return parseUtcDateTimeData(sBuffer);
		break;
	case Utf8String:
		return parseUtf8StringData(sBuffer);
		break;
	case Bool:
		return parseBoolData(sBuffer);
		break;
	case Array:
		return parseArrayData(sBuffer);
		break;
	case NullValue:
		return 0;
		break;
	case Integer32:
		return parseInt32Data(sBuffer);
		break;
	case Integer64:
		return parseInt64Data(sBuffer);
		break;
	}

	return 0;
}

UInt BsonElement::parseInt32Data(UChar* sBuffer)
{
	memcpy(&m_value.m_int32Data, sBuffer, 4);

	return  4;
}

UInt BsonElement::parseInt64Data(UChar* sBuffer)
{
	memcpy(&m_value.m_int32Data, sBuffer, 8);

	return 8;
}

UInt BsonElement::parseArrayData(UChar* sBuffer)
{
	// Get array document size
	UInt nDocumentSize = 0;
	memcpy(&nDocumentSize, sBuffer, 4);

	return  nDocumentSize;
}

UInt BsonElement::parseBoolData(UChar* sBuffer)
{
	m_value.m_boolData = *sBuffer;

	return  1;
}

UInt BsonElement::parseNullData(UChar* sBuffer)
{
	// No any need to implement
	return 0;
}

UInt BsonElement::parseBinaryData(UChar* sBuffer)
{
	__int32 nByteBufferSize = 0;
	memcpy(&nByteBufferSize, sBuffer, 4);
	sBuffer += 4;

	m_valueSubType = (BsonBinarySubtype)(*sBuffer);
	sBuffer += 1;

	m_value.m_binaryData = new char[nByteBufferSize];

	memcpy(m_value.m_binaryData, sBuffer, nByteBufferSize);

	return
		4 /*Size of buffer*/
		+ 1/*Subtype*/
		+ nByteBufferSize;
}

UInt BsonElement::parseUtcDateTimeData(UChar* sBuffer)
{
	memcpy(&(m_value.m_int64Data), sBuffer, 8);

	return 8;
}

UInt BsonElement::parseUtf8StringData(UChar* sBuffer)
{
	UInt nStrLen = 0;
	memcpy(&nStrLen, sBuffer, 4);
	sBuffer += 4;

	m_value.m_utfStrData = new char[nStrLen];
	strcpy_s(m_value.m_utfStrData, nStrLen, (char*)sBuffer);

	return 4 /*string size*/ + nStrLen;
}
