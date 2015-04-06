#include "GameLoop.h"

GameLoop::GameLoop(Game* game): game(game), running(true) {
    event = new Event();
}

GameLoop::~GameLoop() {

}

void GameLoop::run() {
    while(running) {
        while(event->pollEvent()) {
            processEvent(event->getType());
        }
        game->getVideo()->delay(30);
        update();
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