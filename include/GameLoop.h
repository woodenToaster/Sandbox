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

    //TODO: print FPS
    const int FRAMES_PER_SECOND = 50;
    const int FRAME_DELAY = 1000 / FRAMES_PER_SECOND;

private:
    Event* event;
    Game* game;
    bool running;
};

#endif //SANDBOX_GAMELOOP_H
