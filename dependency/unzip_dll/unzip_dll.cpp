// unzip_dll.cpp : Defines the exported functions for the DLL application.
//

#include "stdafx.h"

#include "IZip.h"
#include "unzip.h"

#include <string>

using namespace std;

class UnZip : public IZip
{
public:
	UnZip()
	{

	}

	virtual void	setName(wstring sName)
	{
		m_sName = sName;
	}

	virtual bool	openZip()
	{
		m_hZip = OpenZip(m_sName.c_str(), NULL);
		return m_hZip != 0?true:false;
	}

	virtual int		getItemsCount()
	{
		ZIPENTRY zipEntry;
		if(GetZipItem(m_hZip, -1, &zipEntry) == 0)
			return zipEntry.index;
		return -1;
	}

	virtual bool	unzipItem(int iIndex, wstring sDestName)
	{
		return UnzipItem(m_hZip, iIndex, sDestName.c_str())==0?true:false;
	}

	virtual wstring	getItemName(int iIndex)
	{
		ZIPENTRY zipEntry;
		GetZipItem(m_hZip, iIndex, &zipEntry);

		wstring sResult(zipEntry.name);
		return sResult;
	}

	virtual void	closeZip()
	{
		CloseZip(m_hZip);
	}

private:
	HZIP	m_hZip;
	wstring	m_sName;
};

#define __declspec(dllexport)
IZip* getZipInstance()
{
	return (new UnZip);	
}
