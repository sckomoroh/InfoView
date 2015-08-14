#include "BaseModelItem.h"


BaseModelItem::BaseModelItem(BaseModelItem* pParent)
	: m_pParent(pParent)
{
	if (m_pParent != NULL)
	{
		pParent->m_children.append(this);
	}
}

BaseModelItem::~BaseModelItem()
{
	QList<BaseModelItem*>::iterator iter = m_children.begin();
	for (; iter != m_children.end(); iter++)
	{
		BaseModelItem* pItem = *iter;
		delete pItem;
	}
}

QList<BaseModelItem*>& BaseModelItem::children()
{
	return m_children;
}

BaseModelItem* BaseModelItem::child(int index)
{
	return m_children.at(index);
}

BaseModelItem* BaseModelItem::parent()
{
	return m_pParent;
}

int BaseModelItem::row()
{
	return m_pParent->m_children.indexOf(this);
}

int BaseModelItem::childCount()
{
	return m_children.count();
}
