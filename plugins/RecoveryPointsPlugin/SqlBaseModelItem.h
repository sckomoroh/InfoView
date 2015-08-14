#pragma once

#include <QList>
#include <QString>

class SqlBaseModelItem
{
private:
	QString m_content;
	SqlBaseModelItem* m_pParent;
	QList<SqlBaseModelItem*> m_children;

public:
	SqlBaseModelItem(const QString& content, SqlBaseModelItem* pParent);
	virtual ~SqlBaseModelItem();

	QString& content();

	SqlBaseModelItem* child(int index);
	SqlBaseModelItem* parent();
	int row();
	int childCount();
};

