#include "CollectibleTile.h"

CollectibleTile::CollectibleTile(
        SDL_Surface * collectedImg,
        SDL_Rect* uncollectedImgLoc,
        SDL_Rect* loc,
        SDL_Rect* dest
    ): uncollectedImageLocation(uncollectedImgLoc), collected(false), Tile(collectedImg, loc, dest) {

}

void CollectibleTile::collect() {
    collected = true;
}

bool CollectibleTile::isCollected() const {
    return collected;
}

void CollectibleTile::render(Video* vid) {
    if(!collected) {
        SDL_BlitSurface(image, locationInTileset, vid->getMainSurface(), mapDestination);
    }
    else {
        SDL_BlitSurface(image, uncollectedImageLocation, vid->getMainSurface(), mapDestination);
    }
}

