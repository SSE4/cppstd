cmake_minimum_required(VERSION 2.8)

project(cppstd)

message(STATUS "STDHI: ${STDHI}")
message(STATUS "GNUHI: ${GNUHI}")
message(STATUS "STDLO: ${STDLO}")
message(STATUS "GNULO: ${GNULO}")

add_subdirectory(engine)
add_subdirectory(example)
