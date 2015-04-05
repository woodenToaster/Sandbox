#include <iostream>
#include "Map.h"
#include "SDL_image.h"

Map::Map(Video* vid, char* file): video(vid) {
    IMG_Init(IMG_INIT_PNG);
    tileset = IMG_Load(file);
    if(!tileset) {
        std::cout << "Error" << '\n';
        std::cout << IMG_GetError() << '\n';
    }
}

Map::~Map() {
    delete video;
    IMG_Quit();
}

void Map::init() {

    SDL_Rect* location = new SDL_Rect{0, 32, 32, 32};
    Tile* tile1 = new Tile(tileset, location);
    tiles.push_back(tile1);
}

void Map::render() {
    for(int i = 0; i < tiles.size(); ++i) {
        tiles[i]->render(video);
    }
}