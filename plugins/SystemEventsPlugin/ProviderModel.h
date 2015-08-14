#ifndef PROVIDERSMODEL_H
#define PROVIDERSMODEL_H

#include <QAbstractItemModel>
#include <QStringList>

#include "ProviderData.h"

class ProviderModel : public QAbstractItemModel
{
	Q_OBJECT
private:
	QList<ProviderData*> m_data;

public:
	ProviderModel(QObject *parent);
	~ProviderModel();

	void setModelData(QStringList data);
	ProviderData* rawData(const QModelIndex& index);

	void inverseProvider(const QModelIndex& index);
	QStringList enabledProviders();

	void reset();

	void selectAll();
	void unselectAll();

private:
	virtual QModelIndex	index(int row, int column, const QModelIndex & parent = QModelIndex()) const;
	virtual int			columnCount(const QModelIndex & parent = QModelIndex()) const;
	virtual QVariant	data(const QModelIndex & index, int role = Qt::DisplayRole) const;
	virtual QModelIndex	parent(const QModelIndex & index) const;
	virtual int			rowCount(const QModelIndex & parent = QModelIndex()) const;
	virtual Qt::ItemFlags flags(const QModelIndex & index) const;

};

#endif // PROVIDERSMODEL_H
