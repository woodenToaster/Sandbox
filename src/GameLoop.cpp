#include "GameLoop.h"

GameLoop::GameLoop(Game* game): game(game), running(true) {
    event = new Event();
}

GameLoop::~GameLoop() {

}

void GameLoop::run() {
    Uint32 ticks;
    Uint32 last_frame_time = 0;

    while(running) {
        while(event->pollEvent()) {
            processEvent(event->getType());
            const Uint8* currentKeyStates = SDL_GetKeyboardState(NULL);
            if(currentKeyStates[SDL_SCANCODE_UP]) {
                game->getCurrentMap()->getHero()->setY(
                        game->getCurrentMap()->getHero()->getY() - 2
                );
            }
            else if(currentKeyStates[SDL_SCANCODE_DOWN]) {
                game->getCurrentMap()->getHero()->setY(
                        game->getCurrentMap()->getHero()->getY() + 2
                );
            }
            else if(currentKeyStates[SDL_SCANCODE_LEFT]) {
                game->getCurrentMap()->getHero()->setX(
                        game->getCurrentMap()->getHero()->getX() - 2
                );
            }
            else if(currentKeyStates[SDL_SCANCODE_RIGHT]) {
                game->getCurrentMap()->getHero()->setX(
                        game->getCurrentMap()->getHero()->getX() + 2
                );
            }
            else if(currentKeyStates[SDL_SCANCODE_ESCAPE]) {
                running = false;
            }
        }

        ticks = SDL_GetTicks();
        if(ticks >= last_frame_time + FRAME_DELAY) {
            last_frame_time = ticks;
            update();
        }
    }
}

void GameLoop::update() {
    game->getCurrentMap()->render();
    game->getVideo()->update();
}

void GameLoop::processEvent(int type) {
   if(type == Event::WINDOW_CLOSED) {
        running = false;
    }
}