#ifndef WIN32WIDGET_H
#define WIN32WIDGET_H

#include <QWidget>

class Win32Widget : public QWidget
{
private:
	HWND m_child;

public:
	Win32Widget(QWidget *parent);
	~Win32Widget();

	void setChild(HWND hWnd);

protected:
	virtual void resizeEvent(QResizeEvent *event);

private:
	
};

#endif // WIN32WIDGET_H
