#include "GameLoop.h"

GameLoop::GameLoop(): running(true) {
    video = new Video();
    video->init();
}

GameLoop::~GameLoop() {
    delete video;
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
                    update();
                    break;
                default:
                    break;
            }
        }
        video->delay(30);
    }
}

void GameLoop::update() {
    video->setSurfaceToMain();
    video->fillRect(0, 0, 0);
    video->update();
}