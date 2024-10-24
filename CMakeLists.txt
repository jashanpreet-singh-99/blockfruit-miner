cmake_minimum_required(VERSION 3.16.3)

project(
  BlockFruit
  LANGUAGES C CXX ASM
  VERSION 0.0.1
  DESCRIPTION "Yet another miner [-_-]"
)
set(TARGET_NAME "BlockFruit")

include(CMakePrintHelpers)
include (CheckIncludeFile)
cmake_print_variables(CMAKE_HOST_SYSTEM_NAME)

# Basic configs
set(CMAKE_BUILD_TYPE Release)

if(APPLE)
    if(NOT DEFINED CMAKE_C_COMPILER)
        set(CMAKE_C_COMPILER /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc)
    endif()
    
    if(NOT DEFINED CMAKE_CXX_COMPILER)
        set(CMAKE_CXX_COMPILER /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++)
    endif()
endif()

set(CMAKE_C_FLAGS_RELEASE "${CMAKE_C_FLAGS_RELEASE} -Wno-deprecated")
set(CMAKE_CXX_FLAGS_RELEASE "${CMAKE_CXX_FLAGS_RELEASE} -Wno-deprecated")
set(CMAKE_COLOR_DIAGNOSTICS ON)

set(CFLAGS "${CFLAGS} -fdiagnostics-color=always")
set(CXXFLAGS "${CXXFLAGS} -fdiagnostics-color=always")

set (CMAKE_CXX_STANDARD 20)
set (CMAKE_STANDARD_REQUIRED TRUE)

string(TIMESTAMP M_VERSION "%y%j.%H.d")
set(PROJECT_VERSION ${M_VERSION})
set(BF_OUTPUT_NAME "BlockFruit-${M_VERSION}")
cmake_print_variables(BF_OUTPUT_NAME)

include(cmake/CPM.cmake)
include(cmake/boost.cmake)

include_directories(include)

set(SOURCES
    src/main.cpp
    src/utils/terminal.cpp
    src/utils/configurations.cpp
)

add_executable(${TARGET_NAME} ${SOURCES})
target_link_libraries(${TARGET_NAME} ${BOOST_LIBS})