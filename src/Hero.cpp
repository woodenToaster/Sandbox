#include "SDL.h"
#include "SDL_image.h"

#include "Hero.h"

Hero::Hero(char const* file): locationOnSpritesheet(new SDL_Rect{0, 0, 36, 52}) {
    MapEntity::image = IMG_Load(file);
    MapEntity::locationOnMap = new SDL_Rect{100, 50, 36, 52};
}

Hero::~Hero() {
    delete image;
}

void Hero::setX(int newX) {
    getCurrentMapLocation()->x = newX;
}

void Hero::setY(int newY) {
    getCurrentMapLocation()->y = newY;
}

void Hero::draw(Video* vid, SDL_Rect* dest) {
    SDL_BlitSurface(image, locationOnSpritesheet, vid->getMainSurface(), dest);
}

//TODO: Figure out how inheritance works
void Hero::draw(Map* map) {

}

SDL_Rect* Hero::update(Uint8 const* keyState) {

    if(keyState[SDL_SCANCODE_UP]) {
        getCurrentMapLocation()->y = getY() - 1;
    }
    if(keyState[SDL_SCANCODE_DOWN]) {
        getCurrentMapLocation()->y = getY() + 1;
    }
    if(keyState[SDL_SCANCODE_LEFT]) {
        getCurrentMapLocation()->x = getX() - 1;
    }
    if(keyState[SDL_SCANCODE_RIGHT]) {
        getCurrentMapLocation()->x = getX() + 1;
    }

    return getCurrentMapLocation();
}

