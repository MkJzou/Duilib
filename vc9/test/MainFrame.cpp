#include "MainFrame.h"

using namespace DuiLib;

MainFrame::MainFrame()
{}

MainFrame::~MainFrame()
{
	PostQuitMessage(0);
}

LPCTSTR MainFrame::GetWindowClassName() const
{
	return _T("DuiTest");
}

CDuiString MainFrame::GetSkinFolder()
{
	return  _T("Make\\");
}

CDuiString MainFrame::GetSkinFile()
{
	return _T("00_MainFram.xml");
}

CDuiString MainFrame::GetZIPFileName() const
{
	return  _T("Make.a");
}

UILIB_RESOURCETYPE MainFrame::GetResourceType() const
{
	return UILIB_FILE;
}

void MainFrame::InitWindow()
{
    CContainerUI *pContainer = static_cast<CContainerUI*>(m_PaintManager.FindControl("MainFram_SubContainer"));

    CDialogBuilder builder;
    CControlUI* pControlUI = builder.Create("01_Login.xml");
    pContainer->Add(pControlUI);

    pControlUI = builder.Create("02_Connect.xml");
    pContainer->Add(pControlUI);
}

void MainFrame::OnFinalMessage(HWND hWnd)
{
	WindowImplBase::OnFinalMessage(hWnd);
	delete this;
}

void MainFrame::Notify( TNotifyUI &msg )
{
	CDuiString csType = msg.sType;
	CDuiString csName = msg.pSender->GetName();

	if(csType == DUI_MSGTYPE_CLICK)
	{
		if (csName == _T("Btn_Close")) 
		{	
			Close();
		}
		else if (csName == _T("Btn_Min")) {
			::ShowWindow(m_hWnd, SW_MINIMIZE);
		}
        else if (csName == _T("Btn_Login_Login")) {
            CContainerUI *pContainer = static_cast<CContainerUI*>(m_PaintManager.FindControl("MainFram_SubContainer"));
            pContainer->PageUp();
        }
	}

}