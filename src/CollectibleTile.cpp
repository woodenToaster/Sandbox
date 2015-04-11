#include "CollectibleTile.h"
#include "Map.h"

CollectibleTile::CollectibleTile(
        SDL_Surface * collectedImg,
        SDL_Rect* uncollectedImgLoc,
        SDL_Rect* loc,
        SDL_Rect* dest
    ): uncollectedImageLocation(uncollectedImgLoc), collected(false), Tile(collectedImg, loc, dest, 3) {

}

void CollectibleTile::collect() {
    collected = true;
}

bool CollectibleTile::isCollected() const {
    return collected;
}

void CollectibleTile::draw(Map* map) {
    if(!collected) {
        SDL_BlitSurface(image, locationInTileset, map->getVideo()->getMainSurface(), mapDestination);
    }
    else {
        SDL_BlitSurface(image, uncollectedImageLocation, map->getVideo()->getMainSurface(), mapDestination);
    }

    //Draw bounding box
    //SDL_FillRect(vid->getMainSurface(), this->getMapDestination(), SDL_MapRGB(image->format, 127, 127, 127));
}

