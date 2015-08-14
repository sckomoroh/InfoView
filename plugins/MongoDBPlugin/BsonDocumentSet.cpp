#include "BsonDocumentSet.h"


BsonDocumentSet::BsonDocumentSet(void)
{
}

BsonDocumentSet::~BsonDocumentSet(void)
{
	std::list<BsonDocument*>::iterator iter = m_documentList.begin();
	for (; iter != m_documentList.end(); iter++)
	{
		BsonDocument* pData = *iter;
		delete pData;
	}
}

std::list<BsonDocument*>& BsonDocumentSet::documents()
{
	return m_documentList;
}

BsonDocument* BsonDocumentSet::parseDocument(unsigned char* sBuffer, unsigned int nBufferSize)
{
	BsonDocument* pDocument = new BsonDocument(sBuffer, nBufferSize);
	return pDocument;
}

unsigned int BsonDocumentSet::readDocumentSize(unsigned char* nBuffer)
{
	unsigned int nDocSize = 0;
	memcpy(&nDocSize, nBuffer, 4);
	return nDocSize;
}

BsonDocumentSet* BsonDocumentSetFactory::createFromDump(const char* sFileName)
{
	UInt nBufferOffset = 0;
	fpos_t nFileSize = 0;
	errno_t nError = 0;
	FILE* pFile = NULL;
	BsonDocumentSet* pDocumentSet = NULL;

	if (nError = fopen_s(&pFile, sFileName, "rb"))
	{
		printf("ERROR: Unable to open file due to error code: %d\r\n", nError);
		return NULL;
	}

	// Get the file size
	fseek(pFile, 0, SEEK_END);
	fgetpos(pFile, &nFileSize);
	fseek(pFile, 0, SEEK_SET);

	// Prepare the content buffer and read it from the file
	unsigned char* sFileContent = new unsigned char[nFileSize + 1];
	memset(sFileContent, 0, nFileSize + 1);

	fread(sFileContent, nFileSize, 1, pFile);

	// Start the parsing
	pDocumentSet = new BsonDocumentSet();

	while (nBufferOffset < nFileSize)
	{
		unsigned int documentSize = BsonDocumentSet::readDocumentSize(sFileContent + nBufferOffset);
		BsonDocument* pDocument = pDocumentSet->parseDocument(sFileContent + nBufferOffset, documentSize);
		pDocumentSet->m_documentList.push_back(pDocument);
		nBufferOffset += documentSize;
	}

	fclose(pFile);

	delete[] sFileContent;

	return pDocumentSet;
}
