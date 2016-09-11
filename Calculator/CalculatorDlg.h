
// CalculatorDlg.h : header file
//

#pragma once
#include "afxwin.h"
#include "Calculator.h"
#include "afxext.h"
#include "CalculatorButton.h"


// CalculatorDlg dialog
class CalculatorDlg : public CDialogEx
{
// Construction
public:
	CalculatorDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_CALCULATOR_DIALOG };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support


// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	virtual BOOL OnInitDialog();
	void OnInput(UINT nChar);
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	CFont m_resultFont;
	CFont m_buttonFont;
	CEdit m_editResult;
	CString m_output;
	Calculator m_calculator;
	CalculatorButton m_button0;
	CalculatorButton m_button1;
	CalculatorButton m_button2;
	CalculatorButton m_button3;
	CalculatorButton m_button4;
	CalculatorButton m_button5;
	CalculatorButton m_button6;
	CalculatorButton m_button7;
	CalculatorButton m_button8;
	CalculatorButton m_button9;
	CalculatorButton m_buttonAdd;
	CalculatorButton m_buttonC;
	CalculatorButton m_buttonCe;
	CalculatorButton m_buttonDelete;
	CalculatorButton m_buttonDiv;
	CalculatorButton m_buttonEqual;
	CalculatorButton m_buttonMinus;
	CalculatorButton m_buttonMul;
	CalculatorButton m_buttonPlusMinus;
	CalculatorButton m_buttonPoint;

	void OnBnClickedNum0();
	void OnBnClickedNum1();
	void OnBnClickedNum2();
	void OnBnClickedNum3();
	void OnBnClickedNum4();
	void OnBnClickedNum5();
	void OnBnClickedNum6();
	void OnBnClickedNum7();
	void OnBnClickedNum8();
	void OnBnClickedNum9();
	void OnBnClickedPlusMinus();
	void OnBnClickedPoint();
	void OnBnClickedEqual();
	void OnBnClickedAdd();
	void OnBnClickedMinus();
	void OnBnClickedMul();
	void OnBnClickedCe();
	void OnBnClickedC();
	void OnBnClickedDelete();
	void OnBnClickedDiv();
	
	void enterDigit(char digit);
	void enterOperation(Calculator::CalcOp oper);
	void enterNegate();
	void enterEqual();
	void enterC();
	void enterCE();
	void enterDelete();
	virtual BOOL PreTranslateMessage(MSG* pMsg);

};
