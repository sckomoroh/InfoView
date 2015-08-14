#ifndef MongoJobModel_H
#define MongoJobModel_H

#include <QObject>
#include <QAbstractItemModel>
#include <QList>
#include <QImage>

#include "MongoJobData.h"
#include "MongoJobStorage.h"
#include "IMongoStorageListener.h"

class MongoJobModel 
	: public QAbstractItemModel
	, IMongoStorageListener
{
	Q_OBJECT
private:
	static QImage m_success;
	static QImage m_fail;
	static QImage m_cancel;

private:
	MongoJobData*		m_pRootItem;
	MongoJobStorage*	m_storage;

public:
	MongoJobModel(MongoJobStorage* storage, QObject *parent);
	~MongoJobModel();

public:
	virtual void onBeginChange();
	virtual void onEndChange();

	MongoJobData* rawData(const QModelIndex & index);

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

#endif // MongoJobModel_H
