#ifndef SANDBOX_MAPENTITY_H
#define SANDBOX_MAPENTITY_H

#include "SDL.h"

class Map;
class Game;

class MapEntity {
public:
    virtual ~MapEntity();
    virtual void draw(Game* game, Map* map) = 0;
    virtual bool checkCollision();

private:
    SDL_Rect* locationOnMap;
    SDL_Surface* image;
};

#endif //SANDBOX_MAPENTITY_H
