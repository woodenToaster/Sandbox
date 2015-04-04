#include "Event.h"


Event::Event() {

}

Event::~Event() {

}

int Event::pollEvent() {
    SDL_PollEvent(&event);
}

int Event::getType() {
    switch(event.window.event) {
        case SDL_WINDOWEVENT_CLOSE:
            return Event::WINDOW_CLOSED;
        case SDL_WINDOWEVENT_RESIZED:
            return Event::WINDOW_RESIZED;
        default:
            return -1;
    }
}
