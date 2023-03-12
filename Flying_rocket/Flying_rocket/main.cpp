#include "stdafx.h"
#include "game.h"



int main()
{
    //random seed
    srand(static_cast<unsigned>(time(NULL)));

    //Background music
    sf::Music backgroundMusic;
    if (!backgroundMusic.openFromFile("Music/basicMusic.wav"))
    {
        std::cout << "GAME::ERROR::CAN'T OPEN BACKGROUNDMUSIC FILE::" << std::endl;
    }
    backgroundMusic.play();
    //repeating backgroundmusic
    backgroundMusic.setLoop(true);
    // create game object
    Game game; 
    // run the game loop
    game.running(); 

    system("pause");


    return 0;
}