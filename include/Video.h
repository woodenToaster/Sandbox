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
    void fillRect(int r, int g, int b);
    void update();
    void setSurfaceToMain();


private:
    SDL_Window* window;
    SDL_Surface* surface;
};

#endif //SANDBOX_VIDEO_H
