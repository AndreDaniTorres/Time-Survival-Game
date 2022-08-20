#include "Player.h"


// --------------------------------------
// ----------- CONSTRUCTOR --------------
// --------------------------------------
Player::Player(/* args */)
{
    this->movementSpeed = 1.0f;
    this->attackCooldownMax = 70.f;
    this->attackCooldown = this->attackCooldownMax;
    this->initTexture();
    this->initSprite();
}

// --------------------------------------
// ----------- DESTRUCTOR --------------
// --------------------------------------
Player::~Player()
{
}


// --------------------------------------
// --------------- UPDATE ---------------
// --------------------------------------

void Player::update()
{
    this->updateAttack();
    
}


void Player::updateAttack(){

    if (this->attackCooldown < this->attackCooldownMax)
    {
        this->attackCooldown += 1.f;
    }   

}

const bool Player::canAttack(){

    if ( this->attackCooldown >= this->attackCooldownMax )
    {
        // reset cooldown
        this->attackCooldown=0.f;
        return true;
    }
    return false;
    
}


// --------------------------------------
// --------- TEXTURE AND SPRITE ---------
// --------------------------------------

void Player::initTexture()
{
	//Load a texture from file

    sf::IntRect r1(542, 164, 125, 161); // posicion, largo y, ancho x


    if (!this->texture.loadFromFile("Textures/rick.png", r1))
    {
        std::cout << "ERROR::PLAYER::INITTEXTURE::Could not load texture file." << std::endl;
    }
    
}


void Player::initSprite()
{
    //Set the texture to the sprite 
    this->sprite.setTexture(this->texture);

    //Resize the sprite
    this->sprite.setOrigin({ this->sprite.getLocalBounds().width/2, 0 });
    this->sprite.setScale(0.6f, 0.6f);
    this->sprite.setPosition(200, 200);
    
}


void Player::render(sf::RenderTarget& target)
{
    target.draw(this->sprite);
}


// --------------------------------------
// ---------- PLAYER MOVEMENT -----------
// --------------------------------------

void Player::movement(const float dirX, const float dirY){

    
    // If flips to left or rigth
    float flip = ( dirX > 0 ) ? -1 : 1 ;

    // Flip around the center 
    this->sprite.setOrigin({ this->sprite.getLocalBounds().width/2, 0 });
    this->sprite.setScale(0.6f * flip, 0.6f);

    // Move
    this->sprite.move(this->movementSpeed * dirX, this->movementSpeed * dirY);


}

const sf::Vector2f & Player::getPos() const
{
	return this->sprite.getPosition();
}
