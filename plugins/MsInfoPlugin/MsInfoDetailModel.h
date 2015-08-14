#ifndef DETAILSTABLEMODEL_H
#define DETAILSTABLEMODEL_H

#include <QAbstractItemModel>

#include "msinfodetail.h"
#include "msinfocategory.h"

class MsInfoDetailModel : public QAbstractItemModel
{
	Q_OBJECT
private:
	QList<QString> m_headers;
	QList<MsInfoDetail*> m_details;

public:
	MsInfoDetailModel(QObject *parent);
	~MsInfoDetailModel();

	void setCategory(MsInfoCategory* category);
	void reset();

	// Implementing QAbstractItemModel
	virtual QModelIndex	index(int row, int column, const QModelIndex & parent = QModelIndex()) const;
	virtual int			columnCount(const QModelIndex & parent = QModelIndex()) const;
	virtual QVariant	data(const QModelIndex & index, int role = Qt::DisplayRole) const;
	virtual QModelIndex	parent(const QModelIndex & index) const;
	virtual int			rowCount(const QModelIndex & parent = QModelIndex()) const;
	virtual QVariant	headerData(int section, Qt::Orientation orientation, int role = Qt::DisplayRole) const;
	virtual void 		sort(int column, Qt::SortOrder order = Qt::AscendingOrder);
};

#endif // DETAILSTABLEMODEL_H
