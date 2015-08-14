#include "CustomTextViewWidget.h"

#include <QDebug>
#include <QPainter>
#include <QScrollBar>
#include <QMouseEvent>
#include <QApplication>
#include <QClipboard>

#define FONT_FAMILY_NAME "Arial"
#define FONT_SIZE 10

const QBrush CustomTextViewWidget::m_selectionBrush = QBrush(QColor(17, 255, 177));
const QBrush CustomTextViewWidget::m_highlightBrush = QBrush(QColor(200, 200, 200));

CustomTextViewWidget::CustomTextViewWidget(QWidget *parent)
	: QWidget(parent)
	, m_pScrollArea(NULL)
	, m_normalFont(FONT_FAMILY_NAME, FONT_SIZE)
	, m_boldFont(FONT_FAMILY_NAME, FONT_SIZE, QFont::Bold)
	, m_width(0)
	, m_isMousePressed(false)
	, m_isMouseMoveUp(false)
	, m_startSelectionLine(0)
	, m_startSelectionPos(0)
	, m_endSelectionLine(0)
	, m_endSelectionPos(0)
	, m_fontMetrics(m_normalFont)
	, m_boldFontMetrics(m_boldFont)
	, m_levelFlags(15)
	, m_pModel(NULL)
	, m_iId(0)
	, m_bHighlightWords(true)
	, m_bSelectOnDoubleClick(true)
{
	m_fontHeight = m_fontMetrics.height();
	setCursor(Qt::IBeamCursor);

	m_pCopyAction = new QAction("Copy", this);
	m_pSelectAllAction = new QAction("Select all", this);

	m_pCopyAction->setShortcut(QKeySequence("CTRL+C"));
	m_pSelectAllAction->setShortcut(QKeySequence("CTRL+A"));

	m_pContextMenu = new QMenu(this);

	m_pContextMenu->addAction(m_pCopyAction);
	m_pContextMenu->addAction(m_pSelectAllAction);

	connect(m_pCopyAction, SIGNAL(triggered()), SLOT(onCopyAction()));
	connect(m_pSelectAllAction, SIGNAL(triggered()), SLOT(onSelectAllAction()));
}

void CustomTextViewWidget::setScrollArea(QScrollArea *pScrollArea)
{
	if (pScrollArea != NULL)
	{
		this->m_pScrollArea = pScrollArea;
	}
}

void CustomTextViewWidget::setId(uint iId)
{
	m_iId = iId;
}

void CustomTextViewWidget::setModel(CustomTextViewModel* pModel)
{
	m_pModel = pModel;

	connect(pModel, SIGNAL(modelUpdated()), SLOT(onModelUpdated()));

	onModelUpdated();
}

void CustomTextViewWidget::setSelectOnDoubleClick(bool bSelectOnDoubleClick)
{
	m_bSelectOnDoubleClick = bSelectOnDoubleClick;
}

void CustomTextViewWidget::setHighlightWords(bool bHighlightWords)
{
	m_bHighlightWords = bHighlightWords;
}

void CustomTextViewWidget::paintEvent(QPaintEvent*)
{
	QPainter painter(this);
	painter.setFont(m_normalFont);

	if (m_pScrollArea != NULL)
	{
		QSize widgetSize = m_pScrollArea->viewport()->size();
		int count = (widgetSize.height() / m_fontHeight) + 10;
		int startPosVal = m_pScrollArea->verticalScrollBar()->value();
		int startPos = (startPosVal / m_fontHeight - 0.5);

		count = count + startPos >= m_pModel->linesCount()
			? m_pModel->linesCount() - startPos
			: count;

		for (int i = startPos; i<count + startPos; i++)
		{
			CustomTextViewLine* pLine = m_pModel->lineAt(i);

			painter.setPen(*(pLine->color()));

			if (m_startSelectionLine <= i || m_endSelectionLine >= i)
			{
				drawFullRowSelection(&painter, pLine->string(), i);
				drawPartialRowSelection(&painter, pLine->string(), i);
			}

			if (pLine->isBold())
			{
				painter.setFont(m_boldFont);
			}
			else
			{
				painter.setFont(m_normalFont);
			}

			painter.drawText(10, (i + 1)*m_fontHeight, pLine->string());
		}
	}
}

