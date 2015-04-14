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
    int getLayer();
    void draw(Map* map);
    bool isBlockingTile();
    void setBlocking(bool b);
    virtual void collect();
    bool contains(int x, int y);
    bool overlaps(SDL_Rect entityBox);

protected:
    SDL_Rect* locationInTileset;
    int layer;
    bool blocking;
};

#endif //SANDBOX_TILE_H
