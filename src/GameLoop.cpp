#include "GameLoop.h"

GameLoop::GameLoop(): running(true) {
    video = new Video();
    video->init();
    event = new Event();
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
    }
}

void GameLoop::update() {
    video->setSurfaceToMain();
    video->fillRect(0, 0, 0);
    video->update();
}

void GameLoop::processEvent(int type) {
    switch(type) {
        case Event::WINDOW_CLOSED:
            running = false;
            break;
        case Event::WINDOW_RESIZED:
            update();
            break;
        default:
            break;
    }
}