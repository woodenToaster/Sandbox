cmake_minimum_required(VERSION 3.1)
project(Sandbox)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")
set(CMAKE_INCLUDE_CURRENT_DIR ON)

#add_subdirectory(test)
add_subdirectory(images)

set(INCLUDE_DIR include)
set(SOURCE_DIR src)

include_directories(${SDL2_INCLUDE_DIRS} ${SDL2IMAGE_INCLUDE_DIRS} ${INCLUDE_DIR})

set(SOURCE_FILES
    ${SOURCE_DIR}/main.cpp
    ${SOURCE_DIR}/Video.cpp
    ${SOURCE_DIR}/Game.cpp
    ${SOURCE_DIR}/GameLoop.cpp
    ${SOURCE_DIR}/Event.cpp
    ${SOURCE_DIR}/Tile.cpp
    ${SOURCE_DIR}/CollectibleTile.cpp
    ${SOURCE_DIR}/Map.cpp
    ${SOURCE_DIR}/Tileset.cpp
)

add_executable(Sandbox ${SOURCE_FILES})

include(FindPkgConfig)

pkg_search_module(SDL2 REQUIRED sdl2)
pkg_search_module(SDL2IMAGE REQUIRED SDL2_image>=2.0.0)

target_link_libraries(Sandbox ${SDL2_LIBRARIES} ${SDL2IMAGE_LIBRARIES})