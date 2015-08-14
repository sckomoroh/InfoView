#pragma once

#include <QObject>
#include <QList>

#include "CustomTextViewLine.h"
#include "CustomTextViewSearchLine.h"

class CustomTextViewModel : public QObject
{
	Q_OBJECT
private:
	QList<CustomTextViewLine*> m_data;

public:
	CustomTextViewModel(QObject* pParent = 0);
	virtual ~CustomTextViewModel();

	inline CustomTextViewLine* lineAt(uint iLineIndex)
	{
		return m_data.at(iLineIndex);
	}

	void	setModelData(const QList<CustomTextViewLine*>& data);
	void	appendModelData(const QList<CustomTextViewLine*>& data);
	int		longestStringIndex();
	uint	linesCount();
	void	updateModel();
	void	clear();

	QList<CustomTextViewSearchLine*> searchAll(const QString& title, const QString& searchString, bool bCaseSens, uint iLogId);

signals:
	void modelUpdated();
};

