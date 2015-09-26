


#include "JOpenGLWindow.h"
#include "JEventArgs.h"
#include "JOpenGlContext.h"


using namespace obaro::gui;
using namespace obaro::gui::graphics;
JOpenGLWindow::JOpenGLWindow(std::string title):
JWindow(title)
{
	setWindowPosition(10, 10);
	setWindowSize(500, 500);
	this->__glcontext = 0;   

}

//create the open gl context immediately
void JOpenGLWindow::onCreateEvent(events::JEventArgs *args) 
{	//call the parant on create events
	JWindow::onCreateEvent(args);
	//create the graphic context for gl
	this->__glcontext = new JOpenGLContext();
	this->__glcontext->onCreate(this);
   
	
}
void JOpenGLWindow::onPaintEvent(events::JEventArgs *args) {

	if (this->__glcontext != 0) {	
		::SwapBuffers(::GetDC(this->getHandle()));			
	}	
}

void JOpenGLWindow::onCloseEvent(events::JEventArgs *args) {
	JWindow::onCloseEvent(args);
	if (this->__glcontext != 0) {
		this->__glcontext->onDestroy();
	}
}

void  JOpenGLWindow::onResizeEvent(events::JEventArgs *args) {
	JWindow::onResizeEvent(args);
	if (this->__glcontext) {
		RECT rect;
		::GetClientRect(this->getHandle(), &rect);		 
		//set the glview point here
		glViewport(0, 0, rect.right, rect.bottom);

	}
}


JOpenGLWindow::~JOpenGLWindow() {
	//Memeory management	
	delete this->__glcontext;

}

