#ifndef VALUESTREEMODEL_H
#define VALUESTREEMODEL_H

#include <QAbstractItemModel>

#include "RegValueData.h"

class RegValueModel : public QAbstractItemModel
{
	Q_OBJECT
private:
	QList<RegValueData*> m_values;

public:
	RegValueModel(QObject *parent);
	~RegValueModel();

	void setModelData(const QList<RegValueData*>& content);

	QString rawData(const QModelIndex& index);

	void reset();

private:
	virtual QModelIndex	index(int row, int column, const QModelIndex & parent = QModelIndex()) const;
	virtual int			columnCount(const QModelIndex & parent = QModelIndex()) const;
	virtual QVariant	data(const QModelIndex & index, int role = Qt::DisplayRole) const;
	virtual QModelIndex	parent(const QModelIndex & index) const;
	virtual int			rowCount(const QModelIndex & parent = QModelIndex()) const;
	virtual QVariant	headerData(int section, Qt::Orientation orientation, int role = Qt::DisplayRole) const;

};

#endif // VALUESTREEMODEL_H
