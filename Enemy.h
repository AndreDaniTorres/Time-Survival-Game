#ifndef ENEMY_H
#define ENEMY_H

#include <SFML/Graphics.hpp>
#include <iostream>

class Enemy
{
private:
    unsigned pointCount;
    
	sf::Sprite sprite;
    sf::Texture texture;

	int type;
	float speed;
	int damage;
	int points;

	void initShape();

public:
    Enemy();
    Enemy(float pos_x, float pos_y);
    virtual ~Enemy();

    //Accessors
	const sf::FloatRect getBounds() const;
	const int& getPoints() const;
	const int& getDamage() const;

	//Functions
	void update();
    void initSprite();
    void initTexture();
	void render(sf::RenderTarget * target);
};

#endif