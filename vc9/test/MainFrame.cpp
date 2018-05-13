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
	return  _T("");
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
	return UILIB_ZIP;
}

void MainFrame::InitWindow()
{}

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
	}

}