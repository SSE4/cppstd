file(GLOB SOURCES *.cpp)
file(GLOB HEADERS *.h)

add_library(engine SHARED ${SOURCES} ${HEADERS})

target_include_directories(engine PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})

set_property(TARGET engine PROPERTY CXX_STANDARD ${STDHI})
set_property(TARGET engine PROPERTY CXX_STANDARD_REQUIRED ON)
set_property(TARGET engine PROPERTY CXX_ENTENSIONS ${GNUHI})
