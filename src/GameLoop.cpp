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

        heroX = game->getCurrentMap()->getHero()->getX();
        heroY = game->getCurrentMap()->getHero()->getY();

        //TODO: Remove player movement from this class
        if(currentKeyStates[SDL_SCANCODE_UP]) {
            game->getCurrentMap()->getHero()->setY(heroY - 2);
        }
        if(currentKeyStates[SDL_SCANCODE_DOWN]) {
            game->getCurrentMap()->getHero()->setY(heroY + 2);
        }
        if(currentKeyStates[SDL_SCANCODE_LEFT]) {
            game->getCurrentMap()->getHero()->setX(heroX - 2);
        }
        if(currentKeyStates[SDL_SCANCODE_RIGHT]) {
            game->getCurrentMap()->getHero()->setX(heroX + 2);
        }
        if(currentKeyStates[SDL_SCANCODE_ESCAPE]) {
            running = false;
        }

        if((heroX > 64 && heroX < 64 + 32) && (heroY > 64 && heroY < 64 + 32)) {
            game->getCurrentMap()->collectTile(SDL_Rect{64, 64});
        }

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
    game->getCurrentMap()->render();
    game->getVideo()->update();
}

void GameLoop::processEvent(int type) {
   if(type == Event::WINDOW_CLOSED) {
        running = false;
    }
}