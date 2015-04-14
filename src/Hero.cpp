#include "SDL.h"
#include "SDL_image.h"

#include <iostream>

#include "Hero.h"
#include "Map.h"

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

void Hero::draw(Map* map) {
    SDL_BlitSurface(image, locationOnSpritesheet, map->getVideo()->getMainSurface(), locationOnMap);
}

SDL_Rect* Hero::update(Uint8 const* keyState, Map* map) {

    if(keyState[SDL_SCANCODE_UP]) {
        if(!checkCollision(map, getMoveUpBoundingBox())) {
            getCurrentMapLocation()->y = getY() - 1;
        }
    }
    if(keyState[SDL_SCANCODE_DOWN]) {
        if(!checkCollision(map, getMoveDownBoundingBox())) {
            getCurrentMapLocation()->y = getY() + 1;
        }
    }
    if(keyState[SDL_SCANCODE_LEFT]) {
        if(!checkCollision(map, getMoveLeftBoundingBox())) {
            getCurrentMapLocation()->x = getX() - 1;
        }
    }
    if(keyState[SDL_SCANCODE_RIGHT]) {
        if(!checkCollision(map, getMoveRightBoundingBox())) {
            getCurrentMapLocation()->x = getX() + 1;
        }
    }

    return getCurrentMapLocation();
}

bool Hero::checkCollision(Map* map, SDL_Rect desiredLocation) {
    return map->checkCollision(desiredLocation);
}

SDL_Rect Hero::getMoveUpBoundingBox() {
    int x1 = locationOnMap->x;
    int x2 = locationOnMap->x + locationOnMap->w;
    int y1 = locationOnMap->y - 1;
    int y2 = locationOnMap->y + locationOnMap->h - 1;

    return SDL_Rect{x1, y1, x2, y2};
}

SDL_Rect Hero::getMoveDownBoundingBox() {
    int x1 = locationOnMap->x;
    int x2 = locationOnMap->x + locationOnMap->w;
    int y1 = locationOnMap->y + 1;
    int y2 = locationOnMap->y + locationOnMap->h + 1;

    return SDL_Rect{x1, y1, x2, y2};
}

SDL_Rect Hero::getMoveLeftBoundingBox() {
    int x1 = locationOnMap->x - 1;
    int x2 = locationOnMap->x + locationOnMap->w - 1;
    int y1 = locationOnMap->y;
    int y2 = locationOnMap->y + locationOnMap->h;

    return SDL_Rect{x1, y1, x2, y2};
}

SDL_Rect Hero::getMoveRightBoundingBox() {
    int x1 = locationOnMap->x + 1;
    int x2 = locationOnMap->x + locationOnMap->w + 1;
    int y1 = locationOnMap->y;
    int y2 = locationOnMap->y + locationOnMap->h;

    return SDL_Rect{x1, y1, x2, y2};
}
