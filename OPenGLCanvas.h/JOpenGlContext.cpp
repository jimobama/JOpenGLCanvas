#include "JOpenGlContext.h"
#include "JWindow.h"
#include<iostream>
using namespace obaro::gui;
using namespace obaro::gui::graphics;



JOpenGLContext::JOpenGLContext() {
	this->isGLContextCreateStatus = false;
	
}
	//initialised the context details here}
void JOpenGLContext::onCreate(JWindow *window) {
	//Create the OpenGl Context and that will be used to draw open Jen data on the current window	
	this->__window = window;
	PIXELFORMATDESCRIPTOR pd = {
		sizeof(PIXELFORMATDESCRIPTOR),
		1,//version
		PFD_DRAW_TO_WINDOW | PFD_SUPPORT_OPENGL | PFD_DOUBLEBUFFER,    //Flags
		PFD_TYPE_RGBA,            //The kind of framebuffer. RGBA or palette.
		32,                        //Colordepth of the framebuffer.
		0,
		0, 0, 0, 0, 0,
		0,
		0,
		0,
		0, 0, 0, 0,
		24,                        //Number of bits for the depthbuffer
		8,                        //Number of bits for the stencilbuffer
		0,                        //Number of Aux buffers in the framebuffer.
		PFD_MAIN_PLANE,
		0,
		0, 0, 0
	};
	HDC hdc = ::GetDC(this->__window->getHandle());
	int pixelFormat = ::ChoosePixelFormat(hdc, &pd);
	if (pixelFormat == 0) {
		std::cerr << "Could choose pixel format in  glcontext create function\n";	
		return;
	}
	//set it
	BOOL status = ::SetPixelFormat(hdc, pixelFormat, &pd);
	if (status != TRUE) {
		std::cerr << "Could set pixel format open glcontext create function\n";		
		return;

	}
	this->__hglrc = wglCreateContext(hdc);
	wglMakeCurrent(hdc, this->__hglrc);
	::ReleaseDC(__window->getHandle(), hdc);
	this->isGLContextCreateStatus = true;
	
}



 bool JOpenGLContext::isCreated() {
	return  this->isGLContextCreateStatus;
 }

void JOpenGLContext::onDestroy()
{	//
	
	if (this->__window != 0 && this->__hglrc!=0) {
		//The low level context when the context is destroy
		HDC hdc = ::GetDC(this->__window->getHandle());
		wglMakeCurrent(NULL, NULL);
		wglDeleteContext(this->__hglrc);

		
	}
}
