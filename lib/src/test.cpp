#include "tr/test.hpp"

#include <iostream>


namespace test {
	void sayHello() {
		#ifdef TR_WINDOWS
			std::cout << "Hello from Windows TermRenderGUI !" << std::endl;
		#elifdef TR_LINUX
			std::cout << "Hello from Linux TermRenderGUI !" << std::endl;
		#elifdef TR_APPLE
			std::cout << "Hello from Apple TermRenderGUI !" << std::endl;
		#endif
	}
}