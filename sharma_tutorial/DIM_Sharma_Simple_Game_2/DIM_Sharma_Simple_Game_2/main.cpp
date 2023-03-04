#include "Game.h"

int main()
{
    //random seed
    srand(static_cast<unsigned>(time(NULL)));

    Game game;
    while (game.running())
    {
        game.update();
        game.render();
    }
    system("pause");
    return 0;
}


