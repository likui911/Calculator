#include "stdafx.h"
#include "CalculatorButton.h"


CalculatorButton::CalculatorButton(void)
{
	m_TextColor = RGB(255, 255, 253);
}
CalculatorButton::~CalculatorButton(void)
{
}

void CalculatorButton::SetDownColor(COLORREF color)
{
	m_DownColor = color;
}
void CalculatorButton::SetUpColor(COLORREF color)
{
	m_UpColor = color;
}


void CalculatorButton::DrawItem(LPDRAWITEMSTRUCT lpDrawItemStruct)
{
	CDC dc;
	dc.Attach(lpDrawItemStruct->hDC);

	ASSERT(lpDrawItemStruct->CtlType == ODT_BUTTON);

	CString strText;
	GetWindowText(strText);
	if (lpDrawItemStruct->itemState &ODS_SELECTED)
	{
		CBrush brush(m_DownColor);
		dc.FillRect(&lpDrawItemStruct->rcItem, &brush);
		SetBkMode(lpDrawItemStruct->hDC, TRANSPARENT);

		SetTextColor(lpDrawItemStruct->hDC, m_TextColor);
		DrawText(lpDrawItemStruct->hDC, strText, strText.GetLength(),
			&lpDrawItemStruct->rcItem, DT_CENTER | DT_VCENTER | DT_SINGLELINE | DT_TABSTOP);
	}
	else
	{
		CBrush brush(m_UpColor);
		dc.FillRect(&lpDrawItemStruct->rcItem, &brush);
		SetBkMode(lpDrawItemStruct->hDC, TRANSPARENT);

		SetTextColor(lpDrawItemStruct->hDC, m_TextColor);
		DrawText(lpDrawItemStruct->hDC, strText, strText.GetLength(),
			&lpDrawItemStruct->rcItem, DT_CENTER | DT_VCENTER | DT_SINGLELINE | DT_TABSTOP);
	}
	if (lpDrawItemStruct->itemState &ODS_FOCUS)
	{
		COLORREF bkColor = GetBkColor(lpDrawItemStruct->hDC);
		COLORREF frameColor = RGB(255-GetRValue(bkColor), 255-GetGValue(bkColor),255- GetBValue(bkColor));
		CBrush brush(frameColor);
		dc.FrameRect(&lpDrawItemStruct->rcItem,&brush);
	}
	dc.Detach();

}