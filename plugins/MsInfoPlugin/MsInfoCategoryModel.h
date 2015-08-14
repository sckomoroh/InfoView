#ifndef CATEGORIESTREEMODEL_H
#define CATEGORIESTREEMODEL_H

#include <QAbstractItemModel>

#include "msinfocategory.h"

class MsInfoCategoryModel : public QAbstractItemModel
{
	Q_OBJECT

private:
	const MsInfoCategory* rootCategory;

public:
	MsInfoCategoryModel(QObject *parent);
	~MsInfoCategoryModel();

	void setRootCategory(const MsInfoCategory* rootCategory);
	void reset();

	// Implementing QAbstractItemModel
	virtual QModelIndex	index(int row, int column, const QModelIndex & parent = QModelIndex()) const;
	virtual int			columnCount(const QModelIndex & parent = QModelIndex()) const;
	virtual QVariant	data(const QModelIndex & index, int role = Qt::DisplayRole) const;
	virtual QModelIndex	parent(const QModelIndex & index) const;
	virtual int			rowCount(const QModelIndex & parent = QModelIndex()) const;
	virtual QVariant	headerData(int section, Qt::Orientation orientation, int role = Qt::DisplayRole) const;

	MsInfoCategory*		rawData(const QModelIndex& index) const;
};

#endif // CATEGORIESTREEMODEL_H
