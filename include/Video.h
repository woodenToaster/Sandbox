#ifndef SANDBOX_VIDEO_H
#define SANDBOX_VIDEO_H

#include "SDL.h"

class Video {

public:
    Video();
    ~Video();
    void init();
    SDL_Window* getWindow();
    void setSurface(SDL_Surface* newSurface);
    void fillRect(int r, int g, int b);
    void update();

private:
    SDL_Window* window;
    SDL_Surface* surface;
};

#endif //SANDBOX_VIDEO_H
