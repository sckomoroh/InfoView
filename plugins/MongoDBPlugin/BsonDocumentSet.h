#ifndef BSON_DOCUMENT_SET
#define BSON_DOCUMENT_SET

#include <list>

#include "BsonDocument.h"

class BsonDocumentSetFactory;

class BsonDocumentSet
{
private:
	std::list<BsonDocument*> m_documentList;

public:
	~BsonDocumentSet(void);

	std::list<BsonDocument*>&	documents();

private:
	BsonDocumentSet(void);

	BsonDocument*	parseDocument(UChar* sBuffer, UInt nBufferSize);
	static UInt		readDocumentSize(UChar* sBuffer);

	friend class BsonDocumentSetFactory;
};

class BsonDocumentSetFactory
{
public:
	static BsonDocumentSet* createFromDump(const char* sFileName);
};

#endif
