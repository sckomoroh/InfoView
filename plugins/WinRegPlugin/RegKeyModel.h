#ifndef KEYTREEMODEL_H
#define KEYTREEMODEL_H

#include <QAbstractItemModel>

#include "RegKeyData.h"

class RegKeyModel : public QAbstractItemModel
{
	Q_OBJECT
private:
	const RegKeyData* m_pRootKey;

public:
	RegKeyModel(QObject *parent);
	~RegKeyModel();

	void setModelData(const RegKeyData* pRootKey);
	RegKeyData* rawData(const QModelIndex & index);

	void reset();

private:
	// Implementing QAbstractItemModel
	virtual QModelIndex	index(int row, int column, const QModelIndex & parent = QModelIndex()) const;
	virtual int			columnCount(const QModelIndex & parent = QModelIndex()) const;
	virtual QVariant	data(const QModelIndex & index, int role = Qt::DisplayRole) const;
	virtual QModelIndex	parent(const QModelIndex & index) const;
	virtual int			rowCount(const QModelIndex & parent = QModelIndex()) const;
	virtual QVariant	headerData(int section, Qt::Orientation orientation, int role = Qt::DisplayRole) const;
};

#endif // KEYTREEMODEL_H
