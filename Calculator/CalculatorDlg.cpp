
// CalculatorDlg.cpp : implementation file
//

#include "stdafx.h"
#include "CalculatorApp.h"
#include "CalculatorDlg.h"
#include "afxdialogex.h"
#include <string>
#include <sstream>

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CAboutDlg dialog used for App About

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ABOUTBOX };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

// Implementation
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialogEx(IDD_ABOUTBOX)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()


// CalculatorDlg dialog



CalculatorDlg::CalculatorDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_CALCULATOR_DIALOG, pParent)
	, m_output(_T("0"))
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CalculatorDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_RESULT_EDIT, m_editResult);
	DDX_Control(pDX, IDC_BUTTON1, m_button1);
	DDX_Control(pDX, IDC_BUTTON2, m_button2);
	DDX_Control(pDX, IDC_BUTTON3, m_button3);
	DDX_Control(pDX, IDC_BUTTON4, m_button4);
	DDX_Control(pDX, IDC_BUTTON5, m_button5);
	DDX_Control(pDX, IDC_BUTTON6, m_button6);
	DDX_Control(pDX, IDC_BUTTON7, m_button7);
	DDX_Control(pDX, IDC_BUTTON8, m_button8);
	DDX_Control(pDX, IDC_BUTTON9, m_button9);
	DDX_Control(pDX, IDC_BUTTON0, m_button0);
	DDX_Control(pDX, IDC_BUTTON_ADD, m_buttonAdd);
	DDX_Control(pDX, IDC_BUTTON_C, m_buttonC);
	DDX_Control(pDX, IDC_BUTTON_CE, m_buttonCe);
	DDX_Control(pDX, IDC_BUTTON_DELETE, m_buttonDelete);
	DDX_Control(pDX, IDC_BUTTON_DIV, m_buttonDiv);
	DDX_Control(pDX, IDC_BUTTON_EQUAL, m_buttonEqual);
	DDX_Control(pDX, IDC_BUTTON_MINUS, m_buttonMinus);
	DDX_Control(pDX, IDC_BUTTON_MUL, m_buttonMul);
	DDX_Control(pDX, IDC_BUTTON_PLUSMINUS, m_buttonPlusMinus);
	DDX_Control(pDX, IDC_BUTTON_POINT, m_buttonPoint);
	DDX_Text(pDX, IDC_RESULT_EDIT, m_output);
}

