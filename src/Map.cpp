#include <iostream>
#include "Map.h"
#include "SDL_image.h"

Map::Map(Video* vid, char* file): video(vid) {
    IMG_Init(IMG_INIT_PNG);
    tileset = IMG_Load(file);
    if(!tileset) {
        std::cout << IMG_GetError();
    }
}

Map::~Map() {
    delete video;
    for(Tile* tile : tiles) {
        delete tile;
    }
    IMG_Quit();
}

void Map::init() {

    for(int y = 0; y < 15; ++y) {
        for(int x = 0; x < 20; ++x) {
            SDL_Rect* location = new SDL_Rect{0, 32, 32, 32};
            Tile* tile1 = new Tile(tileset, location);
            tiles.push_back(tile1);
        }
    }
}

void Map::render() {
    int i = 0;
    for(int y = 0; y < 15; ++y) {
        for(int x = 0; x < 20; ++x) {
            SDL_Rect* dest = new SDL_Rect{x * 32, y * 32, 32, 32};
            tiles[i]->render(video, dest);
            i++;
        }

    }
}