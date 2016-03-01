
// PySampleDlg.h : 헤더 파일
//

#pragma once


// CPySampleDlg 대화 상자
class CPySampleDlg : public CDialogEx
{
// 생성입니다.
public:
	CPySampleDlg(CWnd* pParent = NULL);	// 표준 생성자입니다.

// 대화 상자 데이터입니다.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_PYSAMPLE_DIALOG };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV 지원입니다.


// 구현입니다.
protected:
	HICON m_hIcon;

	// 생성된 메시지 맵 함수
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedButton01();
	afx_msg void OnBnClickedButton02();
	afx_msg void OnBnClickedButton03();
	afx_msg void OnBnClickedButton04();
	afx_msg void OnBnClickedButton05();
	afx_msg void OnBnClickedButton06();
	afx_msg void OnBnClickedButton07();
	afx_msg void OnBnClickedButton08();
};
