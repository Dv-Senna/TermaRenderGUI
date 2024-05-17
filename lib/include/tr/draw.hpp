#pragma once

#include <string>

#include "tr/color.hpp"
#include "tr/core.hpp"
#include "tr/vec2.hpp"



namespace tr {
	TR_CORE void drawColorAtPixel(const tr::Vec2f &position, const tr::RGBColor &color);
	TR_CORE void drawTextAtPixel(const tr::Vec2f &position, const tr::RGBColor &color, const std::string &text);
} // namespace tr
