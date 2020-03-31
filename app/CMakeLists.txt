include(CheckCXXSourceCompiles)

set(CMAKE_REQUIRED_FLAGS ${STDFLAGLO})

CHECK_CXX_SOURCE_COMPILES("
        #include <filesystem>
        int main() {
        std::filesystem::path p;
        }
" HAS_FILESYSTEM2)

CHECK_CXX_SOURCE_COMPILES("
        #include <optional>
        int main() {
        std::optional<int> p;
        }
" HAS_OPTIONAL2)

CHECK_CXX_SOURCE_COMPILES("
        #include <string_view>
        int main() {
        std::string_view p;
        }
" HAS_STRINGVIEW2)

file(GLOB SOURCES *.cpp)
file(GLOB HEADERS *.h)

add_executable(example ${SOURCES} ${HEADERS})

if(HAS_FILESYSTEM2)
    target_compile_definitions(example PRIVATE "-DHAS_FILESYSTEM")
endif()

if(HAS_OPTIONAL2)
    target_compile_definitions(example PRIVATE "-DHAS_OPTIONAL")
endif()

if(HAS_STRINGVIEW2)
    target_compile_definitions(example PRIVATE "-DHAS_STRINGVIEW")
endif()

target_link_libraries(example PRIVATE engine)
set_property(TARGET example PROPERTY CXX_STANDARD ${STDLO})
set_property(TARGET example PROPERTY CXX_STANDARD_REQUIRED ON)
set_property(TARGET example PROPERTY CXX_ENTENSIONS ${GNULO})
