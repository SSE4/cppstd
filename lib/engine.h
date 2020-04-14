#if __cplusplus >= 202002L
#define HAS_CXX20
#endif

#if __cplusplus >= 201703L
#define HAS_CXX17
#endif

#if __cplusplus >= 201402L
#define HAS_CXX14
#endif

#if __cplusplus >= 201103L
#define HAS_CXX11
#endif

#include <iostream>
#include <cstddef>
#include <string>
#include <stdexcept>
#include <sstream>
#include <utility>
#include <vector>
#include <deque>
#include <list>
#include <set>
#include <map>
#include <memory>
#include <bitset>
#include <complex>
#include <fstream>
#include <locale>

#ifdef HAS_CODECVT

struct cvt: public std::codecvt<char, char, std::mbstate_t> {};

#endif

struct ioerr : public std::ios_base::failure {
    ioerr() : std::ios_base::failure("") {}
};

#define COMMA ,

#ifdef HAS_CXX11
#define type_alignof alignof
#else
#define type_alignof 0 * sizeof
#endif

template<typename T>
void check(const T & object, size_t size=sizeof(T), size_t alignment=type_alignof(T));

#define CHECK(type) check(type());

#ifdef HAS_CXX11

#include <tuple>
#include <thread>
#include <mutex>
#include <condition_variable>
#include <unordered_set>
#include <unordered_map>
#include <regex>
#include <memory>
#include <array>
#include <chrono>
#include <functional>
#include <atomic>

#endif

#ifdef HAS_CODECVT
#include <codecvt>
#endif

#ifdef HAS_CXX17

#include <shared_mutex>

#endif

#ifdef HAS_FILESYSTEM
#include <filesystem>
#endif

#ifdef HAS_OPTIONAL
#include <optional>
#endif

#ifdef HAS_STRINGVIEW
#include <string_view>
#endif

#ifdef HAS_ANY
#include <any>
#endif

#ifdef HAS_VARIANT
#include <variant>
#endif

#ifdef HAS_CXX20

#include <span>

#endif

void init();
