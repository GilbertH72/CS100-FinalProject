#include "../header/Game.h"

Game* Game::gameInstance = nullptr;

int main()
{
    Game* newGame = newGame->getInstance();
    newGame->startGame();
    return 0;
}
