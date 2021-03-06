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
        "Sandbox",
        SDL_WINDOWPOS_CENTERED,
        SDL_WINDOWPOS_CENTERED,
        640,
        480,
        0
    );

    surface = SDL_GetWindowSurface(window);
    fillRect(0, 0, 0);
    update();
}

SDL_Surface* Video::getMainSurface() {
    return surface;
}

SDL_Window* Video::getMainWindow() {
    return window;
}

void Video::setSurfaceToMain() {
    surface = SDL_GetWindowSurface(window);
}

void Video::fillRect(Uint8 r, Uint8 g, Uint8 b) {
    SDL_FillRect(surface, NULL, SDL_MapRGB(surface->format, r, g, b));
}

void Video::update() {
    SDL_UpdateWindowSurface(window);
}

