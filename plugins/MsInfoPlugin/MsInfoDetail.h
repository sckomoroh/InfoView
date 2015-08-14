#pragma once

#include <QList>
#include <QString>

class MsInfoDetail
{
public:
	static int m_iSortColumn;

private:
	QList<QString> m_data;

public:
	MsInfoDetail();
	~MsInfoDetail();

	void addValue(const QString& value);
	
	inline const QList<QString>& values() const
	{
		return m_data;
	}

	static bool ascCompare(MsInfoDetail* item1, MsInfoDetail* item2);
	static bool descCompare(MsInfoDetail* item1, MsInfoDetail* item2);

};

