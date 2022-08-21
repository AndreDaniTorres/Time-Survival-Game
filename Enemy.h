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

	void initShape();

public:
    Enemy();
    Enemy(float pos_x, float pos_y);
    virtual ~Enemy();


	//Functions
	void update(const float & pos_x, const float & pos_y);
		
    void initSprite();
    void initTexture();
	void render(sf::RenderTarget * target);

	// Accessor
	const sf::Vector2f& getPos() const;
	const sf::FloatRect getBounds() const;
};

#endif