BEGIN_MESSAGE_MAP(CalculatorDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_WM_SYSKEYDOWN()
	ON_WM_KEYDOWN()
	ON_BN_CLICKED(IDC_BUTTON_PLUSMINUS, &CalculatorDlg::OnBnClickedPlusMinus)
	ON_BN_CLICKED(IDC_BUTTON0, &CalculatorDlg::OnBnClickedNum0)
	ON_BN_CLICKED(IDC_BUTTON_POINT, &CalculatorDlg::OnBnClickedPoint)
	ON_BN_CLICKED(IDC_BUTTON_EQUAL, &CalculatorDlg::OnBnClickedEqual)
	ON_BN_CLICKED(IDC_BUTTON1, &CalculatorDlg::OnBnClickedNum1)
	ON_BN_CLICKED(IDC_BUTTON2, &CalculatorDlg::OnBnClickedNum2)
	ON_BN_CLICKED(IDC_BUTTON3, &CalculatorDlg::OnBnClickedNum3)
	ON_BN_CLICKED(IDC_BUTTON_ADD, &CalculatorDlg::OnBnClickedAdd)
	ON_BN_CLICKED(IDC_BUTTON4, &CalculatorDlg::OnBnClickedNum4)
	ON_BN_CLICKED(IDC_BUTTON5, &CalculatorDlg::OnBnClickedNum5)
	ON_BN_CLICKED(IDC_BUTTON6, &CalculatorDlg::OnBnClickedNum6)
	ON_BN_CLICKED(IDC_BUTTON_MINUS, &CalculatorDlg::OnBnClickedMinus)
	ON_BN_CLICKED(IDC_BUTTON7, &CalculatorDlg::OnBnClickedNum7)
	ON_BN_CLICKED(IDC_BUTTON8, &CalculatorDlg::OnBnClickedNum8)
	ON_BN_CLICKED(IDC_BUTTON9, &CalculatorDlg::OnBnClickedNum9)
	ON_BN_CLICKED(IDC_BUTTON_MUL, &CalculatorDlg::OnBnClickedMul)
	ON_BN_CLICKED(IDC_BUTTON_CE, &CalculatorDlg::OnBnClickedCe)
	ON_BN_CLICKED(IDC_BUTTON_C, &CalculatorDlg::OnBnClickedC)
	ON_BN_CLICKED(IDC_BUTTON_DELETE, &CalculatorDlg::OnBnClickedDelete)
	ON_BN_CLICKED(IDC_BUTTON_DIV, &CalculatorDlg::OnBnClickedDiv)
	ON_WM_CLOSE()
	ON_WM_DRAWITEM()
END_MESSAGE_MAP()


// CalculatorDlg message handlers

BOOL CalculatorDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// Add "About..." menu item to system menu.

	// IDM_ABOUTBOX must be in the system command range.
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
	{
		BOOL bNameValid;
		CString strAboutMenu;
		bNameValid = strAboutMenu.LoadString(IDS_ABOUTBOX);
		ASSERT(bNameValid);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// Set the icon for this dialog.  The framework does this automatically
	//  when the application's main window is not a dialog
	SetIcon(m_hIcon, TRUE);			// Set big icon
	SetIcon(m_hIcon, FALSE);		// Set small icon

	m_resultFont.CreateFont(40, 0, 0, 0, FW_BLACK, 0, 0, 0, DEFAULT_CHARSET,
		0, 0, 0, 0, _T("Consolas"));
	m_buttonFont.CreateFont(32, 0, 0, 0, ASFW_ANY, 0, 0, 0, DEFAULT_CHARSET,
		0, 0, 0, 0, _T("Consolas"));
	m_editResult.SetFont(&m_resultFont);
	m_button0.SetFont(&m_buttonFont);
	m_button1.SetFont(&m_buttonFont);
	m_button2.SetFont(&m_buttonFont);
	m_button3.SetFont(&m_buttonFont);
	m_button4.SetFont(&m_buttonFont);
	m_button5.SetFont(&m_buttonFont);
	m_button6.SetFont(&m_buttonFont);
	m_button7.SetFont(&m_buttonFont);
	m_button8.SetFont(&m_buttonFont);
	m_button9.SetFont(&m_buttonFont);
	m_buttonC.SetFont(&m_buttonFont);
	m_buttonCe.SetFont(&m_buttonFont);
	m_buttonAdd.SetFont(&m_buttonFont);
	m_buttonC.SetFont(&m_buttonFont);
	m_buttonMinus.SetFont(&m_buttonFont);
	m_buttonMul.SetFont(&m_buttonFont);
	m_buttonDiv.SetFont(&m_buttonFont);
	m_buttonEqual.SetFont(&m_buttonFont);
	m_buttonDelete.SetFont(&m_buttonFont);
	m_buttonPlusMinus.SetFont(&m_buttonFont);
	m_buttonPoint.SetFont(&m_buttonFont);

	return TRUE;  // return TRUE  unless you set the focus to a control
}

void CalculatorDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialogEx::OnSysCommand(nID, lParam);
	}
}

// If you add a minimize button to your dialog, you will need the code below
//  to draw the icon.  For MFC applications using the document/view model,
//  this is automatically done for you by the framework.

void CalculatorDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // device context for painting

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// Center icon in client rectangle
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// Draw the icon
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

// The system calls this function to obtain the cursor to display while the user drags
//  the minimized window.
HCURSOR CalculatorDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}

void CalculatorDlg::OnInput(UINT nChar)
{
	if (nChar >= 96 && nChar <= 105)
	{
		enterDigit(nChar-48);
	}
	switch (nChar) {
		case 110:
			enterDigit('.');
			break;
		case 107:
			enterOperation(Calculator::CalcOp::Add);
			break;
		case 109:
			enterOperation(Calculator::CalcOp::Substract);
			break;
		case 106:
			enterOperation(Calculator::CalcOp::Multiply);
			break;
		case 111:
			enterOperation(Calculator::CalcOp::Divide);
			break;
		case 8:
			enterDelete();
			break;
		case 13:
			enterEqual();
			break;
	}
}

