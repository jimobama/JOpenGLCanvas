
#ifndef JRUNNABLE_H
#define JRUNNABLE_H
/*A runnable interface*/
namespace obaro {
	namespace utils {

		class JRunnable {
		protected:
			virtual void run() = 0;
		};
	}
}
#endif
