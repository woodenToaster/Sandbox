#include "Tile.h"

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

void Tile::render(Video* vid) {
    SDL_Rect dest = {0, 0, 32, 32};

    SDL_BlitSurface(image, location, vid->getMainSurface(), &dest);
}