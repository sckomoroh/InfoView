#include "msinfocategory.h"

MsInfoCategory::MsInfoCategory()
	: m_parent(NULL)
{
}

MsInfoCategory::~MsInfoCategory()
{
	QList<MsInfoCategory*>::iterator categoryIter = m_childCategories.begin();
	for (; categoryIter != m_childCategories.end(); categoryIter++)
	{
		MsInfoCategory* data = *categoryIter;
		delete data;
	}

	QList<MsInfoDetail*>::iterator detailsIter = m_details.begin();
	for (; detailsIter != m_details.end(); detailsIter++)
	{
		MsInfoDetail* data = *detailsIter;
		delete data;
	}
}

void MsInfoCategory::addCategory(MsInfoCategory* category)
{
	m_childCategories.append(category);
	category->m_parent = this;
}

void MsInfoCategory::addDetails(MsInfoDetail* detail)
{
	m_details.append(detail);
}

void MsInfoCategory::setCategoryName(const QString& name)
{
	m_categoryName = name;
}

void MsInfoCategory::setParent(MsInfoCategory* pParent)
{
	m_parent = pParent;
}

int MsInfoCategory::row() const
{
	MsInfoCategory* pParent = (MsInfoCategory*)this;
	return m_parent->m_childCategories.indexOf(pParent);
}

void MsInfoCategory::addHeader(const QString& header)
{
	m_headers.append(header);
}
