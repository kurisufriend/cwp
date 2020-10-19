#include "hooks.h"

WNDPROC oWndProc = nullptr;


//https://docs.microsoft.com/en-us/previous-versions/windows/desktop/legacy/ms633573(v=vs.85)
LRESULT CALLBACK hooks::hkWndProc(HWND handle, UINT message, WPARAM wParam, LPARAM lParam)
{
	static bool block = false;
	if (GetAsyncKeyState(VK_F9) & 0x1)
		block = !block;
	if (block)
		return 1;
	return CallWindowProcA(oWndProc, handle, message, wParam, lParam);
}

bool hooks::setup()
{
	//https://stackoverflow.com/questions/19705797/find-the-window-handle-for-a-chrome-browser
	oWndProc = (WNDPROC)(SetWindowLongPtr(FindWindow("Chrome_WidgetWin_1", NULL), GWLP_WNDPROC, (LONG)hkWndProc));
	if (!oWndProc)
		return false;
	return true;
}

bool hooks::destroy()
{
	SetWindowLongPtr(FindWindow("Chrome_WidgetWin_1", NULL), GWLP_WNDPROC, (LONG)oWndProc);
	return true;
}