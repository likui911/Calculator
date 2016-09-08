
// CalculatorDlg.h : header file
//

#pragma once
#include "afxwin.h"
#include "Calculator.h"
#include "afxext.h"


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
	CButton m_button1;
	CButton m_button2;
	CButton m_button3;
	CButton m_button4;
	CButton m_button5;
	CButton m_button6;
	CButton m_button7;
	CButton m_button8;
	CButton m_button9;
	CButton m_button0;
	CButton m_buttonAdd;
	CButton m_buttonC;
	CButton m_buttonCe;
	CButton m_buttonDelete;
	CButton m_buttonDiv;
	CButton m_buttonEqual;
	CButton m_buttonMinus;
	CButton m_buttonMul;
	CButton m_buttonPlusMinus;
	CButton m_buttonPoint;
	CString m_output;
	Calculator m_calculator;
	
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
