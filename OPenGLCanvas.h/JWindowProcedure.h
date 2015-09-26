#ifndef WINDOW_PROCEDURE_ROUTINE_H
#define WINDOW_PROCEDURE_ROUTINE_H
#include<Windows.h>
/*Description

The file handle the underline window window procedure routines for all window events that are current presents

*/

#ifndef _WIN32_WINNT
#define _WIN32_WINNT 0x0400                     // for WM_MOUUSEWHEEL.
#endif
namespace obaro {
	namespace gui {	
		namespace events {
			class JWindowProcedure{			
			private:		  
			  public:
				  static LRESULT CALLBACK  WndProc(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam);

			};
		}
	}
}
#endif