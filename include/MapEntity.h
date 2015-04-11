#ifndef SANDBOX_MAPENTITY_H
#define SANDBOX_MAPENTITY_H

#include "Map.h"

#include "SDL.h"

class MapEntity {
public:
    virtual void draw() = 0;
    virtual bool checkCollision(MapEntity* other, Map* map) = 0;

private:
    SDL_Rect* locationOnMap;
    SDL_Surface* image;


};
#endif //SANDBOX_MAPENTITY_H
