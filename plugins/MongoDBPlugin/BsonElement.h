#ifndef BSON_ELEMENT
#define BSON_ELEMENT

#include <list>
#include <vector>

typedef unsigned int	UInt;
typedef unsigned char	UChar;
typedef __int32			Int32;
typedef __int64			Int64;

enum BsonType
{
	Double = 0x01,
	Utf8String = 0x02,
	EmbeddedDocument = 0x03,
	Array = 0x04,
	BinaryData = 0x05,
	Undefined = 0x06,
	ObjectId = 0x07,
	Bool = 0x08,
	UtcDateTime = 0x09,
	NullValue = 0x0A,
	RegExp = 0x0B,
	DBPointer = 0x0C,
	Depricated = 0x0E,
	JavaScript = 0x0F,
	Integer32 = 0x10,
	Timestamp = 0x11,
	Integer64 = 0x12,
	MinKey = 0xFF,
	MaxKey = 0x7F,
};

enum BsonBinarySubtype
{
	Generic = 0x00,
	Function = 0x01,
	BinaryOld = 0x02,
	UuidOld = 0x03,
	Uuid = 0x04,
	MD5 = 0x05,
	UserDefined = 0x80,
	None
};

union BsonData
{
	char*	m_utfStrData;
	double	m_doubleData;
	void*	m_binaryData;
	bool	m_boolData;
	Int64	m_int64Data;
	Int32	m_int32Data;
};

class BsonDocument;

class BsonElement
{
private:
	char*				m_sName;
	BsonType			m_valueType;
	BsonBinarySubtype	m_valueSubType;
	BsonData			m_value;


public:
	~BsonElement(void);

	bool						isArray();
	char*						name();
	BsonDocument*				asArrayDocument();
	std::vector<BsonElement*>	asArray();

	BsonType					valueType();
	BsonBinarySubtype			valueSubType();

	char*						asUtfString();
	double						asDouble();
	void*						asBinary();
	bool						asBool();
	Int32						asInt32();
	Int64						asInt64();
	bool						isNull();

private:
	BsonElement();

	UInt	parseElement(UChar* sDocBuffer);
	void	parseElementName(UChar* sDocBuffer);

	UInt	parseValue(UChar* sBuffer);
	UInt	parseInt32Data(UChar* sBuffer);
	UInt	parseInt64Data(UChar* sBuffer);
	UInt	parseArrayData(UChar* sBuffer);
	UInt	parseBoolData(UChar* sBuffer);
	UInt	parseNullData(UChar* sBuffer);
	UInt	parseBinaryData(UChar* sBuffer);
	UInt	parseUtcDateTimeData(UChar* sBuffer);
	UInt	parseUtf8StringData(UChar* sBuffer);

	friend class BsonDocument;
};

#endif 
