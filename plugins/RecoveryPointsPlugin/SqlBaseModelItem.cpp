#include "SqlBaseModelItem.h"


SqlBaseModelItem::SqlBaseModelItem(const QString& content, SqlBaseModelItem* pParent)
	: m_content(content)
	, m_pParent(pParent)
{
	if (pParent != NULL)
	{
		pParent->m_children.append(this);
	}
}


SqlBaseModelItem::~SqlBaseModelItem()
{
	QList<SqlBaseModelItem*>::iterator iter = m_children.begin();
	for (; iter != m_children.end(); iter++)
	{
		SqlBaseModelItem* pItem = *iter;
		delete pItem;
	}
}

QString& SqlBaseModelItem::content()
{
	return m_content;
}

SqlBaseModelItem* SqlBaseModelItem::child(int index)
{
	return m_children.at(index);
}

SqlBaseModelItem* SqlBaseModelItem::parent()
{
	return m_pParent;
}

int SqlBaseModelItem::row()
{
	return m_pParent->m_children.indexOf(this);
}

int SqlBaseModelItem::childCount()
{
	return m_children.count();
}
