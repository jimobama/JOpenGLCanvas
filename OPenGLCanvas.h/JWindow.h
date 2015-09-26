#ifndef  OBARO_JWINDOW_H
#define  OBARO_JWINDOW_H
#include<Windows.h>
#include "JWindowEvent.h"
#include "JRunnable.h"
#include<string>
//#include<gl\GL.h>



namespace obaro
{

namespace utils {
	class JThread;
}
namespace gui {

	namespace structure {
		typedef WNDCLASSEX WindowProperty;
		typedef MSG        Message;
		typedef HWND       HWindow;
		typedef RECT       Rectangle;
		typedef HINSTANCE   HInstance;
	}
	namespace events {
		class JWindowProcedure;
		class JEventArgs;
	}
	

	
 /*
 The main window canvas
 
 */
	class JWindow :public events::JWindowEvent, utils::JRunnable
		{

		friend events::JWindowProcedure;

		private:
			//pointers			
			structure::WindowProperty __wndClass;
			structure::Rectangle  __rect;
			structure::HWindow __hwnd;
			structure::Message  __msg;
			structure::HInstance __instance;		
			std::string __title;
			std::string __className;
			static bool showing;
		
	
			
		public:
			JWindow(std::string title="");
			virtual ~JWindow();
			structure::HWindow getHandle();	
			void setWindowSize(const int width,const int height);
			void setWindowPosition(const int x,const  int y);
			bool isShowing() { return showing; };
			const int execute();
		private:			
			void __init();			
			void __registered();
			bool __create();
			utils::JThread *mainthread;
		protected:
			//override window events		
			virtual void run();
			virtual void onCloseEvent(events::JEventArgs *args);
			virtual void onDestroyEvent(events::JEventArgs *args);	
			virtual void onBeforeCreateEvent(events::JEventArgs *args);

	

		};
	}
}
#endif
