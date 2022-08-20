#include "Game.h"


// --------------------------------------
// ----------- CONSTRUCTOR --------------
// --------------------------------------
Game::Game()
{
    this->initWindow();
    this->initTextures();
    this->initBackground();

    
    this->bulletDirX = -1.f;
    this->initPlayer();

    this->initEnemies();

    

}


// --------------------------------------
// ----------- DESTRUCTOR --------------
// --------------------------------------
Game::~Game()
{
    delete this->window;
    delete this->player;

    // Delete all textures
    for (auto &tex: this->textures)
    {
        delete tex.second;  //for each tex, second position (contains textures) 
    }

	//Delete bullets
	for (auto *bull : this->bullets)
	{
		delete bull;
	}
    
}


// --------------------------------------
// --------------- WINDOW ---------------
// --------------------------------------
void Game::initWindow()
{
    // window closes and title bar 
	this->window = new sf::RenderWindow(sf::VideoMode(800, 800), "Survival Game");
    this->window->setFramerateLimit(144);
    this->window->setVerticalSyncEnabled(false);
}


void Game::run()
{
    // run while the window is open 
    while (this->window->isOpen())
    {
        // always update before run
        this->updatePollEvents();
        this->update();
        this->render();
    }

}


void Game::render()
{
    // clears previous window
	this->window->clear(sf::Color::White);

    // Render Background sprite 
    this->renderBackground();

    // Render main character
    this->player->render(*this->window); // window is a pointer

    for (auto *bullet: this->bullets)
	{
		bullet->render(this->window);
	}

    this->enemy->render(this->window);

    this->window->display();

}


// --------------------------------------
// ------------- BACKGROUND -------------
// --------------------------------------
void Game::initBackground()
{
    if (!this->textureBackground.loadFromFile("Textures/background1.png"))
    {
        std::cout << "ERROR::GAME::INITTEXTURE::Could not load background file." << std::endl;
    }
    
    this->spriteBackground.setTexture(this->textureBackground);
    
    //Resize the sprite
    this->spriteBackground.setScale(1.5f, 1.5f);
}


void Game::renderBackground()
{
    this->window->draw(this->spriteBackground);
}


// --------------------------------------
// --------------- UPDATES --------------
// --------------------------------------
void Game::update()
{
    this->updateInput();
    this->player->update();
    this->updateBullets();
    

}



void Game::updatePollEvents()
{
    sf::Event event;

    // while there are pending events...
    while (this->window->pollEvent(event))
    {
        // check the type of the event...
        switch (event.type)
        {
            // window closed
            case sf::Event::Closed:
                this->window->close();
                break;

            // key pressed
            case sf::Event::KeyPressed:
                break;

            // we don't process other types of events
            default:
                break;
        }
    }

}


void Game::updateInput()
{
    // move player 
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
    {
        this->player->movement(1.f, 0.f);
        this->bulletDirX = 1.f;
        
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
    {
        this->player->movement(-1.f, 0.f);
        this->bulletDirX = -1.f;
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
    {
        this->player->movement(0.f, -1.f);
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
    {
        this->player->movement(0.f, 1.f);
    }


    // Bullets each 3 seconds 
    sf::Time elapsed = clock.getElapsedTime();

	if ( ((int)elapsed.asSeconds() % 3 == 0) && this->player->canAttack())
	{
		this->bullets.push_back(
			new Bullet(
			this->textures["BULLET"], 
			this->player->getPos().x, 
			this->player->getPos().y, 
			this->bulletDirX, 0.f, 
			3.f  // bullet speed 
			)
		);
	}
    

}



// --------------------------------------
// --------------- PLAYER ---------------
// --------------------------------------
void Game::initPlayer(){

    // new player from Player constructor 
    this->player = new Player();
}


// --------------------------------------
// --------------- BULLETS --------------
// --------------------------------------
void Game::initTextures()
{
	this->textures["BULLET"] = new sf::Texture();

    sf::IntRect r1(5, 740, 122, 158); // posicion, largo y, ancho x
	this->textures["BULLET"]->loadFromFile("Textures/pickle-rick_bullet.png", r1);
}

void Game::updateBullets(){
    
    unsigned count = 0;

    // show bullets
    for (auto *bullet: this->bullets)
	{
        bullet->update();
        //std::cout << bullet->getPosition().x <<std::endl;

        // remove bullets outside the screen (left || right)
        if ( (bullet->getPosition().x < 0) || (bullet->getPosition().x + bullet->getBounds().width > 800))
        {
            delete this->bullets.at(count);
            this->bullets.erase( this->bullets.begin() + count);
            --count;      
        }
     
        ++count;
	}

}


// --------------------------------------
// --------------- ENEMY ---------------
// --------------------------------------
void Game::initEnemies(){

    // new enemy from Enemy constructor 
    this->enemy = new Enemy(110.f, 110.f);
}


