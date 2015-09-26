#ifndef JCONTEXT_CONTEXT_H
#define JCONTEXT_CONTEXT_H

namespace obaro {

	namespace gui{	
		class JWindow;
		namespace graphics {
			 
			class JContext {
				friend gui::JWindow;				
			protected:				
				gui::JWindow *__window;
				
			public:
				virtual void onCreate(gui::JWindow *__window)=0;				
				virtual void onDestroy()=0;				
			};
		}
		
	}
}
#endif
