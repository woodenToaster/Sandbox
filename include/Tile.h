#ifndef SANDBOX_TILE_H
#define SANDBOX_TILE_H

#include "SDL.h"
#include "Video.h"

class Tile {
public:
    Tile(SDL_Surface* img, SDL_Rect* loc, SDL_Rect* dest);
    ~Tile();
    SDL_Surface* getImage();
    SDL_Rect* getLocationInTileset() const;
    SDL_Rect* getMapDestination() const;
    virtual void render(Video* vid);
    virtual void collect();

protected:
    SDL_Surface* image;
    SDL_Rect* locationInTileset;
    SDL_Rect* mapDestination;
};

#endif //SANDBOX_TILE_H
