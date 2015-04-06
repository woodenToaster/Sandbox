#include "Tileset.h"

#include "SDL_image.h"

Tileset::Tileset(const char* imgFile) {
    tilesetImg = IMG_Load(imgFile);
    tilesetImgWidth = tilesetImg->w;
    tilesetImgHeight = tilesetImg->h;
}

Tileset::~Tileset() {
    delete tilesetImg;
}

int Tileset::getTilesetImgWidth() const {
    return tilesetImgWidth;
}

int Tileset::getTilesetImgHeight() const {
    return tilesetImgHeight;
}

SDL_Surface* Tileset::getTilesetImg() const {
    return tilesetImg;
}
