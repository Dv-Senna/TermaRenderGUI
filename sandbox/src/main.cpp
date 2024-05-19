#include <chrono>
#include <iostream>

#include <tr/color.hpp>
#include <tr/draw.hpp>
#include <tr/inputManager.hpp>
#include <tr/instance.hpp>
#include <tr/types.hpp>
#include <tr/vec2.hpp>


int main() {
	tr::InstanceInfos instanceInfos {};
	instanceInfos.screenSetMode = tr::ScreenSetMode::e320x200color256;
	tr::Instance instance {instanceInfos};

	/*std::cout << tr::colors::fgBrightBlue << "Hello " << (tr::colors::fgRed + tr::colors::bgBrightYellow) << " world !" << (tr::colors::fgReset + tr::colors::bgReset) << " Go back to normal" << std::endl;

	std::cout << tr::RGBColor(255, 150, 0) << "HAHA" << tr::colors::bgReset << std::endl;

	tr::drawColorAtPixel(tr::Vec2f(30, 40), tr::RGBColor(255, 150, 0));
	tr::drawColorAtPixel(tr::Vec2f(0, 0), tr::RGBColor(0, 150, 0));*/

	tr::drawTextAtPixel(tr::Vec2f(50, 10), tr::RGBColor(255, 150, 100, false), "Hello World !");
	std::cout << std::flush;

	auto start {std::chrono::steady_clock::now()};

	while (true) {
		tr::InputManager::update();
		auto current {std::chrono::steady_clock::now()};
		if (std::chrono::duration_cast<std::chrono::seconds> (current - start).count() >= 10)
			break;
	}


	return 0;
}