#pragma once

#include <QString>
#include <QList>

#include "msinfodetail.h"

class MsInfoCategory
{
private:
	QString					m_categoryName;
	QList<MsInfoDetail*>	m_details;
	QList<MsInfoCategory*>	m_childCategories;
	MsInfoCategory*			m_parent;
	QList<QString>			m_headers;


public:
	MsInfoCategory();
	~MsInfoCategory();

	void addCategory(MsInfoCategory* category);
	void addDetails(MsInfoDetail* detail);

	inline const QList<MsInfoCategory*>& categories() const
	{
		return m_childCategories;
	}

	inline const QList<MsInfoDetail*>& details() const
	{
		return m_details;
	}

	inline const QString& categoryName() const
	{
		return m_categoryName;
	}

	inline const MsInfoCategory* parent() const
	{
		return m_parent;
	}

	inline const QList<QString>& headers() const
	{
		return m_headers;
	}

	void	setCategoryName(const QString& categoryName);

	void	setParent(MsInfoCategory* pParent);
	int		row() const;

	void	addHeader(const QString& header);
};

