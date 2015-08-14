#ifndef EVENTSTREEMODEL_H
#define EVENTSTREEMODEL_H

#include <QAbstractItemModel>
#include <QList>
#include <QImage>

#include "MongoEventData.h"
#include "MongoEventStorage.h"

class MongoEventModel 
	: public QAbstractItemModel
	, public IMongoStorageListener
{
	Q_OBJECT
private:
	static QImage m_eventError;
	static QImage m_eventInformation;
	static QImage m_eventWarning;
	static QImage m_eventUnknown;

private:
	MongoEventStorage* m_storage;

public:
	MongoEventModel(MongoEventStorage* storage, QObject *parent);
	~MongoEventModel();

private:
	virtual void onBeginChange();
	virtual void onEndChange();

private:
	// Implementing QAbstractItemModel
	virtual QModelIndex	index(int row, int column, const QModelIndex & parent = QModelIndex()) const;
	virtual int			columnCount(const QModelIndex & parent = QModelIndex()) const;
	virtual QVariant	data(const QModelIndex & index, int role = Qt::DisplayRole) const;
	virtual QModelIndex	parent(const QModelIndex & index) const;
	virtual int			rowCount(const QModelIndex & parent = QModelIndex()) const;
	virtual QVariant	headerData(int section, Qt::Orientation orientation, int role = Qt::DisplayRole) const;
	virtual void 		sort(int column, Qt::SortOrder order = Qt::AscendingOrder);
};

#endif // EVENTSTREEMODEL_H
