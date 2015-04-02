cmake_minimum_required(VERSION 3.1)
project(Sandbox)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES main.cpp)
add_executable(Sandbox ${SOURCE_FILES})

include(FindPkgConfig)

pkg_search_module(SDL2 REQUIRED sdl2)

include_directories(${SDL2_INCLUDE_DIRS})
target_link_libraries(Sandbox ${SDL2_LIBRARIES})

