
#ifndef OPENGL_CANVAS_H
#define OPENGL_CANVAS_H
#include"JWindow.h"
#include <GL/GL.h>
#include<gl/GLU.h>
#pragma comment (lib, "opengl32.lib")

namespace obaro
{
	
	namespace gui {

		namespace graphics {
			class JContext;
		}
	
		namespace events {
			class JEventArgs;
		}


		class JOpenGLWindow :public JWindow {
		private :
			//create a new drawing context
			graphics::JContext *__glcontext;
		public:
			JOpenGLWindow(std::string title);
			virtual ~JOpenGLWindow();
//over window create method
		protected:
			virtual void onCreateEvent(events::JEventArgs *args);
			virtual void onPaintEvent(events::JEventArgs *args);
			virtual void onCloseEvent(events::JEventArgs *args);
			virtual void onResizeEvent(events::JEventArgs *args);
		};
	}
}
#endif
