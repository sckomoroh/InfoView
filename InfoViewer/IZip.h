#ifndef IZIP_H
#define IZIP_H

#include <string>

using namespace std;

class IZip
{
public:
	virtual void	setName(wstring sName) = 0;
	virtual bool	openZip() = 0;
	virtual int		getItemsCount() = 0;
	virtual bool	unzipItem(int iIndex, wstring sDestName) = 0;
	virtual wstring	getItemName(int iIndex) = 0;
	virtual void	closeZip() = 0;
};

__declspec(dllimport) IZip* getZipInstance();

#endif // IZIP_H
