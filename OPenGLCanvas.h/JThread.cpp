#include "JThread.h"
#include <iostream>

using namespace obaro::utils;

JThread::JThread(JRunnable *runable) {

	this->__runnable = (JRunnable*)runable;
}

void JThread::start() {

	//create the new thread here
	this->__handle = ::CreateThread(0, 0, (LPTHREAD_START_ROUTINE)&JThread::__threadCall, this, 0, (this->thread_id));
	if (this->__handle==0) {
		std::cout << "Couldnot start the thread in thread function start()";
	}	
}

//Create the thread call function
void JThread::__threadCall(void *arg) {

	JThread *thread = (JThread*)arg;
	if (thread != 0) {
		if (thread->__runnable != NULL) {
			//cash it back to its parent
			thread =(JThread*) (thread->__runnable);
		}		
		thread->run();
	}
}


void JThread::run() {

	//do nothing 
}
LPDWORD JThread::getId() {
	return this->thread_id;
}

HANDLE JThread::getHandle() {
	return this->__handle;
}

JThread::~JThread() {
	::WaitForSingleObjectEx(this->getHandle(),INFINITE,true);
		
}
