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
        default:
            return -1;
    }
}
