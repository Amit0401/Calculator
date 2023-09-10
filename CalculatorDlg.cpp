
// CalculatorDlg.cpp : implementation file
//

#include "pch.h"
#include "framework.h"
#include "Calculator.h"
#include "CalculatorDlg.h"
#include "afxdialogex.h"

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


// CCalculatorDlg dialog



CCalculatorDlg::CCalculatorDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_CALCULATOR_DIALOG, pParent)
	, m_EditResult(_T("0"))
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
	m_iPreviousid = -1;
	flag = false;
}

void CCalculatorDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT_RESULT, m_EditResult);
	DDX_Control(pDX, IDC_EDIT_RESULT, m_EditControlResult);
	DDX_Control(pDX, IDC_BTN_ONE, m_btnOne);
}

BEGIN_MESSAGE_MAP(CCalculatorDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BTN_ONE, &CCalculatorDlg::OnBnClickedBtnOne)
	ON_BN_CLICKED(IDC_BTN_TWO, &CCalculatorDlg::OnBnClickedBtnTwo)
	ON_BN_CLICKED(IDC_BTN_THREE, &CCalculatorDlg::OnBnClickedBtnThree)
	ON_BN_CLICKED(IDC_BTN_FOUR, &CCalculatorDlg::OnBnClickedBtnFour)
	ON_BN_CLICKED(IDC_BTN_FIVE, &CCalculatorDlg::OnBnClickedBtnFive)
	ON_BN_CLICKED(IDC_BTN_SIX, &CCalculatorDlg::OnBnClickedBtnSix)
	ON_BN_CLICKED(IDC_BTN_SEVEN, &CCalculatorDlg::OnBnClickedBtnSeven)
	ON_BN_CLICKED(IDC_BTN_EIGHT, &CCalculatorDlg::OnBnClickedBtnEight)
	ON_BN_CLICKED(IDC_BTN_NINE, &CCalculatorDlg::OnBnClickedBtnNine)
	ON_BN_CLICKED(IDC_BTN_ADD, &CCalculatorDlg::OnBnClickedBtnAdd)
	ON_BN_CLICKED(IDC_BTN_ZERO, &CCalculatorDlg::OnBnClickedBtnZero)
	ON_BN_CLICKED(IDC_BTN_EQUAL, &CCalculatorDlg::OnBnClickedBtnEqual)
	ON_BN_CLICKED(IDC_BTN_AC, &CCalculatorDlg::OnBnClickedBtnAc)
	ON_BN_CLICKED(IDC_BTN_SUBTRACT, &CCalculatorDlg::OnBnClickedBtnSubtract)
	ON_BN_CLICKED(IDC_BTN_DIVISION, &CCalculatorDlg::OnBnClickedBtnDivision)
	ON_BN_CLICKED(IDC_BTN_MULTIPLY, &CCalculatorDlg::OnBnClickedBtnMultiply)
	ON_BN_CLICKED(IDC_BTN_POSITIVE_NEGETIVE, &CCalculatorDlg::OnBnClickedBtnPositiveNegetive)
	ON_BN_CLICKED(IDC_BTN_PERCENTAGE, &CCalculatorDlg::OnBnClickedBtnPercentage)
END_MESSAGE_MAP()


// CCalculatorDlg message handlers

BOOL CCalculatorDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// Add "About..." menu item to system menu.

	// IDM_ABOUTBOX must be in the system command range.
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != nullptr)
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

	// TODO: Add extra initialization here

	return TRUE;  // return TRUE  unless you set the focus to a control
}

void CCalculatorDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void CCalculatorDlg::OnPaint()
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
HCURSOR CCalculatorDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CCalculatorDlg::OnBnClickedBtnOne()
{
	// TODO: Add your control notification handler code here
	ClearPreviousResult();
	m_iFirstNumber = 1;
	if (m_EditResult == L"0")
		m_EditResult.Format(_T("%d"), m_iFirstNumber);
	else
	{
			m_CombineNumber.Format(_T("%d"), m_iFirstNumber);
			m_EditResult += m_CombineNumber;
	}
	UpdateData(FALSE);
}
void CCalculatorDlg::ClearPreviousResult()
{
	if (flag)
	{
		OnBnClickedBtnAc();
		flag = false;
	}
}
void CCalculatorDlg::setFontStyle(int id)
{
		CWnd* ptr = GetDlgItem(id);
		CFont* font = ptr->GetFont();
		LOGFONT logFont;
		font->GetLogFont(&logFont);
		logFont.lfHeight = 40;
		logFont.lfWeight = FW_EXTRABOLD;
		m_font.CreateFontIndirect(&logFont);
		ptr->SetFont(&m_font);
		ptr->SetFont(font);
}
void CCalculatorDlg::OnBnClickedBtnTwo()
{
	// TODO: Add your control notification handler code here
	ClearPreviousResult();
	m_iFirstNumber = 2;
	if (m_EditResult == L"0")
		m_EditResult.Format(_T("%d"), m_iFirstNumber);
	else
	{
		m_CombineNumber.Format(_T("%d"), m_iFirstNumber);
		m_EditResult += m_CombineNumber;
	}
	UpdateData(FALSE);
}


void CCalculatorDlg::OnBnClickedBtnThree()
{
	// TODO: Add your control notification handler code here
	ClearPreviousResult();
	m_iFirstNumber = 3;
	if (m_EditResult == L"0")
		m_EditResult.Format(_T("%d"), m_iFirstNumber);
	else
	{
		m_CombineNumber.Format(_T("%d"), m_iFirstNumber);
		m_EditResult += m_CombineNumber;
	}
	UpdateData(FALSE);
}


void CCalculatorDlg::OnBnClickedBtnFour()
{
	// TODO: Add your control notification handler code here
	ClearPreviousResult();
	m_iFirstNumber = 4;
	if (m_EditResult == L"0")
		m_EditResult.Format(_T("%d"), m_iFirstNumber);
	else
	{
		m_CombineNumber.Format(_T("%d"), m_iFirstNumber);
		m_EditResult += m_CombineNumber;
	}
	UpdateData(FALSE);
}


void CCalculatorDlg::OnBnClickedBtnFive()
{
	// TODO: Add your control notification handler code here
	ClearPreviousResult();
	m_iFirstNumber = 5;
	if (m_EditResult == L"0")
		m_EditResult.Format(_T("%d"), m_iFirstNumber);
	else
	{
		m_CombineNumber.Format(_T("%d"), m_iFirstNumber);
		m_EditResult += m_CombineNumber;
	}
	UpdateData(FALSE);
}


void CCalculatorDlg::OnBnClickedBtnSix()
{
	// TODO: Add your control notification handler code here
	ClearPreviousResult();
	m_iFirstNumber = 6;
	if (m_EditResult == L"0")
		m_EditResult.Format(_T("%d"), m_iFirstNumber);
	else
	{
		m_CombineNumber.Format(_T("%d"), m_iFirstNumber);
		m_EditResult += m_CombineNumber;
	}
	UpdateData(FALSE);
}


void CCalculatorDlg::OnBnClickedBtnSeven()
{
	// TODO: Add your control notification handler code here
	ClearPreviousResult();
	m_iFirstNumber = 7;
	if (m_EditResult == L"0")
		m_EditResult.Format(_T("%d"), m_iFirstNumber);
	else
	{
		m_CombineNumber.Format(_T("%d"), m_iFirstNumber);
		m_EditResult += m_CombineNumber;
	}
	UpdateData(FALSE);
}


void CCalculatorDlg::OnBnClickedBtnEight()
{
	// TODO: Add your control notification handler code here
	ClearPreviousResult();
	m_iFirstNumber = 8;
	if (m_EditResult == L"0")
		m_EditResult.Format(_T("%d"), m_iFirstNumber);
	else
	{
		m_CombineNumber.Format(_T("%d"), m_iFirstNumber);
		m_EditResult += m_CombineNumber;
	}
	UpdateData(FALSE);
}


