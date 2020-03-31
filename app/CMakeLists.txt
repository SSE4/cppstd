file(GLOB SOURCES *.cpp)
file(GLOB HEADERS *.h)

add_executable(example ${SOURCES} ${HEADERS})

target_link_libraries(example PRIVATE engine)
set_property(TARGET example PROPERTY CXX_STANDARD ${STDLO})
set_property(TARGET example PROPERTY CXX_STANDARD_REQUIRED ON)
set_property(TARGET example PROPERTY CXX_ENTENSIONS ${GNULO})
