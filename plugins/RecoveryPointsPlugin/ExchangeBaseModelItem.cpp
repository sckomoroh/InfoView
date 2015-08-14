#include "ExchangeBaseModelItem.h"


ExchangeBaseModelItem::ExchangeBaseModelItem(const QString& content, ExchangeBaseModelItem* pParent)
	: m_content(content)
	, m_pParent(pParent)
{
	if (pParent != NULL)
	{
		pParent->m_children.append(this);
	}
}

ExchangeBaseModelItem::~ExchangeBaseModelItem()
{
	QList<ExchangeBaseModelItem*>::iterator iter = m_children.begin();
	for (; iter != m_children.end(); iter++)
	{
		ExchangeBaseModelItem* pItem = *iter;
		delete pItem;
	}
}

QString& ExchangeBaseModelItem::content()
{
	return m_content;
}

ExchangeBaseModelItem* ExchangeBaseModelItem::child(int index)
{
	return m_children.at(index);
}

ExchangeBaseModelItem* ExchangeBaseModelItem::parent()
{
	return m_pParent;
}

int ExchangeBaseModelItem::row()
{
	return m_pParent->m_children.indexOf(this);
}

int ExchangeBaseModelItem::childCount()
{
	return m_children.count();
}
