#include "tr/draw.hpp"

#include <iostream>



namespace tr {
	void drawColorAtPixel(const tr::Vec2f &position, const tr::RGBColor &color) {
		std::cout << "\033[" << (int)position.y << ";" << (int)position.x << "H" << color << " ";
	}

	void drawTextAtPixel(const tr::Vec2f &position, const tr::RGBColor &color, const std::string &text) {
		std::cout << "\033[" << (int)position.y << ";" << (int)position.x << "H" << color << text;
	}
} // namespace tr
