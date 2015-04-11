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
            game->getCurrentMap()->getHero()->setY(heroY - 1);
        }
        if(currentKeyStates[SDL_SCANCODE_DOWN]) {
            game->getCurrentMap()->getHero()->setY(heroY + 1);
        }
        if(currentKeyStates[SDL_SCANCODE_LEFT]) {
            game->getCurrentMap()->getHero()->setX(heroX - 1);
        }
        if(currentKeyStates[SDL_SCANCODE_RIGHT]) {
            game->getCurrentMap()->getHero()->setX(heroX + 1);
        }
        if(currentKeyStates[SDL_SCANCODE_ESCAPE]) {
            running = false;
        }

        int x = game->getCurrentMap()->getHero()->getX();
        int y = game->getCurrentMap()->getHero()->getY();
        int w = game->getCurrentMap()->getHero()->getWidth();
        int h = game->getCurrentMap()->getHero()->getHeight();

        SDL_Rect heroLocation{x, y, w, h};

        game->getCurrentMap()->collectTile(heroLocation);


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
//    int x = game->getCurrentMap()->getHero()->getX();
//    int y = game->getCurrentMap()->getHero()->getY();
//    int w = game->getCurrentMap()->getHero()->getWidth();
//    int h = game->getCurrentMap()->getHero()->getHeight();
//    SDL_Rect* heroLocation = new SDL_Rect{x, y, w, h};
//    SDL_Surface* surface = game->getVideo()->getMainSurface();
//    SDL_FillRect(surface, heroLocation, SDL_MapRGB(surface->format, 127, 127, 127));

    game->getVideo()->update();
}

void GameLoop::processEvent(int type) {
   if(type == Event::WINDOW_CLOSED) {
        running = false;
    }
}