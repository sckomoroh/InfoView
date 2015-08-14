#ifndef AGENTSTREEMODEL_H
#define AGENTSTREEMODEL_H

#include <QAbstractItemModel>
#include <QList>

#include "BaseModelItem.h"
#include "AgentModelItem.h"
#include "VolumeModelItem.h"
#include "RecoveryPointModelItem.h"

class AgentsTreeModel : public QAbstractItemModel
{
	Q_OBJECT
private:
	BaseModelItem* m_pRootItem;

public:
	AgentsTreeModel(QObject *parent);
	~AgentsTreeModel();

	void reset();

	void setRootItem(BaseModelItem* pRootItem);

	virtual QVariant data(const QModelIndex &index, int role) const;
	virtual QVariant headerData(int section, Qt::Orientation orientation, int role = Qt::DisplayRole) const;
	virtual QModelIndex index(int row, int column, const QModelIndex &parent = QModelIndex()) const;
	virtual QModelIndex parent(const QModelIndex &index) const;
	virtual int rowCount(const QModelIndex &parent = QModelIndex()) const;
	virtual int columnCount(const QModelIndex &parent = QModelIndex()) const;
	virtual void 		sort(int column, Qt::SortOrder order = Qt::AscendingOrder);

	BaseModelItem* dataItem(const QModelIndex& index);

private:
	QVariant agentData(AgentModelItem* pAgentItem, int column, int role) const;
	QVariant recoveryPointData(RecoveryPointModelItem* pRecoveryPointItem, int column, int role) const;
	QVariant volumeData(VolumeModelItem* pVolumeItem, int column, int role) const;

	void sortByDate(bool bAscending);
	void sortBySize(bool bAscending);
};

#endif // AGENTSTREEMODEL_H
