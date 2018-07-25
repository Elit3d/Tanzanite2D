#include "Player.h"


Player::Player()
{
}


Player::~Player()
{
}

Player::Player(std::string imgpath, int health, 
	sf::Vector2f position, sf::Time frameTime, bool paused, bool looped)
	: Character(imgpath, health, position, frameTime, paused, looped)
{
	WalkUp.setSpriteSheet(texture);
	WalkUp.addFrame(sf::IntRect(1, 0, 64, 64));
	WalkUp.addFrame(sf::IntRect(2, 0, 64, 64));
	WalkUp.addFrame(sf::IntRect(3, 0, 64, 64));
	WalkUp.addFrame(sf::IntRect(4, 0, 64, 64));
	WalkUp.addFrame(sf::IntRect(5, 0, 64, 64));
	WalkUp.addFrame(sf::IntRect(6, 0, 64, 64));
	WalkUp.addFrame(sf::IntRect(7, 0, 64, 64));
	WalkUp.addFrame(sf::IntRect(8, 0, 64, 64));
	currentAnimation = &WalkUp;
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