#include "Win32Widget.h"

#include <QResizeEvent>

#include <Windows.h>

Win32Widget::Win32Widget(QWidget *parent)
	: QWidget(parent)
	, m_child(NULL)
{

}

Win32Widget::~Win32Widget()
{

}

void Win32Widget::setChild(HWND hWnd)
{
	m_child = hWnd;
}

void Win32Widget::resizeEvent(QResizeEvent *evt)
{
	QSize size = evt->size();

	if (size.width() > 0 && size.height() > 0)
	{
		::PostMessage(m_child, WM_SIZE, size.width(), size.height());
	}
}
