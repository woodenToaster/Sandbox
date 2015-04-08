#ifndef SANDBOX_COLLECTIBLETILE_H
#define SANDBOX_COLLECTIBLETILE_H

#include "Tile.h"

class CollectibleTile : public Tile {
public:
    CollectibleTile(SDL_Surface * collectedImg, SDL_Rect* uncollectedImgLoc, SDL_Rect* loc);

private:
    SDL_Rect* uncollectedImageLocation;
    bool collected;

};

#endif //SANDBOX_COLLECTIBLETILE_H
