cmake_minimum_required(VERSION 2.8)
project(Sandbox)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

add_subdirectory(images)

set(INCLUDE_DIR include)
set(SOURCE_DIR src)

include_directories(${SDL2_INCLUDE_DIRS} ${SDL2IMAGE_INCLUDE_DIRS} ${INCLUDE_DIR})

set(SOURCE_FILES
    ${SOURCE_DIR}/main.cpp
    ${SOURCE_DIR}/CollectibleTile.cpp
    ${SOURCE_DIR}/Event.cpp
    ${SOURCE_DIR}/Game.cpp
    ${SOURCE_DIR}/GameLoop.cpp
    ${SOURCE_DIR}/Hero.cpp
    ${SOURCE_DIR}/Map.cpp
    ${SOURCE_DIR}/MapEntity.cpp
    ${SOURCE_DIR}/Tile.cpp
    ${SOURCE_DIR}/Tileset.cpp
    ${SOURCE_DIR}/Video.cpp
)

add_executable(Sandbox ${SOURCE_FILES})

include(FindPkgConfig)

pkg_search_module(SDL2 REQUIRED sdl2)
pkg_search_module(SDL2IMAGE REQUIRED SDL2_image>=2.0.0)

target_link_libraries(Sandbox ${SDL2_LIBRARIES} ${SDL2IMAGE_LIBRARIES})