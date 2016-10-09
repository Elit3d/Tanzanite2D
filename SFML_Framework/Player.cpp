#include "Player.h"


Player::Player()
{
}


Player::~Player()
{
}

Player::Player(std::string imgpath, int health) 
	: Character(imgpath, health)
{
}

void Player::Update()
{
	Character::Update();
}

void Player::Draw(sf::RenderWindow &window)
{
	Character::Draw(window);
}

void Player::setHealth(int health)
{
	Character::setHealth(health);
}

int Player::getHealth()
{
	return Character::getHealth();
}