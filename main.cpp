#include <iostream>
#include "SDL.h"


int main() {

    if(SDL_Init(SDL_INIT_VIDEO | SDL_INIT_EVENTS) != 0) {
        std::cerr << "Error initializing SDL: " << SDL_GetError() << '\n';
    }

    SDL_Window* window = SDL_CreateWindow(
            "First Window",
            SDL_WINDOWPOS_CENTERED,
            SDL_WINDOWPOS_CENTERED,
            640,
            480,
            SDL_WINDOW_RESIZABLE
    );

    SDL_Surface* surface = SDL_GetWindowSurface(window);

    while(1) {
        SDL_FillRect(surface, NULL, SDL_MapRGB(surface->format, 0x0, 0x0, 0x0));
        SDL_UpdateWindowSurface(window);
        SDL_Event event;
        while(SDL_PollEvent(&event)) {
            if(event.window.event == SDL_WINDOWEVENT_CLOSE) {
                SDL_Quit();
                return 0;
            }
        }
    }

    return 0;


}