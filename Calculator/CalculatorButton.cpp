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
	CRgn m_btnRgn;
	m_btnRgn.CreateRoundRectRgn(lpDrawItemStruct->rcItem.left, lpDrawItemStruct->rcItem.top,
		lpDrawItemStruct->rcItem.right, lpDrawItemStruct->rcItem.bottom, 9, 9);
	if (lpDrawItemStruct->itemState &ODS_SELECTED)
	{
		CBrush brush(m_DownColor);
		dc.FillRgn(&m_btnRgn, &brush);
		::SetBkMode(lpDrawItemStruct->hDC, TRANSPARENT);

		::SetTextColor(lpDrawItemStruct->hDC, m_TextColor);
		::DrawText(lpDrawItemStruct->hDC, strText, strText.GetLength(),
			&lpDrawItemStruct->rcItem, DT_CENTER | DT_VCENTER | DT_SINGLELINE | DT_TABSTOP);
	}
	else
	{
		CBrush brush(m_UpColor);
		dc.FillRgn(&m_btnRgn, &brush);
		::SetBkMode(lpDrawItemStruct->hDC, TRANSPARENT);

		::SetTextColor(lpDrawItemStruct->hDC, m_TextColor);
		::DrawText(lpDrawItemStruct->hDC, strText, strText.GetLength(),
			&lpDrawItemStruct->rcItem, DT_CENTER | DT_VCENTER | DT_SINGLELINE | DT_TABSTOP);
	}
	if (lpDrawItemStruct->itemState &ODS_FOCUS)
	{
		CBrush brush(RGB(0,90,130));
		dc.FrameRgn(&m_btnRgn,&brush,1,1);
		
	}
	m_btnRgn.DeleteObject();
	dc.Detach();

}