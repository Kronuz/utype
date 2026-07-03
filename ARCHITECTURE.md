# Architecture

One header, one function. `toUType(e)` is `static_cast<std::underlying_type_t<E>>(e)`,
`constexpr` and `noexcept`. That is the whole library — there is no state, no
allocation, no branching.

## Why it exists

`static_cast<EnumClass>(int)` is easy; the inverse (enum value → its integer) is
verbose and, done by hand, easy to get wrong (widening to `int`, or losing the exact
underlying type). `toUType` gives the exact underlying type back, so it composes with
bit operations, array indexing, and serialization without a surprise conversion.

## Dependencies

**None.** Standard library only (`<type_traits>`).

## Invariants

- The return type is exactly `std::underlying_type_t<E>` — never widened.
- `constexpr` + `noexcept`; usable in constant expressions.
- Verbatim from Xapiand; keep the signature stable (callers rely on both properties).