void CustomTextViewWidget::mousePressEvent(QMouseEvent* pe)
{
	if (pe->button() == Qt::LeftButton)
	{
		m_isMousePressed = true;

		int posY = pe->pos().y();

		int lineNumber = posY / m_fontHeight;
		if (lineNumber >= m_pModel->linesCount())
		{
			return;
		}

		QString line = m_pModel->lineAt(lineNumber)->string();

		bool isBold = m_pModel->lineAt(lineNumber)->isBold();
		int charPos = charNumber(line, pe->pos().x() - 10, isBold);

		m_startSelectionPos = m_endSelectionPos = charPos;
		m_endSelectionLine = m_startSelectionLine = lineNumber;

		update();

		return;
	}

	if (pe->button() == Qt::RightButton)
	{
		m_pContextMenu->move(pe->globalX(), pe->globalY());
		m_pContextMenu->exec();
	}
}

void CustomTextViewWidget::mouseDoubleClickEvent(QMouseEvent *event)
{
	if (event->button() == Qt::LeftButton)
	{
		int posY = event->pos().y();

		int lineNumber = posY / m_fontHeight;
		if (lineNumber >= m_pModel->linesCount())
		{
			return;
		}

		if (m_bSelectOnDoubleClick)
		{
			QString line = m_pModel->lineAt(lineNumber)->string();

			bool isBold = m_pModel->lineAt(lineNumber)->isBold();
			int charPos = charNumber(line, event->pos().x() - 10, isBold);

			selectWord(lineNumber, charPos);
		}

		emit doubleClicked(m_pModel->lineAt(lineNumber));
	}
}

void CustomTextViewWidget::mouseReleaseEvent(QMouseEvent* pe)
{
	if (pe->button() == Qt::LeftButton)
	{
		m_isMousePressed = false;
	}
}

void CustomTextViewWidget::mouseMoveEvent(QMouseEvent* pe)
{
	if (m_isMousePressed)
	{
		int posY = pe->pos().y();

		int lineNumber = posY / m_fontHeight;
		if (lineNumber >= m_pModel->linesCount())
		{
			return; 
		}

		QString line = m_pModel->lineAt(lineNumber)->string();

		bool isBold = m_pModel->lineAt(lineNumber)->isBold();
		int charPos = charNumber(line, pe->pos().x() - 10, isBold);

		if (m_isMousePressed)
		{
			bool oldMouseDirection = m_isMouseMoveUp;

			if (lineNumber < m_startSelectionLine)
			{
				m_isMouseMoveUp = true;
			}

			if (lineNumber > m_endSelectionLine)
			{
				m_isMouseMoveUp = false;
			}

			if (m_isMouseMoveUp != oldMouseDirection)
			{
				swapPositions();
			}

			if (m_isMouseMoveUp)
			{
				m_startSelectionLine = lineNumber;
				m_startSelectionPos = charPos;
			}
			else
			{
				m_endSelectionPos = charPos;
				m_endSelectionLine = lineNumber;
			}

			update();
		}
	}
}

int CustomTextViewWidget::charNumber(const QString& string, int mousePos, bool isBold)
{
	QFontMetrics* fontMetrics = NULL;
	if (isBold)
	{
		fontMetrics = &m_boldFontMetrics;
	}
	else
	{
		fontMetrics = &m_fontMetrics;
	}

	for (int i = 0; i<string.length(); i++)
	{
		if (fontMetrics->width(string.mid(0, i)) > mousePos)
		{
			return i;
		}
	}

	return string.length();
}

void CustomTextViewWidget::swapPositions()
{
	int tempLine = m_startSelectionLine;
	int tempPos = m_startSelectionPos;

	m_startSelectionLine = m_endSelectionLine;
	m_startSelectionPos = m_endSelectionPos;
	m_endSelectionPos = tempPos;
	m_endSelectionLine = tempLine;
}

