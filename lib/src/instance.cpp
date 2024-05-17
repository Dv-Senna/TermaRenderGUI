#include "tr/instance.hpp"

#include <iostream>
#include <map>
#include <string>



namespace tr {
	Instance::Instance(const tr::InstanceInfos &infos) :
		m_infos {infos}
	{
		static std::map<tr::ScreenSetMode, std::string> screenSetMode {
			{tr::ScreenSetMode::e640x480color16,    "\033[=17h"},
			{tr::ScreenSetMode::e320x200color256,   "\033[=18h"},
			{tr::ScreenSetMode::e640x480monochrome, "\033[=19h"}
		};

		std::cout << "\0337" "\033[?1049h" "\033[2J";
		std::cout << screenSetMode[m_infos.screenSetMode];
		std::cout << "\033[H";
	}


	Instance::~Instance() {
		static std::map<tr::ScreenSetMode, std::string> screenSetMode {
			{tr::ScreenSetMode::e640x480color16,    "\033[=17l"},
			{tr::ScreenSetMode::e320x200color256,   "\033[=18l"},
			{tr::ScreenSetMode::e640x480monochrome, "\033[=19l"}
		};

		std::cout << screenSetMode[m_infos.screenSetMode];
		std::cout << "\033[2J" "\033[?1049l" "\0338";
	}


} // namespace tr
