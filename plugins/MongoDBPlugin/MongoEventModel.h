#ifndef EVENTSTREEMODEL_H
#define EVENTSTREEMODEL_H

#include <QAbstractItemModel>
#include <QList>

#include "MongoEventData.h"

class MongoEventModel : public QAbstractItemModel
{
	Q_OBJECT
private:
	QList<MongoEventData*> m_events;

public:
	MongoEventModel(QObject *parent);
	~MongoEventModel();

	void setModelData(const QList<MongoEventData*>& content);
	void reset();

private:
	// Implementing QAbstractItemModel
	virtual QModelIndex	index(int row, int column, const QModelIndex & parent = QModelIndex()) const;
	virtual int			columnCount(const QModelIndex & parent = QModelIndex()) const;
	virtual QVariant	data(const QModelIndex & index, int role = Qt::DisplayRole) const;
	virtual QModelIndex	parent(const QModelIndex & index) const;
	virtual int			rowCount(const QModelIndex & parent = QModelIndex()) const;
	virtual QVariant	headerData(int section, Qt::Orientation orientation, int role = Qt::DisplayRole) const;
	virtual void 		sort(int column, Qt::SortOrder order = Qt::AscendingOrder);

	void	sortByMessage(bool acsending);
	void	sortByTime(bool acsending);
};

#endif // EVENTSTREEMODEL_H
