#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Audio.hpp>

class Player
{
private:
    sf::Texture texture;
    sf::Sprite sprite;

    float movementSpeed;

    float attackCooldown;
	float attackCooldownMax;

	void initTexture();
	void initSprite();

public:
    Player();
    ~Player();

    // Movement
    void movement(const float dirX, const float dirY);

    // Bullets 
    void updateAttack();
    const bool canAttack();

    // Accessor
	const sf::Vector2f& getPos() const;
    void update();
    void render(sf::RenderTarget& taget);
};

