#include "SqlLogFile.h"


SqlLogFile::SqlLogFile()
{
}


SqlLogFile::~SqlLogFile()
{
}

QString SqlLogFile::fileName()
{
	return m_fileName;
}

qlonglong SqlLogFile::size()
{
	return m_iSize;
}
