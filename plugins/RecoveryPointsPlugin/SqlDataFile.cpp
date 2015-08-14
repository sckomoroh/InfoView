#include "SqlDataFile.h"


SqlDataFile::SqlDataFile()
{
}


SqlDataFile::~SqlDataFile()
{
}

QString SqlDataFile::fileName()
{
	return m_fileName;
}

qlonglong SqlDataFile::size()
{
	return m_iSize;
}
