#include "SDL.h"
#include "SDL_image.h"

#include "Hero.h"

Hero::Hero(char const* file) {
    image = IMG_Load(file);
    locationOnSpritesheet = new SDL_Rect{0, 0, 36, 52};
    x = 100;
    y = 50;
}

Hero::~Hero() {
    delete image;
}

double Hero::getX() const {
    return x;
}

double Hero::getY() const {
    return y;
}

void Hero::draw(Video* vid, SDL_Rect* dest) {
    SDL_BlitSurface(image, locationOnSpritesheet, vid->getMainSurface(), dest);
}