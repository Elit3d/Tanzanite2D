#include "Character.h"


Character::Character()
{
	texture.loadFromFile("");
	sprite.setTexture(texture);
	_health = 0;
}


Character::~Character()
{
}


Character::Character(std::string imgpath, int health)
{
	texture.loadFromFile(imgpath);
	sprite.setTexture(texture);
	_health = health;
}

void Character::Update()
{
}

void Character::Draw(sf::RenderWindow &window)
{
	window.draw(sprite);
}

void Character::setHealth(int health)
{
	_health = health;
}

int Character::getHealth()
{
	return _health;
}