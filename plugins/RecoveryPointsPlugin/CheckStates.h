#pragma once

#include <QString>

enum CheckState
{
	NoneState = 0x0000,
	PassedChecks = 0x0001,
	FailedChecks = 0x0002,
	PassedExchangeMountabilityCheck = 0x0004,
	FailedExchangeMountabilityCheck = 0x0008,
	PassedExchangeChecksumCheck = 0x0010,
	FailedExchangeChecksumCheck = 0x0020,
	PassedSqlAttachabilityCheck = 0x0040,
	FailedSqlAttachabilityCheck = 0x0080,
	PassedNtfsCheckDisk = 0x0100,
	FailedNtfsCheckDisk = 0x0200,
	RequiredChecks = 0x0400,
	PassedMountCheckDisk = 0x0800,
	FailedMountCheckDisk = 0x1000,
	RequiredExchangeChecks = 0x2000,

	White = NoneState,
	Green = PassedChecks,
	Red = FailedChecks,
	Yellow = RequiredChecks,
};

class CheckStatesParser
{
public:
	static int parseCheckState(QString strCheck);
};

