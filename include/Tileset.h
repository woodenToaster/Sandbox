#ifndef SANDBOX_TILESET_H
#define SANDBOX_TILESET_H

#include "SDL.h"

class Tileset {
public:
    Tileset();
    ~Tileset();

private:
    SDL_Surface* tilesetImg;

};

#endif //SANDBOX_TILESET_H
