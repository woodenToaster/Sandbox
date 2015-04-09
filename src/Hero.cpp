#include "SDL.h"
#include "SDL_image.h"

#include "Hero.h"

Hero::Hero(char const* file) {
    image = IMG_Load(file);
    locationOnSpritesheet = new SDL_Rect{0, 0, 36, 52};
    x = 100;
    y = 50;
    width = 36;
    height = 36;
}

Hero::~Hero() {
    delete image;
}

int Hero::getX() const {
    return x;
}

int Hero::getY() const {
    return y;
}

void Hero::setX(int newX) {
    x = newX;
}

void Hero::setY(int newY) {
    y = newY;
}

void Hero::draw(Video* vid, SDL_Rect* dest) {
    SDL_BlitSurface(image, locationOnSpritesheet, vid->getMainSurface(), dest);
}

int Hero::getWidth() const {
    return width;
}

int Hero::getHeight() const {
    return height;
}
