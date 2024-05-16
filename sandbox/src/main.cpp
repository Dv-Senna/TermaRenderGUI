#include <iostream>

#include <tr/color.hpp>
#include <tr/types.hpp>
#include <tr/vec2.hpp>


int main() {

	std::cout << tr::colors::fgBrightBlue << "Hello " << (tr::colors::fgRed + tr::colors::bgBrightYellow) << " world !" << (tr::colors::fgReset + tr::colors::bgReset) << " Go back to normal" << std::endl;

	return 0;
}