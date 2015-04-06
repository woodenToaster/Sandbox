#include <iostream>
#include "Map.h"

Map::Map(Video* vid, Tileset* ts):
    video(vid),
    tileset(ts) {
}

Map::~Map() {
    delete tileset;
}

void Map::init() {

    for(int y = 0; y < 15; ++y) {
        for(int x = 0; x < 20; ++x) {
            SDL_Rect* location = new SDL_Rect{0, 32, 32, 32};
            Tile* tile1 = new Tile(tileset->getTilesetImg(), location);
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