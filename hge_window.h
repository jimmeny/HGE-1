#ifndef HGE_WINDOW_H
#define HGE_WINDOW_H

#include <windows.h>

#include "hge_common.h"

typedef struct hgeWindow
{
#if DEV_SYS_WIN32
	HWND handle;
#endif
	float width, height;
} hgeWindow;

void	hgeWindow_Init(hgeWindow *self, float width, float height);

#endif//HGE_WINDOW_H