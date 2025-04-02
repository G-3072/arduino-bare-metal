cmake_minimum_required(VERSION 3.14 FATAL_ERROR)

project(arduino-bare-metal VERSION 1.0 LANGUAGES C ASM)

message(STATUS ${CMAKE_VERSION})

include(cmake/avr-gcc.cmake)

add_subdirectory(package)