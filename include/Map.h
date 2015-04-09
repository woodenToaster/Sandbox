#ifndef SANDBOX_MAP_H
#define SANDBOX_MAP_H

#include <vector>
#include "SDL.h"

#include "Hero.h"
#include "Tile.h"
#include "Tileset.h"
#include "Video.h"

class Map {
public:
    Map(Video* vid, Tileset* ts);
    ~Map();
    void init();
    void render();
    Hero* getHero() const;

    void collectTile(SDL_Rect positionOnMap);

private:
    std::vector<Tile*> tiles;
    Video* video;
    Tileset* tileset;
    Hero* hero;

};

#endif //SANDBOX_MAP_H
