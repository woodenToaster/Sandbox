#ifndef SANDBOX_COLLECTIBLETILE_H
#define SANDBOX_COLLECTIBLETILE_H

#include "Tile.h"

class CollectibleTile : public Tile {
public:
    CollectibleTile(
            SDL_Surface * collectedImg,
            SDL_Rect* uncollectedImgLoc,
            SDL_Rect* loc,
            SDL_Rect* dest
    );

    bool isCollected() const;
    void collect();
    void render(Video* vid);


private:
    SDL_Rect* uncollectedImageLocation;
    bool collected;

};

#endif //SANDBOX_COLLECTIBLETILE_H
