#include "Character.h"


Character::Character()
{
	texture.loadFromFile("");
	_health = 0;
}


Character::~Character()
{
}


Character::Character(std::string imgpath, int health, 
	sf::Vector2f position, sf::Time frameTime, bool paused, bool looped)
{
	texture.loadFromFile(imgpath); // load the texture

	animated_sprite = new AnimatedSprite(frameTime, paused, looped);
	animated_sprite->setPosition(position);

	_health = health;
}

void Character::Update()
{
	sf::Time frameTime = frameClock.restart();

	if (currentAnimation != NULL)
	{
		animated_sprite->play(*currentAnimation);
		animated_sprite->update(frameTime);
	}
}

sf::Texture Character::getAnimationTexture()
{
	return texture;
}

void Character::Draw(sf::RenderWindow &window)
{
	window.draw(*animated_sprite);
	//window.draw(sprite);
}

void Character::setHealth(int health)
{
	_health = health;
}

int Character::getHealth()
{
	return _health;
}

// Collision between this and another entity
bool Character::Collision(sf::Sprite &s)
{
	if (sprite.getGlobalBounds().intersects(s.getGlobalBounds()))
		return true;
	return false;
}