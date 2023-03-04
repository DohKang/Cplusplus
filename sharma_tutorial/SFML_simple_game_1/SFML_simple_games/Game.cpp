#include "Game.h"

//Constructors / Destructors

//Private functions
void Game::initVariables()
{
	this->window = nullptr;

    //game logic
    this->endGame = false;
    this->points = 0;
    /*this->enemySpawnTimer = 0.0f;*/
    this->health = 20;
    this->enemySpawnTimerMax = 20.0f;
    this->enemySpawnTimer = this->enemySpawnTimerMax;
    this->maxEnemies = 7;
    this->mouseHeld = false;

}
void Game::initWindow()
{
	this->videoMode.height = 600;
	this->videoMode.width = 800;
	this->window = new sf::RenderWindow(this->videoMode, "Game 1", sf::Style::Titlebar | sf::Style::Close);
    this->window->setFramerateLimit(144);
}

void Game::initFonts()
{
    if (!this->font.loadFromFile("Fonts/Dosis-Light.ttf"))
    {
        std::cout << "ERROR::GAME::INITFONTS::Failed to load font!" << "\n";;
    }

}

void Game::initText()
{
    this->uiText.setFont(this->font);
    this->uiText.setCharacterSize(24);
    this->uiText.setFillColor(sf::Color::White);
    this->uiText.setString("NONE");
}

void Game::initEnemies()
{
    /*this->enemy.setPosition(10.0f, 10.0f);*/
    this->enemy.setSize(sf::Vector2f(100.0f, 100.0f)); // take vector2f as a parameter
    this->enemy.setScale(sf::Vector2f(0.5f, 0.5f));
    this->enemy.setFillColor(sf::Color::Cyan);
    //this->enemy.setOutlineColor(sf::Color::Green);
    //this->enemy.setOutlineThickness(5.0f);
}


Game::Game()
{
	this->initVariables();
	this->initWindow();
    this->initEnemies();
    this->initFonts();
    this->initText();

}

Game::~Game()
{
	delete this->window;
}

const bool Game::running() const
{
	return this->window->isOpen();
}

const bool Game::getEndGame() const
{
    return this->endGame;
}

//Accessors


//Public Function

void Game::spawnEnemy()
{
    /*
    @return void


    spawn enemies and set their size and colors and positions. Spawns at random position.
    -Sets a random type(diff).
    -Sets a random position.
    -Sets a random color.
    -Adds enemyy to the vector.
    */
    this->enemy.setPosition(
        static_cast<float>(rand()% static_cast<int>(this->window->getSize().x - this->enemy.getSize().x)),
       0.0f/* static_cast<float>(rand()% static_cast<int>(this->window->getSize().y - this->enemy.getSize().y))*/
    );

    //Randomize enemy type
    int type = rand() % 5;
    switch (type)
    {
    case 0:
        this->enemy.setFillColor(sf::Color::Magenta);
        this->enemy.setSize(sf::Vector2f(30.0f, 30.0f));
        break;
    case 1:
        this->enemy.setFillColor(sf::Color::Blue);
        this->enemy.setSize(sf::Vector2f(50.0f, 50.0f));
        break;
    case 2:
        this->enemy.setFillColor(sf::Color::Cyan);
        this->enemy.setSize(sf::Vector2f(70.0f, 70.0f));
        break;
    case 3:
        this->enemy.setFillColor(sf::Color::Yellow);
        this->enemy.setSize(sf::Vector2f(85.0f, 85.0f));
        break;
    case 4:
        this->enemy.setFillColor(sf::Color::Red);
        this->enemy.setSize(sf::Vector2f(100.0f, 100.0f));
        break;
    default:
        this->enemy.setFillColor(sf::Color::White);
        this->enemy.setSize(sf::Vector2f(100.0f, 100.0f));
        break;
    }
    

    //spwan the enemy
    this->enemies.push_back(this->enemy);

    //Remove enemies at end of screen
}

void Game::pollEvents()
{
    while (this->window->pollEvent(this->ev)) //pull any event happening inside while
    {
        switch (this->ev.type) //based on evnt.type we will give action
        {
        case sf::Event::Closed:
            this->window->close();
            break;
        case sf::Event::KeyPressed:
            if (ev.key.code == sf::Keyboard::Escape)
                this->window->close();
            break;
        }
    }
}

