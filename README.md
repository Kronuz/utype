# utype

[![CI](https://github.com/Kronuz/utype/actions/workflows/ci.yml/badge.svg)](https://github.com/Kronuz/utype/actions/workflows/ci.yml)

`toUType(e)` returns the value of an enum(-class) as its **underlying integer
type** -- the missing inverse of `static_cast<EnumClass>(int)`. Extracted from
[Xapiand](https://github.com/Kronuz/Xapiand).

```cpp
#include "utype.hh"

enum class State : std::uint8_t { Idle = 0, Running = 2 };
auto n = toUType(State::Running);   // std::uint8_t, value 2
```

`constexpr` and `noexcept`; the result type is exactly `std::underlying_type_t<E>`,
so it never silently widens. Header-only, standard-library only.

## Dependencies

**None** — header-only, standard library only.

## Build / test
```sh
cmake -B build && cmake --build build && ctest --test-dir build
```

## Use (FetchContent)
```cmake
FetchContent_Declare(utype GIT_REPOSITORY https://github.com/Kronuz/utype.git GIT_TAG main)
FetchContent_MakeAvailable(utype)
target_link_libraries(your_app PRIVATE utype::utype)
```
