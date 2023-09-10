
// CalculatorDlg.h : header file
//

#pragma once


// CCalculatorDlg dialog
class CCalculatorDlg : public CDialogEx
{
// Construction
public:
	CCalculatorDlg(CWnd* pParent = nullptr);	// standard constructor

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
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedBtnOne();
	CString m_EditResult;
	CString m_CombineNumber;
	int m_iFirstNumber;
	CString m_sFirstNumber;
	CEdit m_EditControlResult;
	CString m_Operation;
	int m_iPreviousid;
	afx_msg void OnBnClickedBtnTwo();
	afx_msg void OnBnClickedBtnThree();
	afx_msg void OnBnClickedBtnFour();
	afx_msg void OnBnClickedBtnFive();
	afx_msg void OnBnClickedBtnSix();
	afx_msg void OnBnClickedBtnSeven();
	afx_msg void OnBnClickedBtnEight();
	afx_msg void OnBnClickedBtnNine();
	afx_msg void OnBnClickedBtnAdd();
	afx_msg void OnBnClickedBtnZero();
	afx_msg void OnBnClickedBtnEqual();
	afx_msg void OnBnClickedBtnAc();
	afx_msg void OnBnClickedBtnSubtract();
	afx_msg void OnBnClickedBtnDivision();
	afx_msg void OnBnClickedBtnMultiply();
	afx_msg void OnBnClickedBtnPositiveNegetive();
	int OperationSelect();
	afx_msg void OnBnClickedBtnPercentage();
	void setFontStyle(int id);
	CButton m_btnOne;
	CFont m_font;
	bool flag;
	void ClearPreviousResult();
};
