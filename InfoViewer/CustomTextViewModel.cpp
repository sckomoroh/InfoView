#include "CustomTextViewModel.h"

CustomTextViewModel::CustomTextViewModel(QObject* pParent)
	: QObject(pParent)
{
}

CustomTextViewModel::~CustomTextViewModel()
{
	for each (CustomTextViewLine* pLine in m_data)
	{
		delete pLine;
	}
}

void CustomTextViewModel::setModelData(const QList<CustomTextViewLine*>& data)
{
	m_data = data;

	updateModel();
}

void CustomTextViewModel::appendModelData(const QList<CustomTextViewLine*>& data)
{
	m_data.append(data);

	updateModel();
}

void CustomTextViewModel::clear()
{
	m_data.clear();

	updateModel();
}

int CustomTextViewModel::longestStringIndex()
{
	uint iMaxWidth = 0;
	uint iMaxWidthIndex = -1;
	uint iIndex = 0;
		
	for each(CustomTextViewLine* pLine in m_data)
	{
		uint iLineWidth = pLine->string().length();
		if (iLineWidth > iMaxWidth)
		{
			iMaxWidth = iLineWidth;
			iMaxWidthIndex = iIndex;
		}
	
		iIndex++;
	}
	
	return iMaxWidthIndex;
}

uint CustomTextViewModel::linesCount()
{
	return m_data.count();
}

void CustomTextViewModel::updateModel()
{
	emit modelUpdated();
}

QList<CustomTextViewSearchLine*> CustomTextViewModel::searchAll(const QString& title, const QString& searchString, bool bCaseSens, uint iLogId)
{
	QList<CustomTextViewSearchLine*> result;
	Qt::CaseSensitivity caseSens = bCaseSens ? Qt::CaseSensitive : Qt::CaseInsensitive;
	uint iLen = searchString.length();
	uint iLineNumber = 0;

	for each (CustomTextViewLine*  pLine in m_data)
	{
		int iIndex = 0;
		while (iIndex != -1)
		{
			iIndex = pLine->string().indexOf(searchString, iIndex, caseSens);
			if (iIndex != -1)
			{
				QString searchLine = QString("%1 (%2):%3").arg(title).arg(iLineNumber).arg(pLine->string());
				result.append(new CustomTextViewSearchLine(
					searchLine,
					iLineNumber,
					(uint)iIndex,
					iLogId,
					iLen));

				iIndex++;
			}
		}

		iLineNumber++;
	}

	if (!result.empty())
	{
		QString searchTitle = QString("Results for '%1' in %2 (%3)").arg(searchString).arg(title).arg(result.count() - 1);
		CustomTextViewSearchLine* pTitleSearchLine = new CustomTextViewSearchLine(searchTitle, 0, 0, iLogId, 0);
		pTitleSearchLine->setTitle(true);

		result.insert(0, pTitleSearchLine);
	}

	return result;
}
