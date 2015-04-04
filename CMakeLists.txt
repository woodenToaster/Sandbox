cmake_minimum_required(VERSION 3.1)
project(Sandbox)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES src/main.cpp)
set(INCLUDE_DIR include)

add_executable(Sandbox ${SOURCE_FILES} test/catch.hpp test/test.h test/test.cpp src/Video.cpp ${INCLUDE_DIR}/Video.h src/GameLoop.cpp include/GameLoop.h)

include(FindPkgConfig)

pkg_search_module(SDL2 REQUIRED sdl2)

include_directories(${SDL2_INCLUDE_DIRS} ${INCLUDE_DIR})
target_link_libraries(Sandbox ${SDL2_LIBRARIES})

