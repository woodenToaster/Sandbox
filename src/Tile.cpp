#include "Tile.h"

Tile::Tile() {

}

Tile::Tile(SDL_Surface* img, SDL_Rect* loc): image(img), location(loc) {

}

Tile::~Tile() {
    delete image;
    delete location;
}

SDL_Surface* Tile::getImage() {
    return image;
}

SDL_Rect* Tile::getLocationInTileset() {
    return location;
}

void Tile::render(Video* vid, SDL_Rect* dest) {
    SDL_BlitSurface(image, location, vid->getMainSurface(), dest);
}