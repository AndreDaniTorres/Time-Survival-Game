//#pragma once

#include<map>
#include "Player.h"
#include "Bullet.h"
#include "Enemy.h"



class Game
{
private:

	// clock 
	sf::Clock clock;
	
	// Window
	sf::RenderWindow* window;

	//Resources
	std::map<std::string, sf::Texture*> textures; //there is a texture for each string 
	std::vector<Bullet*> bullets;

	//Background
	sf::Texture textureBackground;
	sf::Sprite spriteBackground;

	float bulletDirX;


	// Player
	Player* player;

	// Enemy
	Enemy* enemy;

	// Private functions
	void initWindow();
	void initTextures();
	void initBackground();

	void initPlayer();
	void initEnemies();
	

public:
	Game();
	virtual ~Game();

	void updatePollEvents();
    void updateInput();
	void updateBullets();

	void run();
	void update();
	void render(); //renders the updates
	void renderBackground();

};