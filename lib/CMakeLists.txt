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

set_property(TARGET engine PROPERTY CXX_STANDARD ${STDHI})
set_property(TARGET engine PROPERTY CXX_STANDARD_REQUIRED ON)
set_property(TARGET engine PROPERTY CXX_ENTENSIONS ${GNUHI})
