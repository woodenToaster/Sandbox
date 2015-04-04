#ifndef SANDBOX_GAMELOOP_H
#define SANDBOX_GAMELOOP_H

#include "Video.h"

class GameLoop {

public:
    GameLoop();
    ~GameLoop();
    void run();
    Video* getVideo();

private:
    Video* video;
    bool running;
};


#endif //SANDBOX_GAMELOOP_H