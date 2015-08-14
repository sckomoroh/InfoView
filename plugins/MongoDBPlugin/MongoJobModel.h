#ifndef MongoJobModel_H
#define MongoJobModel_H

#include <QObject>
#include <QAbstractItemModel>
#include <QList>
#include <QImage>

#include "MongoJobData.h"


class MongoJobModel : public QAbstractItemModel
{
	Q_OBJECT
private:
	static QImage m_success;
	static QImage m_fail;
	static QImage m_cancel;

private:
	MongoJobData*			m_pRootItem;

public:
	MongoJobModel(QObject *parent);
	~MongoJobModel();

	void setModelData(const QList<MongoJobData*>& content);
	MongoJobData* rawData(const QModelIndex & index);
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

#endif // MongoJobModel_H
