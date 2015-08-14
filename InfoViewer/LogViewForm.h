#ifndef LOBVIEWFORM_H
#define LOBVIEWFORM_H

#include <QWidget>
#include "ui_LogViewForm.h"

#include "logparserthread.h"
#include "CustomTextViewModel.h"

class LogViewForm : public QWidget
{
	Q_OBJECT
private:
	Ui::LogViewForm			ui;
	int						m_iIndex;
	QString					m_title;
	LogParserThread*		m_pParserThread;
	CustomTextViewModel*	m_pModel;
	bool					m_bDisableSearchNavigate;

public:
	LogViewForm(int iIndex, const QString& title, QWidget *parent = 0);
	~LogViewForm();

	void	loadFile(const QString& fileName);
	void	searchAll(const QString& searchString, bool bCaseSens);
	void	selectWord(uint iLine, uint iStartPos, uint iEndPos);
	void	setDisableSearchNavigate(bool bDisable);

	inline int index()
	{
		return m_iIndex;
	}

	inline bool	isSeachNavigateDisabled()
	{
		return m_bDisableSearchNavigate;
	}

private slots:
	void	onApplyButtonClicked();

	void	onSearchClicked();
	void	onSearchAllClicked();
	
	void	onCloseClicked();
	void	onShowSearchArea();

	void	onStartParse();
	void	onCompleteParse();

signals:
	void	searchAllRequest(const QString& searchString, bool bCaseSens);
	void	searchAllComplete(QList<CustomTextViewSearchLine*> searchResult);
};

#endif // LOBVIEWFORM_H
