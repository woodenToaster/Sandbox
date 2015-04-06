#include "CollectibleTile.h"

CollectibleTile::CollectibleTile(SDL_Surface * collectedImg, SDL_Surface* uncollectedImg, SDL_Rect* loc):
    uncollectedImage(uncollectedImg),
    collected(false),
    Tile(collectedImg, loc) {

}

