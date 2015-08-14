#ifndef LOGVIEWWIDGET_H
#define LOGVIEWWIDGET_H

#include <QWidget>
#include <QMenu>
#include <QScrollArea>

#include "CustomTextViewLine.h"
#include "CustomTextViewModel.h"
#include "CustomTextViewSearchLine.h"

class CustomTextViewWidget : public QWidget
{
	Q_OBJECT
private:
	static const QBrush m_selectionBrush;
	static const QBrush m_highlightBrush;

	CustomTextViewModel* m_pModel;

	QAction*        m_pCopyAction;
	QAction*        m_pSelectAllAction;
	QMenu*          m_pContextMenu;
	QScrollArea*    m_pScrollArea;
	QFont           m_normalFont;
	QFont           m_boldFont;
	QString         m_filterString;
	QFontMetrics    m_fontMetrics;
	QFontMetrics    m_boldFontMetrics;
	int             m_width;
	int             m_fontHeight;
	bool            m_isMousePressed;
	bool            m_isMouseMoveUp;
	int             m_startSelectionLine;
	int             m_startSelectionPos;
	int             m_endSelectionLine;
	int             m_endSelectionPos;
	int             m_levelFlags;
	uint			m_iId;
	bool			m_bSelectOnDoubleClick;
	bool			m_bHighlightWords;

public:
	CustomTextViewWidget(QWidget* parent = 0);

	void setId(uint iId);

	QSize sizeHint() const;

	void setScrollArea(QScrollArea* m_pScrollArea);

	void setModel(CustomTextViewModel* pModel);
	void updateModel();
	void setSelectOnDoubleClick(bool bSelectOnDoubleClick);
	void setHighlightWords(bool bHighlightWords);

	bool search(const QString& searchString, bool bCaseSens, bool bBack);
	QList<CustomTextViewSearchLine*> searchAll(const QString& title, const QString& searchString, bool bCaseSens);
	void setSelection(uint iLine, uint iStart, uint iEnd);

protected:
	virtual void paintEvent(QPaintEvent *event);
	
	virtual void mousePressEvent(QMouseEvent* pe);
	virtual void mouseReleaseEvent(QMouseEvent* pe);
	virtual void mouseMoveEvent(QMouseEvent* pe);
	virtual void mouseDoubleClickEvent(QMouseEvent* event);
	virtual void keyPressEvent(QKeyEvent *event);
	virtual void keyReleaseEvent(QKeyEvent* event);

private:
	int		charNumber(const QString& string, int mousePos, bool isBold);
	void	swapPositions();
	void	drawPartialRowSelection(QPainter* painter, const QString& currentLine, int position);
	void	drawFullRowSelection(QPainter* painter, const QString& line, int position);
	void	drawHighlightBackground(QPainter* painter, const QString& highlightStr, const QString& currentLine, int position);
	QString	highlightString();
	void	selectWord(int line, int pos);

	QFontMetrics& getFontMetrics(int lineNumber);

private slots:
	void onCopyAction();
	void onSelectAllAction();

	void onModelUpdated();

signals:
	void showSearchArea();
	void doubleClicked(CustomTextViewLine* pLine);
};

#endif // LOGVIEWWIDGET_H
