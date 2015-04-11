#ifndef SANDBOX_TILE_H
#define SANDBOX_TILE_H

#include "SDL.h"

#include "MapEntity.h"
#include "Video.h"

class Tile : public MapEntity {
public:
    Tile(SDL_Surface* img, SDL_Rect* loc, SDL_Rect* dest, int layer);
    ~Tile();
    SDL_Surface* getImage();
    SDL_Rect* getLocationInTileset() const;
    SDL_Rect* getMapDestination() const;
    int getLayer();
    virtual void draw(Game* game, Map* map);
    virtual void render(Video* vid);
    virtual void collect();

protected:
    SDL_Surface* image;
    SDL_Rect* locationInTileset;
    SDL_Rect* mapDestination;
    int layer;
};

#endif //SANDBOX_TILE_H