void CustomTextViewWidget::drawPartialRowSelection(QPainter* painter, const QString& currentLine, int position)
{
	int lineNumber = position;
	if (m_startSelectionLine != m_endSelectionLine || m_startSelectionPos != m_endSelectionPos)
	{
		if (lineNumber == m_startSelectionLine && lineNumber == m_endSelectionLine && m_startSelectionPos != m_endSelectionPos)
		{
			int dif = m_endSelectionPos - m_startSelectionPos;
			int start = m_startSelectionPos;

			if (dif < 0)
			{
				dif = -dif;
				start = m_endSelectionPos;
			}

			QString selectedString = currentLine.mid(start, dif);
			QString beforeSelectedString = currentLine.mid(0, start);

			painter->fillRect(
				10 + getFontMetrics(lineNumber).width(beforeSelectedString),
				position * m_fontHeight + 4,
				getFontMetrics(lineNumber).width(selectedString),
				m_fontHeight,
				m_selectionBrush);
		}
		else
		{
			if (lineNumber == m_startSelectionLine)
			{
				QString selectedString = currentLine.mid(m_startSelectionPos);
				int startPos = getFontMetrics(lineNumber).width(currentLine) - getFontMetrics(lineNumber).width(selectedString);
				painter->fillRect(
					10 + startPos,
					position * m_fontHeight + 4,
					getFontMetrics(lineNumber).width(selectedString),
					m_fontHeight,
					m_selectionBrush);
			}

			if (lineNumber == m_endSelectionLine)
			{
				QString selectedString = currentLine.mid(0, m_endSelectionPos);
				painter->fillRect(
					10,
					position * m_fontHeight + 4,
					getFontMetrics(lineNumber).width(selectedString),
					m_fontHeight,
					m_selectionBrush);
			}

			if (m_bHighlightWords)
			{
				drawHighlightBackground(painter, highlightString(), currentLine, position);
			}
		}
	}
}

void CustomTextViewWidget::drawFullRowSelection(QPainter* painter, const QString& line, int position)
{
	int lineNumber = position;
	if (lineNumber > m_startSelectionLine && lineNumber < m_endSelectionLine)
	{
		painter->fillRect(10, position * m_fontHeight + 4, getFontMetrics(lineNumber).width(line), m_fontHeight, m_selectionBrush);
	}
}

QString CustomTextViewWidget::highlightString()
{
	if (m_startSelectionLine == m_endSelectionLine && m_startSelectionPos != m_endSelectionPos)
	{
		int count = m_endSelectionPos - m_startSelectionPos;
		int startIndex = m_startSelectionPos;

		if (count < 0)
		{
			count = -count;
			startIndex = m_endSelectionPos;
		}

		QString result = m_pModel->lineAt(m_startSelectionLine)->string();
		result = result.mid(startIndex, count);
		return result;
	}

	return QString::null;
}

void CustomTextViewWidget::drawHighlightBackground(QPainter* painter, const QString& highlightStr, const QString& currentLine, int position)
{
	if (highlightStr != QString::null && currentLine.contains(highlightStr) && position != m_startSelectionLine - 1)
	{
		int index = currentLine.indexOf(highlightStr);

		while (index != -1)
		{
			QString beforeStr = currentLine.mid(0, index);

			painter->fillRect(
				getFontMetrics(position).width(beforeStr) + 10,
				position * m_fontHeight + 4,
				getFontMetrics(position).width(highlightStr),
				m_fontHeight,
				m_highlightBrush);

			index = currentLine.indexOf(highlightStr, index + 1);
		}
	}
}

QSize CustomTextViewWidget::sizeHint() const
{
	if (m_pModel != NULL)
	{
		return QSize(m_width, m_pModel->linesCount() * m_fontHeight);
	}

	return QSize(10, 10);
}

void CustomTextViewWidget::selectWord(int lineNumber, int pos)
{
	m_startSelectionLine = m_endSelectionLine = lineNumber;

	QString line = m_pModel->lineAt(lineNumber)->string();

	int index = pos;
	while (line.at(index).isLetterOrNumber() && index > 0)
	{
		index--;
	}

	m_startSelectionPos = index == 0 ? index : index + 1;

	index = pos;
	while (line.at(index).isLetterOrNumber() && index < line.count())
	{
		index++;
	}

	m_endSelectionPos = index;

	update();
}

void CustomTextViewWidget::keyPressEvent(QKeyEvent *event)
{
	if (event->modifiers() == Qt::ControlModifier)
	{
		if (event->key() == Qt::Key_F)
		{
			emit showSearchArea();
		}

		if (event->key() == Qt::Key_C)
		{
			onCopyAction();
		}

		if (event->key() == Qt::Key_A)
		{
			onSelectAllAction();
		}
	}
}

