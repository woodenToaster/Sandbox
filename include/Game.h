#ifndef SANDBOX_GAME_H
#define SANDBOX_GAME_H

#include "Event.h"
#include "Map.h"
#include "Video.h"

class Game {
public:
    Game();
    ~Game();
    Video* getVideo() const;
    Map* getCurrentMap() const;

private:
    Video* video;
    Event* event;
    Map* map;

};

#endif //SANDBOX_GAME_H
