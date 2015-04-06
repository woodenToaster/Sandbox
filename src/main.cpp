#include <GameLoop.h>

int main() {
    Game* game = new Game();
    GameLoop(game).run();
    return 0;
}