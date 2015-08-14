#pragma once

#include <QString>

class RecoveryPointsParser;

class Volume
{
private:
	QString m_deviceId;
	QString m_displayName;
	QString m_label;
	uint m_iCapacity;
	uint m_iUsedCapacity;
	QString m_driverId;
	bool m_bIsClean;
	QString m_fileSystem;
	uint m_iPreviousEpochNumber;
	QString m_guidName;

public:
	Volume();
	~Volume();

	QString deviceId();

	QString displayName();

	QString label();

	uint capacity();

	uint usedCapacity();

	QString driverId();

	bool isClean();

	QString fileSystem();

	uint previousEpochNumber();

	QString guidName();

	static QString strSize(qlonglong size);

private:
	friend class RecoveryPointsParser;
};