void CustomTextViewWidget::keyReleaseEvent(QKeyEvent *event)
{
	if (event->modifiers() == Qt::ControlModifier)
	{
		if (event->key() == Qt::Key_Home)
		{
			m_pScrollArea->verticalScrollBar()->setValue(0);
			return;
		}

		if (event->key() == Qt::Key_End)
		{
			m_pScrollArea->verticalScrollBar()->setValue(m_pScrollArea->verticalScrollBar()->maximum());
		}

		return;
	}

	if (event->modifiers() == Qt::NoModifier)
	{
		if (event->key() == Qt::Key_Escape)
		{
			m_startSelectionLine = m_endSelectionLine = m_startSelectionPos = m_endSelectionPos = 0;
			update();

			return;
		}

		int pageStep = m_pScrollArea->verticalScrollBar()->pageStep();
		int singleStep = m_pScrollArea->verticalScrollBar()->singleStep();
		int value = m_pScrollArea->verticalScrollBar()->value();
		int maxValue = m_pScrollArea->verticalScrollBar()->maximum();

		int singleStepH = m_pScrollArea->horizontalScrollBar()->singleStep();
		int maxValueH = m_pScrollArea->horizontalScrollBar()->maximum();
		int valueH = m_pScrollArea->horizontalScrollBar()->value();

		qDebug() << "Page step: " << pageStep << " Single step: " << singleStep;

		if (event->key() == Qt::Key_PageUp)
		{
			int val = value - pageStep < 0 ? 0 : value - pageStep;
			m_pScrollArea->verticalScrollBar()->setValue(val);
			return;
		}

		if (event->key() == Qt::Key_PageDown)
		{
			int val = value + pageStep > maxValue ? maxValue : value + pageStep;
			m_pScrollArea->verticalScrollBar()->setValue(val);
			return;
		}

		if (event->key() == Qt::Key_Up)
		{
			int val = value - singleStep < 0 ? 0 : value - singleStep;
			m_pScrollArea->verticalScrollBar()->setValue(val);
			return;
		}

		if (event->key() == Qt::Key_Down)
		{
			int val = value + singleStep > maxValue ? maxValue : value + singleStep;
			m_pScrollArea->verticalScrollBar()->setValue(val);
			return;
		}

		if (event->key() == Qt::Key_Left)
		{
			int val = valueH - singleStepH < 0 ? 0 : valueH - singleStepH;
			m_pScrollArea->horizontalScrollBar()->setValue(val);
			return;
		}

		if (event->key() == Qt::Key_Right)
		{
			int val = valueH + singleStepH > maxValueH ? maxValueH : valueH + singleStepH;
			m_pScrollArea->horizontalScrollBar()->setValue(val);
			return;
		}

		if (event->key() == Qt::Key_Home)
		{
			m_pScrollArea->horizontalScrollBar()->setValue(0);
			return;
		}

		if (event->key() == Qt::Key_End)
		{
			m_pScrollArea->horizontalScrollBar()->setValue(maxValueH);
			return;
		}
	}
}

void CustomTextViewWidget::onCopyAction()
{
	QClipboard* pClipboard = QApplication::clipboard();

	// Get selected text
	if (m_startSelectionLine == m_endSelectionLine)
	{
		if (m_startSelectionPos == m_endSelectionPos)
		{
			// No selection
			return;
		}

		QString selectionString = m_pModel->lineAt(m_startSelectionLine)->string();
		selectionString = selectionString.mid(m_startSelectionPos, m_endSelectionPos - m_startSelectionPos);
		pClipboard->setText(selectionString);
	}
	else
	{
		// Get a partials strings
		QString topString = m_pModel->lineAt(m_startSelectionLine)->string();
		topString = topString.mid(m_startSelectionPos);

		QString bottomString = m_pModel->lineAt(m_endSelectionLine)->string();
		bottomString = bottomString.mid(0, m_endSelectionPos);

		QString fullLines;
		for (int i = m_startSelectionLine + 1; i < m_endSelectionLine - 1; i++)
		{
			fullLines += m_pModel->lineAt(i)->string() + "\r\n";
		}

		fullLines = topString + "\r\n" + fullLines + bottomString;
		pClipboard->setText(fullLines);
	}
}

