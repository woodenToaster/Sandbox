#include "Game.h"

Game::Game() {
    video = new Video();
    video->init();
    Tileset* ts = new Tileset("images/ground.png");
    map = new Map(video, ts);
    map->init();
}

Game::~Game() {
    delete video;
    delete map;
}

Video* Game::getVideo() const {
    return video;
}

Map* Game::getCurrentMap() const {
    return map;
}