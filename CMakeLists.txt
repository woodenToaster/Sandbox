cmake_minimum_required(VERSION 3.1)
project(Sandbox)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")
set(SOURCE_DIR src)
set(SOURCE_FILES
    ${SOURCE_DIR}/main.cpp
    ${SOURCE_DIR}/Video.cpp
    ${SOURCE_DIR}/Game.cpp
    ${SOURCE_DIR}/GameLoop.cpp
    ${SOURCE_DIR}/Event.cpp
    ${SOURCE_DIR}/Tile.cpp
    ${SOURCE_DIR}/Map.cpp
    ${SOURCE_DIR}/Tileset.cpp
)

set(INCLUDE_DIR include)

add_executable(Sandbox ${SOURCE_FILES})

include(FindPkgConfig)

pkg_search_module(SDL2 REQUIRED sdl2)
pkg_search_module(SDL2IMAGE REQUIRED SDL2_image>=2.0.0)

include_directories(${SDL2_INCLUDE_DIRS} ${SDL2IMAGE_INCLUDE_DIRS} ${INCLUDE_DIR})
target_link_libraries(Sandbox ${SDL2_LIBRARIES} ${SDL2IMAGE_LIBRARIES})

