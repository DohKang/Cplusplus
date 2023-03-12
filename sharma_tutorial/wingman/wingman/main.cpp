#include"Game.h"


int main()
{
    RenderWindow window(VideoMode(1920, 1080), "Wingman", Style::Default);

    Game game(&window);
    //Game loop
    while (window.isOpen())
    {
        srand(static_cast<unsigned>(time(NULL)));
        Event ev;
        while (window.pollEvent(ev))
        {
            if (ev.type == Event::Closed)
            {
                window.close();
            }
            if (ev.type == Event::KeyPressed && ev.key.code == Keyboard::Escape)
            {
                window.close();
            }
        }
        game.Update();
        game.Draw();
       
    }

    return 0;
}