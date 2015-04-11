#ifndef SANDBOX_HERO_H
#define SANDBOX_HERO_H

#include "MapEntity.h"
#include "Video.h"

class Map;
class Game;

class Hero : public MapEntity {
public:
    Hero(char const* file);
    ~Hero();
    void draw(Map* map);
    void draw(Video* vid, SDL_Rect* dest);
    SDL_Rect* update(Uint8 const* keyState);

    void setX(int newX);
    void setY(int newY);

private:
    SDL_Rect* locationOnSpritesheet;
};

#endif //SANDBOX_HERO_H
