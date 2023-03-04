#include "Game.h"




int main()
{
    srand(unsigned(time(NULL)));
    Game game;

    while (game.running() && !game.getGameOver())
    {
        game.update();
        game.render();
    }
    return 0;
}