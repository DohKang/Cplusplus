#include "Game.h"




int main()
{
    srand(static_cast<unsigned>(time(NULL)));

    //initialize game object
    Game game;

    //Game loop
    while (game.running())
    {
        game.update();
        game.render();

    }
    system("pause>0");
    //End of application
    return 0;
    
}


//initialize random seed
//update and rendere