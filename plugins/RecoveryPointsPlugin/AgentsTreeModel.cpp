#include "AgentsTreeModel.h"

#include <QImage>
#include <QDebug>

AgentsTreeModel::AgentsTreeModel(QObject *parent)
	: QAbstractItemModel(parent)
	, m_pRootItem(NULL)
{
	//m_pRootItem = factory.create("d:\\logs\\2430527\\1\\RecoveryPoints\\");
	qDebug() << "Creating AGENT TREE MODEL";
}

AgentsTreeModel::~AgentsTreeModel()
{
	qDebug() << "Removing AGENT TREE MODEL";

	if (m_pRootItem)
	{
		delete m_pRootItem;
	}
}

void AgentsTreeModel::reset()
{
	beginResetModel();

	if (m_pRootItem)
	{
		m_pRootItem = NULL;
	}

	endResetModel();
}

void AgentsTreeModel::setRootItem(BaseModelItem* pRootItem)
{
	beginResetModel();
	m_pRootItem = pRootItem;
	endResetModel();
}

QVariant AgentsTreeModel::data(const QModelIndex &index, int role) const
{
	if (!index.isValid())
	{
		return QVariant();
	} 

	if (role != Qt::DisplayRole && role != Qt::DecorationRole)
	{
		return QVariant();
	}


	BaseModelItem* pItem = static_cast<BaseModelItem*>(index.internalPointer());

	AgentModelItem* pVolumeItem = dynamic_cast<AgentModelItem*>(pItem);
	if (pVolumeItem)
	{
		return agentData(pVolumeItem, index.column(), role);
	}

	RecoveryPointModelItem* pRecoveryPoint = dynamic_cast<RecoveryPointModelItem*>(pItem);
	if (pRecoveryPoint)
	{
		return recoveryPointData(pRecoveryPoint, index.column(), role);
	}

	VolumeModelItem* pVolume = dynamic_cast<VolumeModelItem*>(pItem);
	if (pVolume)
	{
		return volumeData(pVolume, index.column(), role);
	}

	return QVariant();
}

QVariant AgentsTreeModel::headerData(int section, Qt::Orientation orientation, int role) const
{
	if (orientation == Qt::Horizontal && role == Qt::DisplayRole)
	{
		switch (section)
		{
			case 0 :
				return "Content";
			case 1:
				return "State";
			case 2:
				return "Date";
			case 3:
				return "Size";
		}
	}

	return QVariant();
}

QModelIndex AgentsTreeModel::index(int row, int column, const QModelIndex &parent) const
{
	if (!hasIndex(row, column, parent))
		return QModelIndex();

	BaseModelItem* pParentItem;

	if (!parent.isValid())
	{
		pParentItem = m_pRootItem;
	}
	else
	{
		pParentItem = static_cast<BaseModelItem*>(parent.internalPointer());
	}

	BaseModelItem* pChildItem = pParentItem->child(row);

	if (pChildItem)
	{
		return createIndex(row, column, pChildItem);
	}
	else
	{
		return QModelIndex();
	}
}

QModelIndex AgentsTreeModel::parent(const QModelIndex &index) const
{
	if (!index.isValid())
	{
		return QModelIndex();
	}

	BaseModelItem* pChildItem = static_cast<BaseModelItem*>(index.internalPointer());
	BaseModelItem* pParentItem = pChildItem->parent();

	if (pParentItem == m_pRootItem)
	{
		return QModelIndex();
	}

	return createIndex(pParentItem->row(), 0, pParentItem);
}

int AgentsTreeModel::rowCount(const QModelIndex &parent) const
{
	BaseModelItem *pParentItem;
	if (parent.column() > 0)
	{
		return 0;
	}

	if (!parent.isValid())
	{
		pParentItem = m_pRootItem;
	}
	else
	{
		pParentItem = static_cast<BaseModelItem*>(parent.internalPointer());
	}

	if (pParentItem == NULL)
	{
		return 0;
	}

	return pParentItem->childCount();
}

