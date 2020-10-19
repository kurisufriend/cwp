#pragma once
#include <Windows.h>
#include <iostream>

namespace hooks
{
	//https://docs.microsoft.com/en-us/previous-versions/windows/desktop/legacy/ms633573(v=vs.85)
	LRESULT CALLBACK hkWndProc(HWND handle, UINT message, WPARAM wParam, LPARAM lParam);
	bool setup();
	bool destroy();
}