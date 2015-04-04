#ifndef SANDBOX_GAMELOOP_H
#define SANDBOX_GAMELOOP_H

#include "Event.h"
#include "Video.h"


class GameLoop {

public:
    GameLoop();
    ~GameLoop();
    void run();
    void update();
    void processEvent(int type);

private:
    Event* event;
    Video* video;
    bool running;
};

#endif //SANDBOX_GAMELOOP_H
