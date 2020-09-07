cmake_minimum_required(VERSION 3.8...3.15)
project (mak LANGUAGES CXX)

set (_VERSION_MAJOR 0)
set (_VERSION_MINOR 0)
set (_VERSION_REVISION 2)

configure_file (
  "${PROJECT_SOURCE_DIR}/source/version.h.in"
  "${PROJECT_BINARY_DIR}/gen/version.h"
)

if(NOT CMAKE_BUILD_TYPE)
    set(CMAKE_BUILD_TYPE Release)
endif(NOT CMAKE_BUILD_TYPE)

set(CMAKE_CXX_FLAGS_DEBUG "-Wall -g -D_DEBUG")
set(CMAKE_CXX_FLAGS_RELEASE "-O3")

include_directories(${PROJECT_SOURCE_DIR}/build/gen)

file(GLOB SOURCES "${PROJECT_SOURCE_DIR}/source/*.cpp")

add_subdirectory(${PROJECT_SOURCE_DIR}/include/wxWidgets ${PROJECT_BINARY_DIR}/wxWidgets)
set (wxBUILD_SHARED OFF)

add_executable(mak ${SOURCES})
target_link_libraries(mak wx::net wx::core wx::base)
target_compile_features(mak PUBLIC cxx_std_17)
