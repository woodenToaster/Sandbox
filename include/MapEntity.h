#ifndef SANDBOX_MAPENTITY_H
#define SANDBOX_MAPENTITY_H

#include "SDL.h"

class Map;
class Game;

class MapEntity {
public:
    virtual ~MapEntity();
    virtual void draw(Map* map) = 0;
    virtual bool checkCollision();

    int getX() const;
    int getY() const;
    int getW() const;
    int getH() const;

    SDL_Rect* getCurrentMapLocation() const;

protected:
    SDL_Rect* locationOnMap;
    SDL_Surface* image;
};

#endif //SANDBOX_MAPENTITY_H
