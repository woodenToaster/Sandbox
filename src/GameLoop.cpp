#include "GameLoop.h"
#include "SDL.h"

GameLoop::GameLoop(): running(true) {
    video = new Video();
    video->init();
}

GameLoop::~GameLoop() {
    delete video;
}

Video* GameLoop::getVideo() {
    return video;
}

void GameLoop::run() {
    while(running) {
        SDL_Event event;
        while(SDL_PollEvent(&event)) {
            switch(event.window.event) {
                case SDL_WINDOWEVENT_CLOSE:
                    running = false;
                    break;
                case SDL_WINDOWEVENT_RESIZED:
                    video->setSurface(SDL_GetWindowSurface(video->getWindow()));
                    video->fillRect(0, 0, 0);
                    video->update();
                    break;
                default:
                    break;
            }
        }
        SDL_Delay(30);
    }
}