void CalculatorDlg::enterDigit(char digit)
{
	UpdateData(TRUE);
	if (m_calculator.getCurrentState() == Calculator::CalcState::Start )
	{
		m_output = '0';
		m_calculator.setCurrentState(Calculator::CalcState::Operand_1);
	}
	else if (m_calculator.getCurrentState() == Calculator::CalcState::Operator)
	{
		m_calculator.setCurrentState(Calculator::CalcState::Operand_2);
		m_output = '0';
	}
	if (m_calculator.getCurrentState() == Calculator::CalcState::Operand_1 ||
		m_calculator.getCurrentState() == Calculator::CalcState::Negate_1 ||
		m_calculator.getCurrentState() == Calculator::CalcState::Operand_2 ||
		m_calculator.getCurrentState() == Calculator::CalcState::Negate_2)
	{
		if (digit == '.' && (m_output.Find('.') == -1)) {
			m_output += digit;
		}
		else if (m_output == "0" && digit != '.')
		{
			m_output = digit;
		}
		else if (m_output != "0" && digit != '.')
		{
			m_output += digit;
		}
	}
	UpdateData(FALSE);
}

void CalculatorDlg::enterOperation(Calculator::CalcOp oper)
{
	if (m_calculator.getCurrentState() == Calculator::CalcState::Error)
	{
		return;
	}
	if (m_calculator.getCurrentState() == Calculator::CalcState::Start ||
		m_calculator.getCurrentState() == Calculator::CalcState::Negate_1 ||
		m_calculator.getCurrentState() == Calculator::CalcState::Operand_1)
	{
		m_calculator.setOperand_1(_wtof(m_output));
	}
	else if (m_calculator.getCurrentState() == Calculator::CalcState::Operand_2 ||
		m_calculator.getCurrentState() == Calculator::CalcState::Negate_2)
	{
		m_calculator.setOperand_2(_wtof(m_output));
		UpdateData(TRUE);
		std::stringstream ss;
		ss << m_calculator.getResult();
		m_output = ss.str().c_str();
		UpdateData(FALSE);
		m_calculator.setCurrentState(Calculator::CalcState::Start);
		m_calculator.setOperand_1(m_calculator.getResult());
	}
	m_calculator.setCurrentState(Calculator::CalcState::Operator);
	m_calculator.setOperator(oper);
}

void CalculatorDlg::enterNegate()
{
	if (m_calculator.getCurrentState() == Calculator::CalcState::Operand_1)
	{
		m_calculator.setCurrentState(Calculator::CalcState::Negate_1);
		UpdateData(TRUE);
		m_output = '-' + m_output;
		UpdateData(FALSE);
	}
	else if (m_calculator.getCurrentState() == Calculator::CalcState::Operand_2)
	{
		m_calculator.setCurrentState(Calculator::CalcState::Negate_2);
		UpdateData(TRUE);
		m_output = '-' + m_output;
		UpdateData(FALSE);
	}
	else if (m_calculator.getCurrentState() == Calculator::CalcState::Negate_1)
	{
		m_calculator.setCurrentState(Calculator::CalcState::Operand_1);
		UpdateData(TRUE);
		m_output = m_output.Right(m_output.GetLength()-1);
		UpdateData(FALSE); 
	}
	else if (m_calculator.getCurrentState() == Calculator::CalcState::Negate_2)
	{
		m_calculator.setCurrentState(Calculator::CalcState::Operand_2);
		UpdateData(TRUE);
		m_output = m_output.Right(m_output.GetLength() - 1);
		UpdateData(FALSE);
	}
}

void CalculatorDlg::enterEqual()
{
	if (m_calculator.getCurrentState() == Calculator::CalcState::Negate_2 ||
		m_calculator.getCurrentState() == Calculator::CalcState::Operand_2)
	{
		UpdateData(TRUE);
		try {
			m_calculator.setOperand_2(_wtof(m_output));
			std::stringstream ss;
			ss << m_calculator.getResult();
			m_output = ss.str().c_str();
			m_calculator.setCurrentState(Calculator::CalcState::Start);
		}
		catch (std::exception& e)
		{
			m_output = e.what();
			m_calculator.setCurrentState(Calculator::CalcState::Error);
		}
		UpdateData(FALSE);
		
	}
}

