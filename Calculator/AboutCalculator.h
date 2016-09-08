#pragma once


// AboutCalculator dialog

class AboutCalculator : public CDialogEx
{
	DECLARE_DYNAMIC(AboutCalculator)

public:
	AboutCalculator(CWnd* pParent = NULL);   // standard constructor
	virtual ~AboutCalculator();

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ABOUTBOX };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
};
