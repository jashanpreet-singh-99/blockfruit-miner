cmake_minimum_required(VERSION 3.16.3)

project(
  BlockFruit
  LANGUAGES C CXX ASM
  DESCRIPTION "Yet another miner [-_-]"
)

include(CMakePrintHelpers)
include (CheckIncludeFile)
cmake_print_variables(CMAKE_HOST_SYSTEM_NAME)

# Basic configs
set(CMAKE_BUILD_TYPE Release)

set(CMAKE_C_COMPILER clang)
set(CMAKE_CXX_COMPILER clang++)
set(CMAKE_C_FLAGS_RELEASE "${CMAKE_C_FLAGS_RELEASE} -Wno-deprecated")
set(CMAKE_CXX_FLAGS_RELEASE "${CMAKE_CXX_FLAGS_RELEASE} -Wno-deprecated")
set(CMAKE_COLOR_DIAGNOSTICS ON)
set(CFLAGS "${CFLAGS} -fdiagnostics-color=always")
set(CXXFLAGS "${CXXFLAGS} -fdiagnostics-color=always")

# Specify C++ standard
set (CMAKE_CXX_STANDARD 20)
set (CMAKE_STANDARD_REQUIRED TRUE)

string(TIMESTAMP M_VERSION "%y%j.%H.d")
set(PROJECT_VERSION ${M_VERSION})
set(BF_OUTPUT_NAME "BlockFruit-${M_VERSION}")
cmake_print_variables(BF_OUTPUT_NAME)

include_directories(include)

set(SOURCES
    src/main.cpp
    src/utils/terminal.cpp
)

list(APPEND CMAKE_MODULE_PATH "${PROJECT_SOURCE_DIR}/cmake")

add_executable(BlockFruit ${SOURCES})