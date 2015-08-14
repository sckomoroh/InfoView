#ifndef EVENTSTABLEMODEL_H
#define EVENTSTABLEMODEL_H

#include <QAbstractItemModel>
#include <QList>
#include <QString>

#include "SystemEventData.h"
#include "SystemEventStorage.h"
#include "IStorageListener.h"

class SystemEventModel 
	: public QAbstractItemModel
	, public IStorageListener
{
	Q_OBJECT
private:
	SystemEventStorage* m_storage;

	static QImage m_sysEventCritical;
	static QImage m_sysEventError;
	static QImage m_sysEventInfo;
	static QImage m_sysEventVerbose;
	static QImage m_sysEventWarning;
	static QImage m_sysEventLogAlways;
	static QImage m_sysEventQuestion;

public:
	SystemEventModel(SystemEventStorage* storage, QObject *parent);
	~SystemEventModel();

	SystemEventData* rawData(const QModelIndex & index);

	void reset();

public:
	virtual void beginStorageChange();
	virtual void endStorageChange();

private:
	virtual QModelIndex	index(int row, int column, const QModelIndex & parent = QModelIndex()) const;
	virtual int			columnCount(const QModelIndex & parent = QModelIndex()) const;
	virtual QVariant	data(const QModelIndex & index, int role = Qt::DisplayRole) const;
	virtual QModelIndex	parent(const QModelIndex & index) const;
	virtual int			rowCount(const QModelIndex & parent = QModelIndex()) const;
	virtual QVariant	headerData(int section, Qt::Orientation orientation, int role = Qt::DisplayRole) const;
	virtual void 		sort(int column, Qt::SortOrder order = Qt::AscendingOrder);

private:
	void sortByEventId(bool ascending);
	void sortByProvider(bool ascending);
	void sortByTime(bool ascending);
};

#endif // EVENTSTABLEMODEL_H
