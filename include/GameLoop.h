#ifndef SANDBOX_GAMELOOP_H
#define SANDBOX_GAMELOOP_H

#include "Event.h"
#include "Game.h"
#include "Map.h"
#include "Video.h"


class GameLoop {

public:
    GameLoop(Game* game);
    ~GameLoop();
    void run();
    void update();
    void processEvent(int type);

private:
    Event* event;
    Game* game;
    bool running;
};

#endif //SANDBOX_GAMELOOP_H
