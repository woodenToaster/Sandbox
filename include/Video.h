#ifndef SANDBOX_VIDEO_H
#define SANDBOX_VIDEO_H

#include "SDL.h"

class Video {

public:
    Video();
    ~Video();
    SDL_Surface* getMainSurface();
    SDL_Window* getMainWindow();
    void init();
    void fillRect(Uint8 r, Uint8 g, Uint8 b);
    void update();
    void setSurfaceToMain();


private:
    SDL_Window* window;
    SDL_Surface* surface;
};

#endif //SANDBOX_VIDEO_H
