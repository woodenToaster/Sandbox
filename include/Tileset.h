#ifndef SANDBOX_TILESET_H
#define SANDBOX_TILESET_H

#include "SDL.h"

class Tileset {
public:
    Tileset(const char* imgFile);
    ~Tileset();
    int getTilesetImgWidth() const;
    int getTilesetImgHeight() const;
    SDL_Surface* getTilesetImg() const;

private:
    SDL_Surface* tilesetImg;
    int tilesetImgWidth;
    int tilesetImgHeight;

};

#endif //SANDBOX_TILESET_H