void CCalculatorDlg::OnBnClickedBtnNine()
{
	// TODO: Add your control notification handler code here
	ClearPreviousResult();
	m_iFirstNumber = 9;
	if (m_EditResult == L"0")
		m_EditResult.Format(_T("%d"), m_iFirstNumber);
	else
	{
		m_CombineNumber.Format(_T("%d"), m_iFirstNumber);
		m_EditResult += m_CombineNumber;
	}
	UpdateData(FALSE);
}


void CCalculatorDlg::OnBnClickedBtnAdd()
{
	// TODO: Add your control notification handler code here
	m_sFirstNumber = m_EditResult;
	m_EditResult = L"0";
	m_Operation = L"+";
	UpdateData(FALSE);
}


void CCalculatorDlg::OnBnClickedBtnZero()
{
	// TODO: Add your control notification handler code here
	ClearPreviousResult();
	m_iFirstNumber = 0;
	if (m_EditResult == L"0")
		m_EditResult.Format(_T("%d"), m_iFirstNumber);
	else
	{
		m_CombineNumber.Format(_T("%d"), m_iFirstNumber);
		m_EditResult += m_CombineNumber;
	}
	UpdateData(FALSE);
}
int CCalculatorDlg::OperationSelect()
{

	return 1;
}

void CCalculatorDlg::OnBnClickedBtnEqual()
{
	// TODO: Add your control notification handler code here
	//int test = OperationSelect();
	int First = _wtoi(m_sFirstNumber);
	int Second = _wtoi(m_EditResult);
	int Result = 0;
	float DivResult;
	if (m_Operation == L"+")
	{
		Result = First + Second;
		m_EditResult.Format(_T("%d"), Result);
	}
	else if (m_Operation == L"-")
	{
		Result = First - Second;
		m_EditResult.Format(_T("%d"), Result);
	}
	else if (m_Operation == L"*")
	{
		Result = First * Second;
		m_EditResult.Format(_T("%d"), Result);
	}
	else if (m_Operation == L"/")
	{
		if (Second != 0)
		{
			DivResult = First /(float)Second;
			m_EditResult.Format(_T("%f"), DivResult);
		}
		else
		{
			m_EditResult.Format(L"Invalid");
		}
	}
	flag = true;
	UpdateData(FALSE);
}


void CCalculatorDlg::OnBnClickedBtnAc()
{
	// TODO: Add your control notification handler code here
	m_EditResult = L"";
	UpdateData(FALSE);
}


void CCalculatorDlg::OnBnClickedBtnSubtract()
{
	// TODO: Add your control notification handler code here
	m_sFirstNumber = m_EditResult;
	m_EditResult = L"0";
	m_Operation = L"-";
	UpdateData(FALSE);
}


void CCalculatorDlg::OnBnClickedBtnDivision()
{
	// TODO: Add your control notification handler code here
	m_sFirstNumber = m_EditResult;
	m_EditResult = L"0";
	m_Operation = L"/";
}


void CCalculatorDlg::OnBnClickedBtnMultiply()
{
	// TODO: Add your control notification handler code here
	m_sFirstNumber = m_EditResult;
	m_EditResult = L"0";
	m_Operation = L"*";
}


void CCalculatorDlg::OnBnClickedBtnPositiveNegetive()
{
	// TODO: Add your control notification handler code here
	UpdateData();
	int PosNeg = _wtoi(m_EditResult);
    PosNeg *= -1;
	m_EditResult.Format(_T("%d"), PosNeg);
	UpdateData(FALSE);
}


void CCalculatorDlg::OnBnClickedBtnPercentage()
{
	// TODO: Add your control notification handler code here
	UpdateData();
	float Percentage = _wtof(m_EditResult);
	Percentage /=100;
	m_EditResult.Format(_T("%0.4f"),Percentage);
	UpdateData(FALSE);
}
