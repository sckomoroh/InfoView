#include "msinfodetail.h"

int MsInfoDetail::m_iSortColumn = 0;

MsInfoDetail::MsInfoDetail()
{
}

MsInfoDetail::~MsInfoDetail()
{

}

void MsInfoDetail::addValue(const QString& value)
{
	m_data.append(value);
}

bool MsInfoDetail::ascCompare(MsInfoDetail* item1, MsInfoDetail* item2)
{
	return item1->values().at(m_iSortColumn) < item2->values().at(m_iSortColumn);
}

bool MsInfoDetail::descCompare(MsInfoDetail* item1, MsInfoDetail* item2)
{
	return item1->values().at(m_iSortColumn) > item2->values().at(m_iSortColumn);
}
