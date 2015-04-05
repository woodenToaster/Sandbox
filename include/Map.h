#ifndef SANDBOX_MAP_H
#define SANDBOX_MAP_H

#include <vector>
#include "Tile.h"
#include "Video.h"

class Map {
public:
    Map(Video* vid, char* file);
    ~Map();
    void init();
    void render();

private:
    std::vector<Tile*> tiles;
    SDL_Surface* tileset;
    Video* video;

};

#endif //SANDBOX_MAP_H
