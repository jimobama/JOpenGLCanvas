#ifndef JTHREAD_H
#define JTHREAD_H
#include<Windows.h>
#include "JRunnable.h"
namespace obaro {

	namespace utils {	
		class JThread  :public JRunnable{
			JRunnable *__runnable;
			HANDLE __handle;
			LPDWORD  thread_id;
		protected:
			virtual void run();
		public:
			JThread(JRunnable *runable=0);
			LPDWORD getId();
			HANDLE getHandle();
			virtual ~JThread();
			void start();
			
		private:
			static void  __threadCall(void * args);

		};
	}
}
#endif