#include <iostream>
#include "CollectibleTile.h"
#include "Map.h"

Map::Map(Video* vid, Tileset* ts):
    video(vid),
    tileset(ts) {
    hero = new Hero("images/hero.png");
}

Map::~Map() {
    delete tileset;
}

void Map::init() {

    SDL_Rect* location = new SDL_Rect{0, 0, 32, 32};
    for(int y = 0; y < 15; ++y) {
        for(int x = 0; x < 20; ++x) {
            Tile* tile1 = new Tile(tileset->getTilesetImg(), location);
            tiles.push_back(tile1);
        }
    }

    SDL_Rect* collectibleLocation = new SDL_Rect{64, 0, 32, 32};
    CollectibleTile* cTile = new CollectibleTile(tileset->getTilesetImg(), location, collectibleLocation);
    tiles.push_back(cTile);
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
    SDL_Rect* cDest = new SDL_Rect{64, 64, 32, 32};
    tiles[tiles.size() - 1]->render(video, cDest);

    SDL_Rect* heroDest = new SDL_Rect{hero->getX(), hero->getY()};
    hero->draw(video, heroDest);
}