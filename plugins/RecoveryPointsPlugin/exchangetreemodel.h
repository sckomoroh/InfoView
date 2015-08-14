#ifndef EXCHANGETREEMODEL_H
#define EXCHANGETREEMODEL_H

#include <QAbstractItemModel>
#include <QImage>

#include "RecoveryPointRecord.h"
#include "ExchangeBaseModelItem.h"
#include "ExchangeDatabaseModelItem.h"

class ExchangeTreeModel : public QAbstractItemModel
{
	Q_OBJECT
private:
	ExchangeBaseModelItem* m_pRootItem;

private: 
	static QImage m_redBall;
	static QImage m_yellowBall;
	static QImage m_grayBall;
	static QImage m_greenBall;

public:
	ExchangeTreeModel(QObject *parent);
	~ExchangeTreeModel();

	void reset();

	QVariant data(const QModelIndex &index, int role) const;
	QVariant headerData(int section, Qt::Orientation orientation, int role = Qt::DisplayRole) const;
	QModelIndex index(int row, int column, const QModelIndex &parent = QModelIndex()) const;
	QModelIndex parent(const QModelIndex &index) const;
	int rowCount(const QModelIndex &parent = QModelIndex()) const;
	int columnCount(const QModelIndex &parent = QModelIndex()) const;

	void buildModel(Exchange* pExchange);

private:
	QVariant baseItemData(ExchangeBaseModelItem* pItemData, int role) const;
	QVariant databaseItemData(ExchangeDatabaseModelItem* pItemData, int role) const;
};

#endif // EXCHANGETREEMODEL_H
