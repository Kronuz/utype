# utype

Part of [Kronuz C++ Libraries](https://github.com/Kronuz/cpp-libraries), a collection of small, reusable C++ libraries.

[![CI](https://github.com/Kronuz/utype/actions/workflows/ci.yml/badge.svg)](https://github.com/Kronuz/utype/actions/workflows/ci.yml)
[![License: MIT](https://img.shields.io/badge/license-MIT-blue.svg)](LICENSE)
![C++20](https://img.shields.io/badge/C%2B%2B-20-blue.svg)
![Header-only](https://img.shields.io/badge/header--only-yes-green.svg)

`toUType(e)`: an enum's value as its exact underlying integer type, in C++20.
The inverse of `static_cast<Enum>(n)`, without naming the type.

## ✨ Highlights

- **Exactly `std::underlying_type_t<E>`**, never a silent widening.
- **`constexpr` and `noexcept`.**
- **One header, no dependencies.**

## 📦 Installation

Requires a C++20 compiler; CMake 3.14 or newer for the CMake route. CI builds it
on Linux (x86_64, arm64), macOS (arm64, x86_64), and FreeBSD, plus ASan, UBSan,
and TSan builds.

```cmake
include(FetchContent)
FetchContent_Declare(utype
  GIT_REPOSITORY https://github.com/Kronuz/utype.git
  GIT_TAG        main)
FetchContent_MakeAvailable(utype)

target_link_libraries(my_app PRIVATE utype::utype)
```

## 🚀 Quick start

```cpp
#include "utype.hh"

#include <cstdint>

enum class State : std::uint8_t { Idle = 0, Running = 2 };

static_assert(toUType(State::Running) == 2);   // a std::uint8_t

int main() {}
```

## 🎯 When to use it

- ✅ Writing enums to wire formats, arrays, or bit fields.
- ❌ C++23 code: `std::to_underlying` does the same.

## 📚 Documentation

- [ARCHITECTURE.md](ARCHITECTURE.md): the one function.
- [AGENTS.md](AGENTS.md): repository map.

## 🛠️ Building and testing

```sh
cmake -B build && cmake --build build && ctest --test-dir build
```

## 🤝 Contributing

Issues and pull requests are welcome. Read [AGENTS.md](AGENTS.md) first. CI must
pass on every platform.

## 📄 License

MIT, Copyright (c) 2015-2018 Dubalu LLC. See [LICENSE](LICENSE). Extracted from
[Xapiand](https://github.com/Kronuz/Xapiand).
