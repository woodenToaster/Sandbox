#include "GameLoop.h"

GameLoop::GameLoop(): running(true) {
    video = new Video();
    video->init();
    event = new Event();
    char* file = "ground.png";
    map = new Map(video, file);
    map->init();

}

GameLoop::~GameLoop() {
    delete video;
    delete event;
}

void GameLoop::run() {
    while(running) {
        while(event->pollEvent()) {
            processEvent(event->getType());
        }
        video->delay(30);
        update();
    }
}

void GameLoop::update() {
    map->render();
    video->update();
}

void GameLoop::processEvent(int type) {
    switch(type) {
        case Event::WINDOW_CLOSED:
            running = false;
            break;
        default:
            break;
    }
}