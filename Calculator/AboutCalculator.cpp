// AboutCalculator.cpp : implementation file
//

#include "stdafx.h"
#include "CalculatorApp.h"
#include "AboutCalculator.h"
#include "afxdialogex.h"


// AboutCalculator dialog

IMPLEMENT_DYNAMIC(AboutCalculator, CDialogEx)

AboutCalculator::AboutCalculator(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_ABOUTBOX, pParent)
{

}

AboutCalculator::~AboutCalculator()
{
}

void AboutCalculator::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(AboutCalculator, CDialogEx)
END_MESSAGE_MAP()


// AboutCalculator message handlers
