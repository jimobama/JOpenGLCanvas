#ifndef JWINDOW_EVENTS_H
#define JWINDOW_EVENTS_H
namespace obaro
{
	namespace gui {	
		class JWindow;
		namespace events {
			
			class JEventArgs;
			class JWindowEvent {
			private:
				friend JWindow;
			protected:					
				virtual void onCreateEvent(JEventArgs *args)  {};
				virtual void onPaintEvent(JEventArgs *args)   {};
				virtual void onBeforeCreateEvent(JEventArgs *args) {};
				virtual void onResizeEvent(JEventArgs *arg)   {};
				virtual void onCloseEvent(JEventArgs *args)   {};
				virtual void onDestroyEvent(JEventArgs *args) {};
				virtual void onEnableEvent(JEventArgs * args) {};
				virtual void onCommandEvent(JEventArgs *args) {};				
			};
		}
	}
	
}
#endif