void CustomTextViewWidget::onSelectAllAction()
{
	m_startSelectionPos = m_startSelectionLine = 0;
	m_endSelectionLine = m_pModel->linesCount() - 1;
	m_endSelectionPos = m_pModel->lineAt(m_endSelectionLine)->string().length();

	update();
}

bool CustomTextViewWidget::search(const QString& searchString, bool bCaseSens, bool bBack)
{
	int iStartPosition = m_startSelectionPos;
	Qt::CaseSensitivity caseSensivity = (Qt::CaseSensitivity)(bCaseSens ? Qt::CaseSensitive : Qt::CaseInsensitive);
	int iIndex, iLineNumber = -1;

	if (bBack)
	{
		if (m_startSelectionPos == m_endSelectionPos && m_startSelectionLine == m_endSelectionLine)
		{
			m_endSelectionLine = m_pModel->linesCount() - 1;
			iStartPosition = m_pModel->lineAt(m_endSelectionLine)->string().length();
		}
		else
		{
			iStartPosition--;
		}

		if (iStartPosition < 0)
		{
			m_endSelectionLine--;
			if (m_endSelectionLine < 0)
			{
				m_endSelectionLine = m_startSelectionLine = m_endSelectionPos = m_startSelectionPos = 0;
				update();
				return false;
			}

			iStartPosition = m_pModel->lineAt(m_endSelectionLine)->string().length();
		}

		for (int i = m_endSelectionLine; i > -1; i--)
		{
			QString strLine = m_pModel->lineAt(i)->string();
			iIndex = strLine.lastIndexOf(searchString, iStartPosition, caseSensivity);
			if (iIndex != -1)
			{
				iLineNumber = i;
				break;
			}

			if (i > 0)
			{
				iStartPosition = m_pModel->lineAt(i - 1)->string().length() - 1;
			}
		}
	}
	else
	{
		iStartPosition++;

		if (m_startSelectionPos == m_endSelectionPos && m_startSelectionLine == m_endSelectionLine)
		{
			m_startSelectionLine = m_endSelectionLine = m_startSelectionPos = m_endSelectionPos = 0;
			iStartPosition = 0;
		}

		for (int i = m_startSelectionLine; i < m_pModel->linesCount(); i++)
		{
			iIndex = m_pModel->lineAt(i)->string().indexOf(searchString, iStartPosition, caseSensivity);
			if (iIndex != -1)
			{
				iLineNumber = i;
				break;
			}

			iStartPosition = 0;
		}
	}

	if (iLineNumber != -1)
	{
		m_startSelectionLine = m_endSelectionLine = iLineNumber;
		m_startSelectionPos = iIndex;
		m_endSelectionPos = iIndex + searchString.length();

		update();

		int scrollPos = m_fontHeight * iLineNumber;
		m_pScrollArea->verticalScrollBar()->setValue(scrollPos);

		return true;
	}
	else
	{
		m_endSelectionLine = m_startSelectionLine = m_endSelectionPos = m_startSelectionPos = 0;
		update();
	}

	return false;
}

QFontMetrics& CustomTextViewWidget::getFontMetrics(int lineNumber)
{
	return m_pModel->lineAt(lineNumber)->isBold() ? m_boldFontMetrics : m_fontMetrics;
}

void CustomTextViewWidget::onModelUpdated()
{
	m_startSelectionLine = m_startSelectionPos = m_endSelectionLine = m_endSelectionPos = 0;

	int iLongestLineIndex = m_pModel->longestStringIndex();

	if (iLongestLineIndex > -1)
	{
		QFontMetrics fontMetrics = getFontMetrics(iLongestLineIndex);
		m_width = fontMetrics.width(m_pModel->lineAt(iLongestLineIndex)->string()) + 70;
	}
	else
	{
		m_width = 0;
	}

	update();
	adjustSize();
}

QList<CustomTextViewSearchLine*> CustomTextViewWidget::searchAll(const QString& title, const QString& searchString, bool bCaseSens)
{
	return m_pModel->searchAll(title, searchString, bCaseSens, m_iId);
}

void CustomTextViewWidget::setSelection(uint iLine, uint iStart, uint iEnd)
{
	m_startSelectionLine = m_endSelectionLine = iLine;
	m_startSelectionPos = iStart;
	m_endSelectionPos = iEnd;

	int scrollPos = m_fontHeight * iLine;
	m_pScrollArea->verticalScrollBar()->setValue(scrollPos);

	update();
}

