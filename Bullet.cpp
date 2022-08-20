#include "Bullet.h"


// --------------------------------------
// ----------- CONSTRUCTOR --------------
// --------------------------------------
Bullet::Bullet()
{
}

Bullet::Bullet(sf::Texture* texture, float pos_x, float pos_y, float dir_x, float dir_y, float movement_speed)
{
    this->shape.setTexture(*texture); //desferenciar
	this->shape.setScale(0.5f, 0.5f);

	this->shape.setPosition(pos_x + this->getBounds().width, pos_y);
	this->shape.rotate(90);
	this->direction.x = dir_x;
	this->direction.y = dir_y;
	this->movementSpeed = movement_speed;
}


// --------------------------------------
// ----------- DESTRUCTOR --------------
// --------------------------------------
Bullet::~Bullet()
{
}


// --------------------------------------
// --------------- UPDATES --------------
// --------------------------------------
void Bullet::update()
{
	//Movement
	this->shape.move(this->movementSpeed * this->direction);

	
}

void Bullet::render(sf::RenderTarget * target)
{
	target->draw(this->shape);
	
}


const sf::FloatRect Bullet::getBounds() const
{
	// global coordinate of bullet
	return this->shape.getGlobalBounds();
}

const sf::Vector2f Bullet::getPosition() const
{
	// global coordinate of bullet
	return this->shape.getPosition();	
}