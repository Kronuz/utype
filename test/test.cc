// ctest for utype: toUType maps an enum value to its underlying integer type.

#include "utype.hh"

#include <cstdint>
#include <cstdio>
#include <type_traits>

enum class Color : std::uint8_t { Red = 1, Green = 2, Blue = 255 };
enum class Signed : int { Neg = -3, Zero = 0, Pos = 7 };

int main() {
	int failures = 0;
	auto check = [&](bool ok, const char* what) {
		if (!ok) { std::fprintf(stderr, "FAIL: %s\n", what); ++failures; }
	};

	// Value preservation.
	check(toUType(Color::Red) == 1, "Color::Red == 1");
	check(toUType(Color::Blue) == 255, "Color::Blue == 255");
	check(toUType(Signed::Neg) == -3, "Signed::Neg == -3");

	// Type preservation: the result type is exactly the enum's underlying type.
	static_assert(std::is_same_v<decltype(toUType(Color::Red)), std::uint8_t>);
	static_assert(std::is_same_v<decltype(toUType(Signed::Pos)), int>);

	// constexpr-usable.
	static_assert(toUType(Color::Green) == 2);

	if (failures == 0) { std::puts("all utype tests passed"); }
	return failures == 0 ? 0 : 1;
}
