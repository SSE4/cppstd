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

#endif

#ifdef HAS_CXX17

#include <string_view>
#include <optional>
#include <any>
#include <variant>
#include <shared_mutex>
//#include <filesystem>

#endif

#ifdef HAS_CXX20

#include <span>

#endif

void init();
