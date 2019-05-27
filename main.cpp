#include <windows.h>
#include <iostream>

int main(){
	typedef struct _RECT {
		LONG left;
		LONG top;
		LONG right;
		LONG bottom;
	} RECT;

	RECT aWsInfo;

	if (RegisterHotKey(
		NULL,
		1,
		MOD_SHIFT | MOD_CONTROL | MOD_NOREPEAT,
		0x59))
	{
		std::cout << "Hotkey registered\n";
	}

	MSG msg = { 0 };
	while (GetMessage(&msg, NULL, 0, 0) != 0)
	{
		if (msg.message == WM_HOTKEY)
		{
			std::cout << "WM_HOTKEY received\n";
			SystemParametersInfo(SPI_GETWORKAREA, 0, &aWsInfo, 0);
			//std::cout << aWsInfo.right << " - " << aWsInfo.bottom << std::endl;
			SetCursorPos(aWsInfo.right / 2, aWsInfo.bottom / 2);
		}
	}
	return 0;
}
