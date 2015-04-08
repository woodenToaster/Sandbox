#ifndef SANDBOX_HERO_H
#define SANDBOX_HERO_H

#include "Video.h"

class Hero {
public:
    Hero(char const* file);
    ~Hero();
    void draw(Video* vid, SDL_Rect* dest);
    double getX() const;
    double getY() const;

private:
    SDL_Surface* image;
    SDL_Rect* locationOnSpritesheet;
    double x;
    double y;
};

#endif //SANDBOX_HERO_H
