#include "JWindowProcedure.h"
#include "JWindow.h"
#include "JEventArgs.h"

using namespace obaro::gui;
using namespace obaro::gui::events;

 LRESULT CALLBACK  JWindowProcedure::WndProc(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam) {

	static JWindow* window = 0;
	static JEventArgs *args = 0;
	if (args == 0) {
		args = new JEventArgs();
	}

	args->lParam = lParam;
	args->wParam = wParam;
	args->msg = msg;

	switch (args->msg)
	{
	case WM_NCCREATE:
	{
		CREATESTRUCT * pcs = (CREATESTRUCT*)lParam;
		window = (JWindow*)pcs->lpCreateParams;
		window->__hwnd = hwnd;
		args->source = window;	

		SetWindowLongPtr(hwnd, GWLP_USERDATA, (LONG_PTR)window);
		if (window != 0) {
			window->onBeforeCreateEvent(args);
		}
		return TRUE;
	}
	case WM_CREATE:
		window = (JWindow*)GetWindowLongPtr(hwnd, GWLP_USERDATA);	
		window->__hwnd = hwnd;
		window->onCreateEvent(args);		
		break;
	case WM_SIZE:
		window->onResizeEvent(args);
		break;
	case WM_PAINT:	
		window->onPaintEvent(args);
		break;
	case WM_CLOSE:
		window->onCloseEvent(args);		
		break;
	case WM_DESTROY:
		window->onDestroyEvent(args);
		break;
	case WM_ENABLE:
		window->onEnableEvent(args);
		break;
	case WM_COMMAND:
		window->onCommandEvent(args);
		break;	
	default:
		return  DefWindowProc(hwnd, msg, wParam, lParam);
	}
	return wParam;

}