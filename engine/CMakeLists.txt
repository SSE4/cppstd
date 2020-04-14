include(CheckCXXSourceCompiles)

set(CMAKE_REQUIRED_FLAGS ${STDFLAGHI})

CHECK_CXX_SOURCE_COMPILES("
        #include <filesystem>
        int main() {
        std::filesystem::path p;
        }
" HAS_FILESYSTEM1)

CHECK_CXX_SOURCE_COMPILES("
        #include <optional>
        int main() {
        std::optional<int> p;
        }
" HAS_OPTIONAL1)

CHECK_CXX_SOURCE_COMPILES("
        #include <string_view>
        int main() {
        std::string_view p;
        }
" HAS_STRINGVIEW1)

CHECK_CXX_SOURCE_COMPILES("
        #include <any>
        int main() {
        std::any p;
        }
" HAS_ANY1)

CHECK_CXX_SOURCE_COMPILES("
        #include <codecvt>
        int main() {
        typedef std::codecvt<char, char, std::mbstate_t> p;
        }
" HAS_CODECVT1)

CHECK_CXX_SOURCE_COMPILES("
        #include <variant>
        int main() {
        std::variant<int, bool> p;
        }
" HAS_VARIANT1)

file(GLOB SOURCES *.cpp)
file(GLOB HEADERS *.h)

add_library(engine SHARED ${SOURCES} ${HEADERS})

target_include_directories(engine PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})

if(HAS_FILESYSTEM1)
    target_compile_definitions(engine PRIVATE "-DHAS_FILESYSTEM")
endif()

if(HAS_OPTIONAL1)
    target_compile_definitions(engine PRIVATE "-DHAS_OPTIONAL")
endif()

if(HAS_STRINGVIEW1)
    target_compile_definitions(engine PRIVATE "-DHAS_STRINGVIEW")
endif()

if(HAS_ANY1)
    target_compile_definitions(engine PRIVATE "-DHAS_ANY")
endif()

if(HAS_CODECVT1)
    target_compile_definitions(engine PRIVATE "-DHAS_CODECVT")
endif()

if(HAS_VARIANT1)
    target_compile_definitions(engine PRIVATE "-DHAS_VARIANT1")
endif()

set_property(TARGET engine PROPERTY CXX_STANDARD ${STDHI})
set_property(TARGET engine PROPERTY CXX_STANDARD_REQUIRED ON)
set_property(TARGET engine PROPERTY CXX_ENTENSIONS ${GNUHI})
