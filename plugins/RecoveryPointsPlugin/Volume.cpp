#include "Volume.h"


Volume::Volume()
{
}


Volume::~Volume()
{
}

QString Volume::deviceId()
{
	return m_deviceId;
}

QString Volume::displayName()
{
	return m_displayName;
}

QString Volume::label()
{
	return m_label;
}

uint Volume::capacity()
{
	return m_iCapacity;
}

uint Volume::usedCapacity()
{
	return m_iUsedCapacity;
}

QString Volume::driverId()
{
	return m_deviceId;
}

bool Volume::isClean()
{
	return m_bIsClean;
}

QString Volume::fileSystem()
{
	return m_fileSystem;
}

uint Volume::previousEpochNumber()
{
	return m_iPreviousEpochNumber;
}

QString Volume::guidName()
{
	return m_guidName;
}

QString Volume::strSize(qlonglong size)
{
	int deep = 0;
	double value = size;

	while (value > 1024)
	{
		value = value / 1024;
		deep++;
	}

	QString marker;

	switch (deep)
	{
	case 0:
		marker = "bytes";
		break;
	case 1:
		marker = "Kb";
		break;
	case 2:
		marker = "Mb";
		break;
	case 3:
		marker = "Gb";
		break;
	case 4:
		marker = "Tb";
		break;
	}

	QString result = QString("%1 %2").arg(QString::number(value, 'f', 2)).arg(marker);

	return result;
}
