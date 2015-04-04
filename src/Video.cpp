#include <iostream>
#include "Video.h"

Video::Video(): window(nullptr), surface(nullptr) {
    if(SDL_Init(SDL_INIT_VIDEO | SDL_INIT_EVENTS) != 0) {
        std::cerr << "Error initializing SDL: " << SDL_GetError() << '\n';
    }
}

Video::~Video() {
    SDL_Quit();
}

void Video::init() {
    window = SDL_CreateWindow(
        "First Window",
        SDL_WINDOWPOS_CENTERED,
        SDL_WINDOWPOS_CENTERED,
        640,
        480,
        SDL_WINDOW_RESIZABLE
    );

    surface = SDL_GetWindowSurface(window);

    SDL_FillRect(surface, NULL, SDL_MapRGB(surface->format, 0x0, 0x0, 0x0));
    SDL_UpdateWindowSurface(window);
}

SDL_Window* Video::getWindow() {
    return window;
}

SDL_Surface* Video::getSurface() {
    return surface;
}

void Video::setSurface(SDL_Surface *newSurface) {
    surface = newSurface;
}