int AgentsTreeModel::columnCount(const QModelIndex&) const
{
	return 4;
}

QVariant AgentsTreeModel::agentData(AgentModelItem* pAgentItem, int column, int role) const
{
	switch (column)
	{
		case 0:
			if (role == Qt::DecorationRole)
			{
				return QImage(":/plugin/images/Resources/Computer.png");
			}

			return pAgentItem->displayName();

		case 1:
			return pAgentItem->childCount();
	}

	return QVariant();
}

QVariant AgentsTreeModel::recoveryPointData(RecoveryPointModelItem* pRecoveryPointItem, int column, int role) const
{
	switch (column)
	{
		case 0:
			if (role == Qt::DecorationRole)
			{
				switch (pRecoveryPointItem->checkState())
				{
					case CheckState::Green:
						return QImage(":/plugin/images/Resources/GreenBall.png");
					case CheckState::Red:
						return QImage(":/plugin/images/Resources/RedBall.png");
					case CheckState::Yellow:
						return QImage(":/plugin/images/Resources/YellowBall.png");
				}
				
				return QImage(":/plugin/images/Resources/GrayBall.png");
			}

			return pRecoveryPointItem->content();
		case 1:
			return pRecoveryPointItem->status();
		case 2:
			return pRecoveryPointItem->timestamp();
		case 3:
			return Volume::strSize(pRecoveryPointItem->size());
	}

	return QVariant();
}

QVariant AgentsTreeModel::volumeData(VolumeModelItem* pVolumeItem, int column, int role) const
{
	switch (column)
	{
	case 0:
		if (role == Qt::DecorationRole)
		{
			switch (pVolumeItem->checkState())
			{
				case CheckState::Green:
					return QImage(":/plugin/images/Resources/GreenBall.png");
				case CheckState::Red:
					return QImage(":/plugin/images/Resources/RedBall.png");
				case CheckState::Yellow:
					return QImage(":/plugin/images/Resources/YellowBall.png");
			}

			return QImage(":/plugin/images/Resources/GrayBall.png");
		}

		return pVolumeItem->displayName();
	case 1:
		return pVolumeItem->status();
	case 2:
		return pVolumeItem->timestamp();
	case 3:
		return Volume::strSize(pVolumeItem->size());
	}

	return QVariant();
}

BaseModelItem* AgentsTreeModel::dataItem(const QModelIndex& index)
{
	if (index.isValid())
	{
		BaseModelItem* pItem = static_cast<BaseModelItem*>(index.internalPointer());

		return pItem;
	}

	return NULL;
}

void AgentsTreeModel::sort(int column, Qt::SortOrder order)
{
	beginResetModel();

	switch (column)
	{
	case 2:
		sortByDate(order == Qt::AscendingOrder);
		break;
	case 3:
		sortBySize(order == Qt::AscendingOrder);
		break;
	}

	endResetModel();
}

void AgentsTreeModel::sortBySize(bool bAscending)
{
	QList<BaseModelItem*> agents = m_pRootItem->children();
	for each (BaseModelItem* pAgent in agents)
	{
		QList<BaseModelItem*>& recoveryPoints = pAgent->children();

		if (bAscending)
		{
			qSort(recoveryPoints.begin(), recoveryPoints.end(), RecoveryPointModelItem::ascSizeCompare);
		}
		else
		{
			qSort(recoveryPoints.begin(), recoveryPoints.end(), RecoveryPointModelItem::descSizeCompare);
		}
	}
}

void AgentsTreeModel::sortByDate(bool bAscending)
{
	QList<BaseModelItem*> agents = m_pRootItem->children();
	for each (BaseModelItem* pAgent in agents)
	{
		QList<BaseModelItem*>& recoveryPoints = pAgent->children();

		if (bAscending)
		{
			qSort(recoveryPoints.begin(), recoveryPoints.end(), RecoveryPointModelItem::ascTimeCompare);
		}
		else
		{
			qSort(recoveryPoints.begin(), recoveryPoints.end(), RecoveryPointModelItem::descTimeCompare);
		}
	}
}
