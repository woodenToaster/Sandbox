#ifndef SANDBOX_COLLECTIBLETILE_H
#define SANDBOX_COLLECTIBLETILE_H

#include "Tile.h"

class CollectibleTile : Tile {
public:
    CollectibleTile(SDL_Surface * collectedImg, SDL_Surface* uncollectedImg, SDL_Rect* loc);

private:
    SDL_Surface* uncollectedImage;
    bool collected;

};

#endif //SANDBOX_COLLECTIBLETILE_H
