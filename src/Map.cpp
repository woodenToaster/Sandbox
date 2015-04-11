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

    //Make grass floor tiles
    SDL_Rect* locationInTileset = new SDL_Rect{0, 0, 32, 32};
    for(int y = 0; y < 15; ++y) {
        for(int x = 0; x < 20; ++x) {
            SDL_Rect* destinationInMap = new SDL_Rect{x * 32, y * 32, 32, 32};
            Tile* tile1 = new Tile(tileset->getTilesetImg(), locationInTileset, destinationInMap, 0);
            layer0Tiles.push_back(tile1);
        }
    }

    //Make pillars
    SDL_Rect* pillarLocationInTileset = new SDL_Rect{456, 160, 16, 32};
    for(int i = 0; i < 6; ++i) {
        SDL_Rect* pillarDestination = new SDL_Rect{8 * 32 + 16 * i, 8 * 32};
        Tile* pillar = new Tile(tileset->getTilesetImg(), pillarLocationInTileset, pillarDestination, 1);
        layer1Tiles.push_back(pillar);
    }


    //Make collectible grass tile
    SDL_Rect* collectibleLocation = new SDL_Rect{64, 0, 32, 32};
    SDL_Rect* cDest = new SDL_Rect{64, 64, 32, 32};
    CollectibleTile* cTile;
    cTile = new CollectibleTile(tileset->getTilesetImg(), locationInTileset, collectibleLocation, cDest);
    collectibleTiles.push_back(cTile);
}

void Map::collectTile(SDL_Rect positionOnMap) {
    for(CollectibleTile* cTile : collectibleTiles) {

        int x1 = cTile->getMapDestination()->x;
        int x2 = cTile->getMapDestination()->x + 32;
        int x3 = positionOnMap.x;
        int x4 = positionOnMap.x + 32;

        bool x_overlaps = x3 < x2 && x1 < x4;

        int y1 = cTile->getMapDestination()->y;
        int y2 = cTile->getMapDestination()->y + 36;
        int y3 = positionOnMap.y;
        int y4 = positionOnMap.y + 56;

        bool y_overlaps = y3 < y2 && y1 < y4;

        bool overlaps = x_overlaps && y_overlaps;

        if(overlaps && !cTile->isCollected()) {
            cTile->collect();
            removeCollectibleTile(cTile);
            std::cout << "Overlapped" << '\n';
        }
    }
}

void Map::drawMapEntities() {

    drawLayer0Tiles();
    drawLayer1Tiles();
    drawCollectibleTiles();

    SDL_Rect* heroDest = new SDL_Rect{hero->getX(), hero->getY()};
    hero->draw(video, heroDest);
}

void Map::removeCollectibleTile(CollectibleTile *cTileToRemove) {
    for(int i = 0; i < collectibleTiles.size(); ++i) {
        if(collectibleTiles[i] == cTileToRemove) {
            collectibleTiles.erase(collectibleTiles.begin() + i);
        }
    }
}

void Map::drawLayer0Tiles() {
    for(Tile* tile : layer0Tiles) {
        tile->render(video);
    }
}

void Map::drawLayer1Tiles() {
    for(Tile* tile : layer1Tiles) {
        tile->render(video);
    }
}

void Map::drawCollectibleTiles() {
    for(CollectibleTile* cTile : collectibleTiles) {
        cTile->render(video);
    }
}
