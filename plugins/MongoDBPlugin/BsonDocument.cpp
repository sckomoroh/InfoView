#include "BsonDocument.h"

BsonDocument::~BsonDocument(void)
{
	std::list<BsonElement*>::iterator iter = m_elements.begin();
	for (; iter != m_elements.end(); iter++)
	{
		BsonElement* pData = *iter;
		delete pData;
	}
}

std::list<BsonElement*>& BsonDocument::elements()
{
	return m_elements;
}

BsonElement* BsonDocument::elementByName(char* sElementName)
{
	std::list<BsonElement*>::iterator iter = m_elements.begin();
	for (; iter != m_elements.end(); iter++)
	{
		BsonElement* pElement = *iter;
		if (_strcmpi(pElement->name(), sElementName) == 0)
		{
			return pElement;
		}
	}

	return NULL;
}

bool BsonDocument::hasElement(char* sElementName)
{
	std::list<BsonElement*>::iterator iter = m_elements.begin();
	for (; iter != m_elements.end(); iter++)
	{
		BsonElement* pElement = *iter;
		if (_strcmpi(pElement->name(), sElementName) == 0)
		{
			return true;
		}
	}

	return false;
}

unsigned int BsonDocument::documentSize()
{
	return m_nDocSize;
}

BsonDocument::BsonDocument(unsigned char* sDocBuffer, int nBufferSize)
: m_nDocSize(nBufferSize)
{
	parseDocument(sDocBuffer, nBufferSize);
}

void BsonDocument::parseDocument(unsigned char* sDocBuffer, int nBufferSize)
{
	int nDocumentOffset = 0;

	// 
	sDocBuffer += 4;

	while (nDocumentOffset < m_nDocSize - 4 - 1 && nDocumentOffset < nBufferSize)
	{
		BsonElement* pElement = new BsonElement();

		nDocumentOffset += pElement->parseElement(sDocBuffer + nDocumentOffset);

		m_elements.push_back(pElement);
	}
}
