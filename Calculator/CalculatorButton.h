#pragma once
#include "afxwin.h"
class CalculatorButton :public CButton
{
public:
	CalculatorButton();
	~CalculatorButton();
	void SetDownColor(COLORREF color);
	void SetUpColor(COLORREF color);

protected:
	virtual void DrawItem(LPDRAWITEMSTRUCT /*lpDrawItemStruct*/);

private:
	COLORREF m_TextColor, m_DownColor, m_UpColor;
};
