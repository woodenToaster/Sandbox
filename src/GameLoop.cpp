#include <iostream>
#include "GameLoop.h"

GameLoop::GameLoop(Game* game): game(game), running(true) {
    event = new Event();
}

GameLoop::~GameLoop() {
    delete event;
}

void GameLoop::run() {
    Uint32 ticks;
    Uint32 last_frame_time = 0;

    int heroX;
    int heroY;

    while(running) {

        while(event->pollEvent()) {
            processEvent(event->getType());
        }

        const Uint8* currentKeyStates = SDL_GetKeyboardState(NULL);

        if(currentKeyStates[SDL_SCANCODE_ESCAPE]) {
            running = false;
        }

        SDL_Rect* heroLocation = game->getCurrentMap()->getHero()->update(currentKeyStates);

        game->getCurrentMap()->collectTile(*heroLocation);

        //TODO: Figure out high cpu usage
        SDL_Delay(10);

        ticks = SDL_GetTicks();
        if(ticks >= last_frame_time + FRAME_DELAY) {
            last_frame_time = ticks;
            update();
        }
    }
}

void GameLoop::update() {
    game->getCurrentMap()->drawMapEntities();

    //Draw hero bounding box
//    SDL_Rect* heroLocation = game->getCurrentMap()->getHero()->getCurrentMapLocation();
//    SDL_Surface* surface = game->getVideo()->getMainSurface();
//    SDL_FillRect(surface, heroLocation, SDL_MapRGB(surface->format, 127, 127, 127));

    game->getVideo()->update();
}

void GameLoop::processEvent(int type) {
   if(type == Event::WINDOW_CLOSED) {
        running = false;
    }
}