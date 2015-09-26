#ifndef JOPEN_CONTEXT_H
#define JOPEN_CONTEXT_H
#include<Windows.h>
#include "JContext.h"


/*This is the openGL abstract window context for drawing*/
namespace obaro {
	namespace gui {

		namespace graphics {

			class JOpenGLContext :public JContext {
				
			private:
				HGLRC __hglrc;		
				bool  isGLContextCreateStatus;					
			public:
				JOpenGLContext();
		     	virtual void onCreate(gui::JWindow *__window);
				virtual void onDestroy();
				bool isCreated();	
			
			
			};

		}
	}
}
#endif
