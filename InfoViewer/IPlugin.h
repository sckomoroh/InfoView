#pragma once

#define TESTPLUGIN_EXPORT Q_DECL_IMPORT

// Interface
class TESTPLUGIN_EXPORT IPlugin
{
public:
	virtual wchar_t*	getPluginName() = 0;
	virtual wchar_t*	getPluginId() = 0;
	virtual void		initPluginData(wchar_t* path) = 0;
	virtual void		resetPluginData() = 0;
};

class TESTPLUGIN_EXPORT IWin32Plugin : public IPlugin
{
public:
	virtual void createPluginControl() = 0;
	virtual HWND getPluginControlHWND() = 0;
};

class TESTPLUGIN_EXPORT IQtPlugin : public IPlugin
{
public:
	virtual QWidget*	getPluginWidget() = 0;
	virtual QImage*		getPluginIcon() = 0;
};

typedef IPlugin* (*createWin32PluginFuncPtr)(HWND parentWnd, unsigned int controlId);
typedef IPlugin* (*createPluginFuncPtr)();
typedef int (*isWin32FuncPtr)();
