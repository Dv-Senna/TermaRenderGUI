#include "tr/instance.hpp"

#include <iostream>
#include <map>
#include <string>

#include <termios.h>



namespace tr {
	Instance::Instance(const tr::InstanceInfos &infos) :
		m_infos {infos},
		m_savedTerminal {}
	{
		static std::map<tr::ScreenSetMode, std::string> screenSetMode {
			{tr::ScreenSetMode::e640x480color16,    "\033[=17h"},
			{tr::ScreenSetMode::e320x200color256,   "\033[=18h"},
			{tr::ScreenSetMode::e640x480monochrome, "\033[=19h"}
		};

		std::cout << "\0337" "\033[?1049h" "\033[2J";
		std::cout << screenSetMode[m_infos.screenSetMode];
		std::cout << "\033[H";
		std::cout << std::flush;

		struct termios terminal {};
		tcgetattr(fileno(stdin), &terminal);
		m_savedTerminal = terminal;
		terminal.c_lflag &= (~ICANON & ~ECHO);
		terminal.c_cc[VTIME] = 0;
		terminal.c_cc[VMIN] = 1;
		if (tcsetattr(fileno(stdin), TCSANOW, &terminal) < 0)
			throw std::runtime_error("Can't set terminal to single character input mode");
	}


	Instance::~Instance() {
		static std::map<tr::ScreenSetMode, std::string> screenSetMode {
			{tr::ScreenSetMode::e640x480color16,    "\033[=17l"},
			{tr::ScreenSetMode::e320x200color256,   "\033[=18l"},
			{tr::ScreenSetMode::e640x480monochrome, "\033[=19l"}
		};


		if (tcsetattr(fileno(stdin), TCSANOW, &m_savedTerminal) < 0)
			std::cout << "Can't restore terminal input mode" << std::endl;

		std::cout << screenSetMode[m_infos.screenSetMode];
		std::cout << "\033[2J" "\033[?1049l" "\0338";
	}


} // namespace tr
