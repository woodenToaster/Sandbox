#include "Tile.h"

Tile::Tile(SDL_Surface* img, SDL_Rect* loc, SDL_Rect* dest, int layer):
        image(img),
        locationInTileset(loc),
        mapDestination(dest),
        layer(layer) {

}

Tile::~Tile() {
    delete image;
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

void Tile::render(Video* vid) {
    SDL_BlitSurface(image, locationInTileset, vid->getMainSurface(), mapDestination);
}

void Tile::draw(Game* game, Map* map) {

}

void Tile::collect() {

}

int Tile::getLayer() {
    return layer;
}
