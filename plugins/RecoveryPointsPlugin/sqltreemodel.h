#ifndef SQLTREEMODEL_H
#define SQLTREEMODEL_H

#include <QAbstractItemModel>
#include <QList>
#include <QImage>

#include "SqlBaseModelItem.h"
#include "SqlDatabaseModelItem.h"
#include "SqlInstance.h"

class SqlTreeModel : public QAbstractItemModel
{
	Q_OBJECT
private:
	SqlBaseModelItem* m_pRootItem;

private: 
	static QImage m_redBall;
	static QImage m_yellowBall;
	static QImage m_grayBall;
	static QImage m_greenBall;

public:
	SqlTreeModel(QObject *parent);
	~SqlTreeModel();

	void reset();

	QVariant data(const QModelIndex &index, int role) const;
	QVariant headerData(int section, Qt::Orientation orientation, int role = Qt::DisplayRole) const;
	QModelIndex index(int row, int column, const QModelIndex &parent = QModelIndex()) const;
	QModelIndex parent(const QModelIndex &index) const;
	int rowCount(const QModelIndex &parent = QModelIndex()) const;
	int columnCount(const QModelIndex &parent = QModelIndex()) const;

	void buildModel(QList<SqlInstance*> sqlInstances);

private:
	QVariant baseModelItemData(SqlBaseModelItem* pSqlBaseModelItem, int role) const;
	QVariant databaseModelItemData(SqlDatabaseModelItem* pSqlDatabaseModelItem, int role) const;
};

#endif // SQLTREEMODEL_H
