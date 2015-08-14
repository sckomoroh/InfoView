#pragma once

class IMongoStorageListener
{
public:
	virtual void onBeginChange() = 0;
	virtual void onEndChange() = 0;
};