void Game::updateMousePosition()
{
    /*
    @return void

    update the mouse positions:
        - Mouse position relative to window(vector 2i)

    */
    this->mousePosWindow = sf::Mouse::getPosition(*this->window);
    this->mousePosView = this->window->mapPixelToCoords(mousePosWindow);
}

void Game::updateText()
{
    std::stringstream ss;

    ss << "Points: " << this->points << "\n"
        << "Health: " << this->health << "\n";
    this->uiText.setString(ss.str());
}

void Game::updateEnemies()
{
    /*
    @return void

    updates the enemy spawn timer and spawns enemies
    when the total amount of enemies is smaller than max value.
  
    -updating the timer for enemy spawning
    -Moves enemies downward //TOdo
    - Remove the enemies at the edge of the screen. //TOdo
      */
    if (this->enemies.size() < this->maxEnemies)
    {
   
        if (this->enemySpawnTimer >= this->enemySpawnTimerMax)
        {
            //spawn the enemy and reset the timer
            this->spawnEnemy(); 
            this->enemySpawnTimer = 0.0f;
        }
        else
            this->enemySpawnTimer += 1.0f;
    }

    //moving and updating enemies.
    for ( int i =0; i < this->enemies.size(); i++)
    {
        this->enemies[i].move(0.0f, 0.5f);
    
        if (this->enemies[i].getPosition().y > this->window->getSize().y)
        {
            this->enemies.erase(this->enemies.begin() + i);
            this->health--;
            std::cout << "Health: " << this->health << "\n";
        }
    }
    //Check if clicked upon
    //if we mouse click the enemy, we delete it
    
    if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
    {
        if (this->mouseHeld == false)
        {
            this->mouseHeld = true;
            bool deleted = false;
            for (int i=0; i < this->enemies.size() && deleted == false; i++)
            {
                if (this->enemies[i].getGlobalBounds().contains(this->mousePosView))
                {

                    if (this->enemies[i].getFillColor() == sf::Color::Magenta)
                    {
                        this->points += 10;
                    }
                    else if (this->enemies[i].getFillColor() == sf::Color::Blue)
                    {
                        this->points += 7;
                    }
                    else if (this->enemies[i].getFillColor() == sf::Color::Cyan)
                    {
                        this->points += 5;
                    }
                    else if (this->enemies[i].getFillColor() == sf::Color::Yellow)
                    {
                        this->points += 4;
                    }
                    else if (this->enemies[i].getFillColor() == sf::Color::Red)
                    {
                        this->points += 3;
                    }
                    else if (this->enemies[i].getFillColor() == sf::Color::White)
                    {
                        this->points += 5000000;
                    }
                    std::cout << "Points: " << this->points << "\n";

                    //Delete the enemy
                    deleted = true;
                    this->enemies.erase(this->enemies.begin() + i);

                }
            }
        }
    }
    else
    {
        this->mouseHeld = false;
    }
}
//where the games at. character moves, item, mouse ..etc logic stuff
void Game::update()
{
    this->pollEvents();
    if (!this->endGame)
    {
        this->updateMousePosition();
        this->updateEnemies();
        this->updateText();
    }
    if (this->health <= 0)
    {
        this->endGame = true; //endGame condition
    }
}
    


void Game::renderText(sf::RenderTarget& target)
{
    target.draw(this->uiText);
}

void Game::renderEnemies(sf::RenderTarget& target)
{
    for (auto& e : this->enemies)
    {
        target.draw(e);
        //this->window->draw(e); //rendering all the enemies.

    }
}
//just visualize all position, points, putting pixels out. visualization
void Game::render()
{
    /*
        @return void
        -clear old frame
        -render objects
        -display frame in window

        Renders the game object.
    */
    this->window->clear();

    //draw game object
    this->renderEnemies(*this->window);
    this->renderText(*this->window);

    this->window->display();
}




//if the enemy is past the bottom of the screen. we delete it

//if true, delete that enemy.


//update mouse position
//Relative to the screen
//std::cout << "Mouse pos: " << sf::Mouse::getPosition().x << " " << sf::Mouse::getPosition().y << "\n";
//Relative to the window
//std::cout << "Mouse pos: " << 
//    sf::Mouse::getPosition(*this->window).x << " " << 
//    sf::Mouse::getPosition(*this->window).y << "\n";
