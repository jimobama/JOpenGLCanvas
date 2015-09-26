#ifndef EVENT_ARG_H
#define EVENT_ARG_H
#include<Windows.h>

namespace obaro {
	namespace gui {

		namespace events {
			class JEventArgs {
			public:
				LPARAM lParam;
				WPARAM wParam;
				UINT msg;
				void *source;
			};
		}
	}
}
#endif
