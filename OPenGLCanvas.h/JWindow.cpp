
#include<iostream>
#include "JWindow.h"
#include "JEventArgs.h"
#include "JWindowProcedure.h"
#include "JThread.h"


using namespace obaro::gui;
using namespace obaro::gui::events;

bool JWindow::showing = false;
JWindow::JWindow(std::string title) {
	this->__title = title;
	this->__className = "JWindow";
	this->__rect.left = 0;
	this->__rect.bottom = 400;
	this->__rect.top = 0;
	this->__rect.right = 300;
	this->__instance = ::GetModuleHandle(NULL);
	this->__hwnd = 0;	
	//create the new thread for the window
	this->mainthread = new utils::JThread(this);

}


void JWindow::__init() {

	this->__wndClass.cbSize = sizeof(structure::WindowProperty);
	this->__wndClass.cbClsExtra = 0;
	this->__wndClass.cbWndExtra = 0;
	this->__wndClass.hbrBackground = (HBRUSH)::CreateSolidBrush(RGB(214, 214, 214));
	this->__wndClass.hCursor = LoadCursor(this->__instance, IDC_ARROW);
	this->__wndClass.hIcon = LoadCursor(this->__instance, IDI_APPLICATION);
	this->__wndClass.hIconSm = LoadCursor(this->__instance, IDI_APPLICATION);
	this->__wndClass.hInstance = this->__instance;
	//handle the main window procedure 
	this->__wndClass.lpfnWndProc = JWindowProcedure::WndProc;
	this->__wndClass.lpszClassName = this->__className.c_str();
	this->__wndClass.style = 0;

}


void JWindow::run() {

	this->__registered();
	bool status = this->__create();
	if (!status) {
	   std::cout<< "Could'nt Create either"<<std::endl;
	  return;
	}

	::SetWindowText(this->__hwnd, this->__title.c_str());
	//__menubar = new IMenu(this);
	ShowWindow(this->__hwnd, 1);
	UpdateWindow(this->__hwnd);
	showing = true;

	while (GetMessage(&this->__msg, NULL, 0, 0) ) {
		::TranslateMessage(&this->__msg);
	    DispatchMessage(&this->__msg);
	}
	showing = false;

}
void JWindow::__registered() {

	this->__init();
	BOOL status =::RegisterClassEx(&this->__wndClass);
	if (!status) {
		MessageBox(NULL, "Could register window class", "Window Error2,0", MB_OK);
	}

}
structure::HWindow JWindow::getHandle() {	
	return __hwnd;
}

bool JWindow::__create() {
	
	this->__hwnd = CreateWindowEx(//| WS_CLIPSIBLING 
		WS_EX_CLIENTEDGE,
		this->__className.c_str(),
		this->__title.c_str(),
		WS_OVERLAPPEDWINDOW | WS_CLIPCHILDREN | WS_CLIPSIBLINGS,
		this->__rect.left,
		this->__rect.top,
		this->__rect.right,
		this->__rect.bottom,
		NULL,
		NULL,
		this->__instance,
		this//pass the object class to the procedure 
		);

	if (this->__hwnd == 0) return false;
	return true;
}
void JWindow::setWindowSize(const int width, const int height) {
	this->__rect.right = width;
	this->__rect.bottom = height;
}
void JWindow::setWindowPosition(const int x, const  int y) {
	this->__rect.left = x;
	this->__rect.top = y;
}
const int JWindow::execute() {
	
	this->mainthread->start();	
	//wait util the window is created and show on the screen;
	while (!showing) {};
	return (int)__msg.wParam;
}

void JWindow::onCloseEvent(JEventArgs *args)
{	
  
  ::DestroyWindow(this->__hwnd);
}

void  JWindow::onDestroyEvent(JEventArgs *args) {
	
	ReleaseDC(this->__hwnd, ::GetDC(this->__hwnd));
	PostQuitMessage(0);
}
void JWindow::onBeforeCreateEvent(events::JEventArgs *args)
{
		
}

JWindow::~JWindow() {
	
	delete __instance;
	delete __hwnd;
	::WaitForSingleObjectEx(this->mainthread->getHandle(), INFINITE, true);
	delete this->mainthread;
	showing = false;

}


