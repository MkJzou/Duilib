#ifndef MAINFRAME_HPP
#define MAINFRAME_HPP

#include "UIlib.h"


namespace DuiLib
{

class MainFrame : public WindowImplBase
{
public:

	MainFrame();
	~MainFrame();

public:

	LPCTSTR GetWindowClassName() const;	
	virtual CDuiString GetSkinFolder();
	virtual CDuiString GetSkinFile();
	virtual CDuiString GetZIPFileName() const;
	virtual UILIB_RESOURCETYPE GetResourceType() const;

public:

	virtual void InitWindow();
	virtual void OnFinalMessage(HWND hWnd);
	virtual void Notify( TNotifyUI &msg );
};

}
#endif // MAINFRAME_HPP