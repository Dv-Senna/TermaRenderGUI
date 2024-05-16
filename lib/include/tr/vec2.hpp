#pragma once

#include <ostream>

#include "tr/types.hpp"



namespace tr {
	template <typename T>
	struct Vec2 {
		union {
			T x;
			T w;
		};
		union {
			T y;
			T h;
		};

		inline Vec2() : x {0}, y {0} {}
		template <typename U>
		inline Vec2(U fill) : x {(T)fill}, y {(T)fill} {}
		template <typename T1, typename T2>
		inline Vec2(T1 _x, T2 _y) : x {(T)_x}, y {(T)_y} {}
		template <typename U>
		inline Vec2(const tr::Vec2<U> &vector) : x {(T)vector.x}, y {(T)vector.y} {}
		template <typename U>
		inline const tr::Vec2<T> &operator=(const tr::Vec2<U> &vector) {
			x = (T)vector.x;
			y = (T)vector.y;
			return *this;
		}

		template <typename U>
		inline const tr::Vec2<T> &operator+=(const tr::Vec2<U> &vector) {
			x += (T)vector.x;
			y += (T)vector.y;
			return *this;
		}
		template <typename U>
		inline const tr::Vec2<T> &operator-=(const tr::Vec2<U> &vector) {
			x -= (T)vector.x;
			y -= (T)vector.y;
			return *this;
		}
		template <typename U>
		inline const tr::Vec2<T> &operator*=(const tr::Vec2<U> &vector) {
			x *= (T)vector.x;
			y *= (T)vector.y;
			return *this;
		}

		template <typename U>
		inline tr::Vec2<T> operator+(const tr::Vec2<U> &vector) {
			auto result {*this};
			result += vector;
			return result;
		}
		template <typename U>
		inline tr::Vec2<T> operator-(const tr::Vec2<U> &vector) {
			auto result {*this};
			result -= vector;
			return result;
		}
		template <typename U>
		inline tr::Vec2<T> operator*(const tr::Vec2<U> &vector) {
			auto result {*this};
			result *= vector;
			return result;
		}

		template <typename U>
		inline bool operator==(const tr::Vec2<U> &vector) {
			return x == (T)vector.x && y == (T)vector.y;
		}
	};

	template <typename T>
	inline std::ostream &operator<<(std::ostream &stream, const tr::Vec2<T> &vector) {
		stream << "(" << vector.x << ", " << vector.y << ")";
		return stream;
	}


	using Vec2f = tr::Vec2<tr::Float>;
	using Vec2i = tr::Vec2<tr::Int>;


} // namespace tr
