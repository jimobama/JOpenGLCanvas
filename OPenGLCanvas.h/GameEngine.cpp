#include "JOpenGLWindow.h"
using namespace obaro::gui;

int main() {

	JWindow *window = new JOpenGLWindow("Window");
	window->execute();

	while (window->isShowing());
	
}