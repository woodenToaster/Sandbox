#ifndef SANDBOX_MAP_H
#define SANDBOX_MAP_H

#include <vector>
#include "SDL.h"

#include "CollectibleTile.h"
#include "Hero.h"
#include "MapEntity.h"
#include "Tile.h"
#include "Tileset.h"
#include "Video.h"

class Map {
public:
    Map(Video* vid, Tileset* ts);
    ~Map();

    Video* getVideo() const;

    void init();
    void drawMapEntities();
    void drawCollectibleTiles();
    Hero* getHero() const;
    void removeCollectibleTile(CollectibleTile* cTileToRemove);
    void collectTile(SDL_Rect positionOnMap);
    bool checkCollision(SDL_Rect* entityBox) const;
    Tile* getTileByPosition(int x, int y) const;

private:
    std::vector<MapEntity*> mapEntities;
    std::vector<std::vector<Tile*>> layers;
    std::vector<CollectibleTile*> collectibleTiles;
    Video* video;
    Tileset* tileset;
    Hero* hero;

};

#endif //SANDBOX_MAP_H
