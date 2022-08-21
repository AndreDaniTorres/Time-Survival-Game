
#include "Enemy.h"

Enemy::Enemy()
{
}


Enemy::~Enemy()
{
}

Enemy::Enemy(float pos_x, float pos_y)
{

    this->initTexture();
    this->initSprite();
	
	this->sprite.setPosition(pos_x, pos_y);
}


// --------------------------------------
// --------- TEXTURE AND SPRITE ---------
// --------------------------------------

void Enemy::initTexture()
{
	//Load a texture from file

    sf::IntRect r1(1787, 0, 311, 401); // posicion, largo y, ancho x

    if (!this->texture.loadFromFile("Textures/yoshi_enemy.png", r1))
    {
        std::cout << "ERROR::PLAYER::INITTEXTURE::Could not load texture file." << std::endl;
    }
    
}

void Enemy::initSprite()
{
    //Set the texture to the sprite 
    this->sprite.setTexture(this->texture);

    //Resize the sprite
    this->sprite.setOrigin({ this->sprite.getLocalBounds().width/2, 0 });
    this->sprite.setScale(0.2f, 0.2f);
    
}

void Enemy::render(sf::RenderTarget * target)
{
	target->draw(this->sprite);
}


const sf::Vector2f & Enemy::getPos() const
{
	return this->sprite.getPosition();
}

const sf::FloatRect Enemy::getBounds() const
{
	return this->sprite.getLocalBounds();
}


// --------------------------------------
// ------------- UPDATE ----------------
// --------------------------------------
void Enemy::update(const float & pos_x, const float & pos_y)
{
    // Towards player: (Position of player - position of enemy) * speed
	this->sprite.move((pos_x - this->getPos().x) * 0.001, (pos_y - this->getPos().y)* 0.001);
    
}