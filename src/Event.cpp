#include "Event.h"

Event::Event() {

}

Event::~Event() {

}

int Event::pollEvent() {
    return SDL_PollEvent(&event);
}

int Event::getType() {
    return event.window.event == SDL_WINDOWEVENT_CLOSE ? Event::WINDOW_CLOSED : -1;
}
