#ifndef BSON_DOCUMENT
#define BSON_DOCUMENT

#include <list>

#include "BsonElement.h"

class BsonDocumentSet;
class BsonElement;

class BsonDocument
{
private:
	UInt					m_nDocSize;
	std::list<BsonElement*>	m_elements;

public:
	~BsonDocument(void);

	std::list<BsonElement*>&	elements();
	BsonElement*				elementByName(char* sElementName);
	bool						hasElement(char* sElementName);
	UInt						documentSize();

private:
	BsonDocument(UChar* sDocBuffer, int nBufferSize);

	void parseDocument(UChar* sDocBuffer, int nBufferSize);
	void setDocumentSize(UInt nDocumentSize);

	friend class BsonDocumentSet;
	friend class BsonElement;
};

#endif
