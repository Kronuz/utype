# AGENTS

One header, one function: `toUType(e)` -> `std::underlying_type_t<E>`. Extracted
verbatim from Xapiand.

- Header-only, zero dependencies (just `<type_traits>`), `constexpr`/`noexcept`.
- `test/test.cc` (ctest) covers value + exact-type preservation and constexpr use.
- Do not widen the return type or drop `constexpr`; callers rely on both.
- No separate ARCHITECTURE.md: there is no architecture beyond the one-line cast.

## Verification and benchmarks

The method shared by the Kronuz libraries is in
[docs/PERFORMANCE.md](https://github.com/Kronuz/cpp-libraries/blob/main/docs/PERFORMANCE.md).

- **Tests.** `cmake -B build && cmake --build build && ctest --test-dir build` runs `utype`
  (`test/test.cc`). The oracle is `std::is_same_v` against the declared underlying type, in
  `static_assert`s, so a wrong return type fails the build.
- **Sanitizers.** CI (`.github/workflows/ci.yml`, which calls the shared
  [cmake.yml](https://github.com/Kronuz/cpp-libraries/blob/main/.github/workflows/cmake.yml))
  runs the test in an ASan+UBSan build and a TSan build, with clang on Linux. The ASan+UBSan
  job is:

  ```sh
  CC=clang CXX=clang++ cmake -B build-asan -DCMAKE_BUILD_TYPE=Debug \
    -DCMAKE_CXX_FLAGS="-fsanitize=address,undefined -fno-sanitize-recover=undefined -fno-omit-frame-pointer -D_GLIBCXX_ASSERTIONS" \
    -DCMAKE_EXE_LINKER_FLAGS="-fsanitize=address,undefined"
  cmake --build build-asan && ASAN_OPTIONS=detect_leaks=1 ctest --test-dir build-asan --output-on-failure
  ```

- **Not here.** No benchmark, differential, fuzz target or mutation script: the function is one
  `static_cast`, with nothing to time or compare against.
