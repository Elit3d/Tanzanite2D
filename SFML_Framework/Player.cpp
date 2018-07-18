#include "Player.h"


Player::Player()
{
}


Player::~Player()
{
}

Player::Player(std::string imgpath, int health, sf::Vector2f location)
	: Character(imgpath, health, location)
{
	sf::Texture t;
	t.loadFromFile(imgpath);
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

bool Player::Collision(sf::Sprite &s)
{
	return Character::Collision(s);
}