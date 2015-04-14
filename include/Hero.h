#ifndef SANDBOX_HERO_H
#define SANDBOX_HERO_H

#include "MapEntity.h"
#include "Video.h"

class Map;
class Game;

class Hero : public MapEntity {
public:
    enum Facing {
        NORTH,
        SOUTH,
        EAST,
        WEST
    };

    Hero(char const* file);
    ~Hero();
    void draw(Map* map);
    SDL_Rect* update(Uint8 const* keyState, Map* map);
    bool checkCollision(Map* map, SDL_Rect desiredLocation) override;
    void setX(int newX);
    void setY(int newY);
    SDL_Rect getMoveUpBoundingBox();
    SDL_Rect getMoveDownBoundingBox();
    SDL_Rect getMoveLeftBoundingBox();
    SDL_Rect getMoveRightBoundingBox();

private:
    SDL_Rect* locationOnSpritesheet;
};

#endif //SANDBOX_HERO_H
