cmake_minimum_required(VERSION 3.14 FATAL_ERROR)

include(cmake/avr-gcc.cmake)

project(arduino-bare-metal VERSION 1.0 LANGUAGES C ASM)

message(STATUS ${CMAKE_VERSION})

add_subdirectory(package)
add_subdirectory(tests)