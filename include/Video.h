#ifndef SANDBOX_VIDEO_H
#define SANDBOX_VIDEO_H

#include "SDL.h"

class Video {

public:

    Video();
    ~Video();
    void init();
    SDL_Window* getWindow();
    SDL_Surface* getSurface();
    void setSurface(SDL_Surface* newSurface);

private:
    SDL_Window* window;
    SDL_Surface* surface;


};


#endif //SANDBOX_VIDEO_H
