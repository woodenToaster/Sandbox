#include "Map.h"
#include "Tile.h"

Tile::Tile(SDL_Surface* img, SDL_Rect* loc, SDL_Rect* dest, int layer):
        image(img),
        locationInTileset(loc),
        mapDestination(dest),
        layer(layer),
        blocking(false) {

}

Tile::~Tile() {
    delete locationInTileset;
}

SDL_Surface* Tile::getImage() {
    return image;
}

SDL_Rect* Tile::getLocationInTileset() const{
    return locationInTileset;
}

SDL_Rect* Tile::getMapDestination() const {
    return mapDestination;
}

void Tile::draw(Map* map) {
    SDL_BlitSurface(image, locationInTileset, map->getVideo()->getMainSurface(), mapDestination);
}

void Tile::collect() {

}

int Tile::getLayer() {
    return layer;
}

bool Tile::isBlockingTile() {
    return blocking;
}

void Tile::setBlocking(bool b) {
    blocking = b;
}

bool Tile::contains(int x, int y) {
    bool x1 = x > locationOnMap->x;
    bool x2 = x < locationOnMap->x + locationOnMap->w;
    bool y1 = y > locationOnMap->y;
    bool y2 = y < locationOnMap->y + locationOnMap->h;

    return x1 && x2 && y1 && y2;
}

bool Tile::overlaps(SDL_Rect *entityBox) {
    int x1 = locationOnMap->x;
    int x2 = locationOnMap->x + locationInTileset->w;
    int x3 = entityBox->x;
    int x4 = entityBox->x + entityBox->w;

    bool x_overlaps = x3 < x2 && x1 < x4;

    int y1 = locationOnMap->y;
    int y2 = locationOnMap->y + locationInTileset->h;
    int y3 = entityBox->y;
    int y4 = entityBox->y + entityBox->h;

    bool y_overlaps = y3 < y2 && y1 < y4;

    return x_overlaps && y_overlaps;
}
