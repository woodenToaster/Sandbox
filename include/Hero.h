#ifndef SANDBOX_HERO_H
#define SANDBOX_HERO_H

#include "Video.h"

class Hero {
public:
    Hero(char const* file);
    ~Hero();
    void draw(Video* vid, SDL_Rect* dest);
    int getX() const;
    int getY() const;
    int getWidth() const;
    int getHeight() const;
    void setX(int newX);
    void setY(int newY);

private:
    SDL_Surface* image;
    SDL_Rect* locationOnSpritesheet;
    int x;
    int y;
    int width;
    int height;
};

#endif //SANDBOX_HERO_H
