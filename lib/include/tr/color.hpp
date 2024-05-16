#pragma once

#include <ostream>
#include <string>



namespace tr {
	struct Color {
		std::string code;

		inline explicit operator std::string() const noexcept {
			return "\033[" + code + "m";
		}

		inline tr::Color operator+(const tr::Color &color) {
			auto result {*this};
			result.code += ";" + color.code;
			return result;
		}
	};

	inline std::ostream &operator<<(std::ostream &stream, const tr::Color &color) {
		stream << static_cast<std::string> (color);
		return stream;
	}


	namespace colors {
		inline static tr::Color fgBlack   {"30"};
		inline static tr::Color fgRed     {"31"};
		inline static tr::Color fgGreen   {"32"};
		inline static tr::Color fgYellow  {"33"};
		inline static tr::Color fgBlue    {"34"};
		inline static tr::Color fgMagenta {"35"};
		inline static tr::Color fgCyan    {"36"};
		inline static tr::Color fgWhite   {"37"};

		inline static tr::Color fgBrightBlack   {"90"};
		inline static tr::Color fgBrightRed     {"91"};
		inline static tr::Color fgBrightGreen   {"92"};
		inline static tr::Color fgBrightYellow  {"93"};
		inline static tr::Color fgBrightBlue    {"94"};
		inline static tr::Color fgBrightMagenta {"95"};
		inline static tr::Color fgBrightCyan    {"96"};
		inline static tr::Color fgBrightWhite   {"97"};

		inline static tr::Color bgBlack   {"40"};
		inline static tr::Color bgRed     {"41"};
		inline static tr::Color bgGreen   {"42"};
		inline static tr::Color bgYellow  {"43"};
		inline static tr::Color bgBlue    {"44"};
		inline static tr::Color bgMagenta {"45"};
		inline static tr::Color bgCyan    {"46"};
		inline static tr::Color bgWhite   {"47"};

		inline static tr::Color bgBrightBlack   {"100"};
		inline static tr::Color bgBrightRed     {"101"};
		inline static tr::Color bgBrightGreen   {"102"};
		inline static tr::Color bgBrightYellow  {"103"};
		inline static tr::Color bgBrightBlue    {"104"};
		inline static tr::Color bgBrightMagenta {"105"};
		inline static tr::Color bgBrightCyan    {"106"};
		inline static tr::Color bgBrightWhite   {"107"};

		inline static tr::Color none    {""};
		inline static tr::Color fgReset {"39"};
		inline static tr::Color bgReset {"49"};
	} // namespace colors

} // namespace tr
