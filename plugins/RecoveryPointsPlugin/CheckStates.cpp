#include "CheckStates.h"

#include <QStringList>
#include <QDebug>

int CheckStatesParser::parseCheckState(QString strCheck)
{
	QStringList checks = strCheck.split(" ");
	int result = 0;

	for each (QString check in checks)
	{
		if (check == "None")
		{
			continue;
		}

		if (check == "PassedChecks" || check == "MountCheckPassed" || check == "ChecksumCheckPassed" || check == "AttachabilityCheckPassed" || check == "PassedExchangeMountabilityCheck" || check == "PassedExchangeChecksumCheck") //
		{
			result |= CheckStatesParser::Green;
			continue;
		}
		else if (check == "FailedChecks" || check == "MountCheckFailed" || check == "ChecksumCheckFailed" || check == "FailedExchangeChecksumCheck" || check == "FailedExchangeMountabilityCheck") //
		{
			result |= CheckStatesParser::FailedChecks;
			continue;
		}
		else if (check == "RequiredChecks" || check == "RequiredExchangeChecks")
		{
			result |= CheckStatesParser::Yellow;
			continue;
		}

		if (check != "None")
		{
			qDebug() << "CHECK STATE:" << check;
		}
	}

	return result;
}
