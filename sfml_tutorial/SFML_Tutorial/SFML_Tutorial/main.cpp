#include <SFML/Graphics.hpp>
#include <iostream>
#include "animation.h"

int main()
{
    
    sf::RenderWindow window(sf::VideoMode(512, 512), "SFML Tutorial!", sf::Style::Close | sf::Style::Resize);
    sf::RectangleShape player(sf::Vector2f(100.0f, 150.0f));
    player.setPosition(206.0f, 206.0f);
    sf::Texture playerTexture;
    playerTexture.loadFromFile("texture/tux.png");
    player.setTexture(&playerTexture);
    sf::Vector2u textureSize = playerTexture.getSize();
    textureSize.x /= 8;
    textureSize.y /= 2;

    Animation Animation(&playerTexture, sf::Vector2u(8, 2), 0.3f);
    float deltaTime = 0.0f;
    sf::Clock clock;
    

    while (window.isOpen())
    {
        deltaTime = clock.restart().asSeconds();
        sf::Event evnt;
        while (window.pollEvent(evnt))
        {
            switch (evnt.type)
            {
            case sf::Event::Closed:
                window.close();
                break;
        
            }
        }

        Animation.Update(0, deltaTime);
        player.setTextureRect(Animation.uvRect);

        window.clear(sf::Color(150,150,150));
        window.draw(player);
        window.display();
    }

    return 0;
}




//Keyboard
//Keyboard
//
//if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::A))
//{
//    player.move(-0.5f,0.0f);
//}
//
//if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::D))
//{
//    player.move(0.5f, 0.0f);
//}
//
//if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::W))
//{
//    player.move(0.0f, -0.5f);
//}
//if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::S))
//{
//    player.move(0.0f, 0.5f);
//}


//Mouse
//if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
//{
//    sf::Vector2i mousepos = sf::Mouse::getPosition(window);
//    player.setPosition((float)mousepos.x, static_cast<float>(mousepos.y));//sine we put int value, we need to cast it to float
//}


//rectangle
//player.setOrigin(50.0f, 50.0f); - set middle position as the center of rect.
//player.setFillColor(sf::Color::Red); - set color of rect


//resize and text input
//case sf::Event::Resized:
////cout << "New window width: "<<evnt.size.width <<" New window height: " << evnt.size.height << endl;
//printf("New window width: %i New window hegiht: %i\n", evnt.size.width, evnt.size.height);
//break;
//case sf::Event::TextEntered:
//if (evnt.text.unicode < 128)
//{
//    printf("%c", evnt.text.unicode);


// player.setTextureRect(sf::IntRect(textureSize.x * 3, textureSize.y *0, textureSize.x, textureSize.y));
//}