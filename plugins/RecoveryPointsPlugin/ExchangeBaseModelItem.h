#pragma once

#include <QString>
#include <QList>

class ExchangeBaseModelItem
{
private:
	QString m_content;
	ExchangeBaseModelItem* m_pParent;
	QList<ExchangeBaseModelItem*> m_children;

public:
	ExchangeBaseModelItem(const QString& content, ExchangeBaseModelItem* pParent);
	virtual ~ExchangeBaseModelItem();

	QString& content();

	ExchangeBaseModelItem* child(int index);
	ExchangeBaseModelItem* parent();
	int row();
	int childCount();
};

