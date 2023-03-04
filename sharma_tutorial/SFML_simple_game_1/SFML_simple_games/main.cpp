#include "Game.h"
#include <iostream>

int main()
{
    //init srand
    
    std::srand(static_cast<unsigned>(time(NULL)));
    //Init Game engine
    Game game;

    //Game loop
    while (game.running() && !game.getEndGame())
    {

        //update
        game.update();

        //render
        game.render();


    }
    //End of application
    return 0;
}