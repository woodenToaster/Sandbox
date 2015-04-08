#ifndef SANDBOX_EVENT_H
#define SANDBOX_EVENT_H

#include "SDL.h"

class Event {
public:
    enum EventType {
        WINDOW_CLOSED,
        MOVE_UP,
        MOVE_DOWN,
        MOVE_LEFT,
        MOVE_RIGHT
    };

    Event();
    ~Event();
    int pollEvent();
    int getType();

private:
    SDL_Event event;
};

#endif //SANDBOX_EVENT_H
