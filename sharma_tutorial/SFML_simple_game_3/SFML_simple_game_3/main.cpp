#include "Game.h"
#include <time.h>

int main()
{
    srand(static_cast<unsigned>(time(NULL)));
    Game game;

    game.running();
    return 0;
}