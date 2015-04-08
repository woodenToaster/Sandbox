#ifndef SANDBOX_TILE_H
#define SANDBOX_TILE_H

#include "SDL.h"
#include "Video.h"

class Tile {
public:
    Tile(SDL_Surface* img, SDL_Rect* loc);
    ~Tile();
    SDL_Surface* getImage();
    SDL_Rect* getLocationInTileset();
    void render(Video* vid, SDL_Rect* dest);

protected:
    SDL_Surface* image;
    SDL_Rect* location;
};

#endif //SANDBOX_TILE_H
