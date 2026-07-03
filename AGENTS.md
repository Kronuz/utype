# AGENTS

One header, one function: `toUType(e)` -> `std::underlying_type_t<E>`. Extracted
verbatim from Xapiand.

- Header-only, zero dependencies (just `<type_traits>`), `constexpr`/`noexcept`.
- `test/test.cc` (ctest) covers value + exact-type preservation and constexpr use.
- Do not widen the return type or drop `constexpr`; callers rely on both.
- No separate ARCHITECTURE.md: there is no architecture beyond the one-line cast.
