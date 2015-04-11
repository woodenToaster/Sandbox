#include <MapEntity.h>

MapEntity::~MapEntity() {
    delete locationOnMap;
    delete image;
}

bool MapEntity::checkCollision() {
    return false;
}
