#include <windows.h>

#include "hge_common.h"
#include "hge_window.h"

hgeBool class_registered = hgeFalse;
char *windowClassName = "hgeWindow";

LRESULT CALLBACK doNothing(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam) {
	switch(message) {
		case WM_DESTROY:
			PostQuitMessage(0);
		default:
			return DefWindowProc(hWnd, message, wParam, lParam);
	}
}

static void hgeWindow_RegisterWindowClass() {
	WNDCLASSEX wcex = {0};

	wcex.cbSize = sizeof(WNDCLASSEX);
	wcex.style = CS_HREDRAW | CS_VREDRAW;
	wcex.lpfnWndProc = doNothing;
	wcex.hInstance = GetModuleHandle(NULL);
	wcex.hbrBackground = (HBRUSH)(COLOR_WINDOW+1);
	wcex.lpszClassName = windowClassName;

	class_registered = hgeTrue;
	RegisterClassEx(&wcex);
}

void hgeWindow_Init(hgeWindow *self, float width, float height) {
	if(!class_registered) {
		hgeWindow_RegisterWindowClass();
	}
	self->handle = CreateWindow(windowClassName, "Robert, Check this out!", WS_OVERLAPPEDWINDOW,
		CW_USEDEFAULT, CW_USEDEFAULT, width, height,
		NULL, NULL, GetModuleHandle(NULL), NULL);

	if(self->handle) {
		ShowWindow(self->handle, SW_SHOW);
		UpdateWindow(self->handle);
	}
}
