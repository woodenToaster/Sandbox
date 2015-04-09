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

Hero* Map::getHero() const {
    return hero;
}

void Map::init() {

    SDL_Rect* locationInTileset = new SDL_Rect{0, 0, 32, 32};
    for(int y = 0; y < 15; ++y) {
        for(int x = 0; x < 20; ++x) {
            SDL_Rect* destinationInMap = new SDL_Rect{x * 32, y * 32, 32, 32};
            Tile* tile1 = new Tile(tileset->getTilesetImg(), locationInTileset, destinationInMap);
            tiles.push_back(tile1);
        }
    }

    SDL_Rect* collectibleLocation = new SDL_Rect{64, 0, 32, 32};
    SDL_Rect* cDest = new SDL_Rect{64, 64, 32, 32};
    CollectibleTile* cTile;
    cTile = new CollectibleTile(tileset->getTilesetImg(), locationInTileset, collectibleLocation, cDest);
    tiles.push_back(cTile);
}

void Map::collectTile(SDL_Rect positionOnMap) {
    for(Tile* tile : tiles) {
        if((positionOnMap.x > tile->getMapDestination()->x) && (positionOnMap.x < tile->getMapDestination()->x + 32) &&
           (positionOnMap.y > tile->getMapDestination()->y) && (positionOnMap.y < tile->getMapDestination()->y + 32)) {
            tile->collect();
            std::cout << "OVerlapped" << '\n';
        }
    }
}

void Map::render() {
    int i = 0;
    for(int y = 0; y < 15; ++y) {
        for(int x = 0; x < 20; ++x) {
            tiles[i]->render(video);
            i++;
        }

    }

    tiles[tiles.size() - 1]->render(video);

    SDL_Rect* heroDest = new SDL_Rect{hero->getX(), hero->getY()};
    hero->draw(video, heroDest);
}