void CalculatorDlg::enterC()
{
	m_calculator.reset();
	UpdateData(TRUE);
	m_output = '0';
	UpdateData(FALSE);
}

void CalculatorDlg::enterCE()
{
	if (m_calculator.getCurrentState() == Calculator::CalcState::Start ||
		m_calculator.getCurrentState() == Calculator::CalcState::Operand_1 ||
		m_calculator.getCurrentState() == Calculator::CalcState::Negate_1)
	{
		m_calculator.setCurrentState(Calculator::CalcState::Start);
		UpdateData(TRUE);
		m_output = '0';
		UpdateData(FALSE);
		m_calculator.setOperand_1(0);
	}
	else if (m_calculator.getCurrentState() == Calculator::CalcState::Operand_2 ||
		m_calculator.getCurrentState() == Calculator::CalcState::Negate_2)
	{
		m_calculator.setCurrentState(Calculator::CalcState::Operator);
		UpdateData(TRUE);
		m_output = '0';
		UpdateData(FALSE);
		m_calculator.setOperand_2(0);
	}
}

void CalculatorDlg::enterDelete()
{
	if (m_calculator.getCurrentState() == Calculator::CalcState::Operand_1 ||
		m_calculator.getCurrentState() == Calculator::CalcState::Negate_1||
		m_calculator.getCurrentState() == Calculator::CalcState::Operand_2||
		m_calculator.getCurrentState() == Calculator::CalcState::Negate_2)
	{
		UpdateData(TRUE);
		m_output = m_output.Left(m_output.GetLength() - 1);
		if(m_output.GetLength()==0)
		{
			m_output = '0';
		}
		UpdateData(FALSE);
	}
}

void CalculatorDlg::OnBnClickedNum0()
{
	enterDigit('0');
}

void CalculatorDlg::OnBnClickedNum1()
{
	enterDigit('1');
}

void CalculatorDlg::OnBnClickedNum2()
{
	enterDigit('2');
}

void CalculatorDlg::OnBnClickedNum3()
{
	enterDigit('3');
}

void CalculatorDlg::OnBnClickedNum4()
{
	enterDigit('4');
}

void CalculatorDlg::OnBnClickedNum5()
{
	enterDigit('5');
}

void CalculatorDlg::OnBnClickedNum6()
{
	enterDigit('6');
}

void CalculatorDlg::OnBnClickedNum7()
{
	enterDigit('7');
}

void CalculatorDlg::OnBnClickedNum8()
{
	enterDigit('8');
}

void CalculatorDlg::OnBnClickedNum9()
{
	enterDigit('9');
}

void CalculatorDlg::OnBnClickedPoint()
{
	enterDigit('.');
}

void CalculatorDlg::OnBnClickedPlusMinus()
{
	enterNegate();
}

void CalculatorDlg::OnBnClickedEqual()
{
	enterEqual();
}
void CalculatorDlg::OnBnClickedAdd()
{
	enterOperation(Calculator::CalcOp::Add);
}
void CalculatorDlg::OnBnClickedMinus()
{
	enterOperation(Calculator::CalcOp::Substract);
}
void CalculatorDlg::OnBnClickedMul()
{
	enterOperation(Calculator::CalcOp::Multiply);
}

void CalculatorDlg::OnBnClickedDiv()
{
	enterOperation(Calculator::CalcOp::Divide);
}

void CalculatorDlg::OnBnClickedCe()
{
	enterCE();
}
void CalculatorDlg::OnBnClickedC()
{
	enterC();
}
void CalculatorDlg::OnBnClickedDelete()
{
	enterDelete();
}


BOOL CalculatorDlg::PreTranslateMessage(MSG* pMsg)
{
	
	if (pMsg->message == WM_KEYDOWN)
	{
		OnInput(pMsg->wParam);
		return TRUE;
	}
	return CDialogEx::PreTranslateMessage(pMsg);
}
