#include <MapEntity.h>

MapEntity::~MapEntity() {
    delete locationOnMap;
    delete image;
}

bool MapEntity::checkCollision() {
    return false;
}

int MapEntity::getX() const {
    return locationOnMap->x;
}

int MapEntity::getY() const {
    return locationOnMap->y;
}

int MapEntity::getW() const {
    return locationOnMap->w;
}

int MapEntity::getH() const {
    return locationOnMap->h;
}

SDL_Rect *MapEntity::getCurrentMapLocation() const {
    return locationOnMap;
}
