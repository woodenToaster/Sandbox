#ifndef SANDBOX_MAP_H
#define SANDBOX_MAP_H

#include <vector>
#include "Tile.h"
#include "Tileset.h"
#include "Video.h"

class Map {
public:
    Map(Video* vid, Tileset* ts);
    ~Map();
    void init();
    void render();

private:
    std::vector<Tile*> tiles;
    Video* video;
    Tileset* tileset;

};

#endif //SANDBOX_MAP_H
