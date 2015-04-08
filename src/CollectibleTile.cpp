#include "CollectibleTile.h"

CollectibleTile::CollectibleTile(SDL_Surface * collectedImg, SDL_Rect* uncollectedImgLoc, SDL_Rect* loc):
    uncollectedImageLocation(uncollectedImgLoc),
    collected(false),
    Tile(collectedImg, loc) {

}

