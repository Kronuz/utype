# utype

Part of [Kronuz C++ Libraries](https://github.com/Kronuz/cpp-libraries), a collection of small, reusable C++ libraries.

[![CI](https://github.com/Kronuz/utype/actions/workflows/ci.yml/badge.svg)](https://github.com/Kronuz/utype/actions/workflows/ci.yml)
[![License: MIT](https://img.shields.io/badge/license-MIT-blue.svg)](LICENSE)
![C++20](https://img.shields.io/badge/C%2B%2B-20-blue.svg)
![Header-only](https://img.shields.io/badge/header--only-yes-green.svg)

Header-only enum-to-integer cast for C++20: toUType(e) returns the exact underlying type,
constexpr and noexcept. It is a `static_cast` to `std::underlying_type_t<E>`, so the
caller never names the type and never widens it by accident. Reach for it when an enum
goes into a wire format, an array index or a bit field.

## ✨ Highlights

- **Exactly `std::underlying_type_t<E>`:** a `std::uint8_t` enum gives a `std::uint8_t`,
  never an `int`.
- **`constexpr` and `noexcept`:** usable in `static_assert` and constant expressions.
- **One function template** in one header, over `<type_traits>`.

## 🚀 Quick start

```cpp
#include "utype.hh"

#include <cstdint>
#include <cstdio>
#include <type_traits>

enum class State : std::uint8_t { Idle = 0, Running = 2 };

static_assert(toUType(State::Running) == 2);

int main() {
	auto n = toUType(State::Running);
	static_assert(std::is_same_v<decltype(n), std::uint8_t>);
	std::printf("%d\n", n);  // 2
}
```

## 📦 Installation

Requires C++20 and CMake 3.16 or newer; no other dependencies. CI builds and tests it on
Linux (x86_64 with GCC and Clang, arm64), macOS (arm64, x86_64) and FreeBSD, plus ASan,
UBSan and TSan builds.

```cmake
include(FetchContent)
FetchContent_Declare(utype
  GIT_REPOSITORY https://github.com/Kronuz/utype.git
  GIT_TAG        6e2c2a858e3d88cf678d899f82b284b92af1caca)  # or main, to track the tip
FetchContent_MakeAvailable(utype)

target_link_libraries(my_app PRIVATE utype::utype)
```

Link `utype::utype` and include `utype.hh`.

## 🎯 When to use it

- Writing enums to wire formats, arrays or bit fields in C++20 code.

Not for:

- C++23 code: `std::to_underlying` does the same.
- Enum names as strings: see [enum-reflection](https://github.com/Kronuz/enum-reflection).
- Non-enum arguments: `std::underlying_type_t` of a non-enum type does not compile.

## 📚 Documentation

- [ARCHITECTURE.md](ARCHITECTURE.md): the one function.
- [AGENTS.md](AGENTS.md): repository map.
- [Catalog entry](https://github.com/Kronuz/cpp-libraries/blob/main/AGENTS.md#utype) in
  Kronuz C++ Libraries.

## 🛠️ Building and testing

```sh
cmake -B build -DCMAKE_BUILD_TYPE=Release
cmake --build build
ctest --test-dir build --output-on-failure
```

## 🤝 Contributing

Issues and pull requests are welcome; read [AGENTS.md](AGENTS.md) and the catalog's
[rules of engagement](https://github.com/Kronuz/cpp-libraries/blob/main/AGENTS.md#rules-of-engagement)
first.

## 📄 License

MIT, see [LICENSE](LICENSE). Extracted from [Xapiand](https://github.com/Kronuz/Xapiand).
