#pragma once

class IStorageListener
{
public:
	virtual void beginStorageChange() = 0;
	virtual void endStorageChange() = 0;
};
