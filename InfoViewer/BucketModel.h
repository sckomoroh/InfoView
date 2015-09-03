#ifndef RESOURCEMODEL_H
#define RESOURCEMODEL_H

#include <QObject>
#include <QAbstractItemModel>

#include "IAmazon.h"

class BucketModel : public QAbstractItemModel
{
	Q_OBJECT

private:
	QList<AmazonObject> m_data;

public:
	BucketModel(QObject *parent);
	~BucketModel();

	void setModelData(const QList<AmazonObject>& objectList);

	AmazonObject* rawData(const QModelIndex& index);

	void resetModel();

private:
	virtual QModelIndex	index(int row, int column, const QModelIndex& parent = QModelIndex()) const;
	virtual QModelIndex	parent(const QModelIndex& index) const;
	virtual int         rowCount(const QModelIndex& parent = QModelIndex()) const;
	virtual int         columnCount(const QModelIndex& parent = QModelIndex()) const;
	virtual QVariant    data(const QModelIndex& index, int role = Qt::DisplayRole) const;
	virtual QVariant	headerData(int section, Qt::Orientation orientation, int role = Qt::DisplayRole) const;
};

#endif // RESOURCEMODEL_H
