#include "Enemy.h"


Enemy::Enemy()
{
}


Enemy::~Enemy()
{
}

Enemy::Enemy(std::string imgpath, int health, 
	sf::Vector2f position, sf::Time frameTime, bool paused, bool looped)
	: Character(imgpath, health, position, frameTime, paused, looped)
{
	WalkLeft.setSpriteSheet(texture);
	WalkLeft.addFrame(sf::IntRect(0, 1, 64, 64));
	WalkLeft.addFrame(sf::IntRect(1, 1, 64, 64));
	WalkLeft.addFrame(sf::IntRect(2, 1, 64, 64));
	WalkLeft.addFrame(sf::IntRect(3, 1, 64, 64));
	WalkLeft.addFrame(sf::IntRect(4, 1, 64, 64));
	WalkLeft.addFrame(sf::IntRect(5, 1, 64, 64));
	WalkLeft.addFrame(sf::IntRect(6, 1, 64, 64));
	WalkLeft.addFrame(sf::IntRect(7, 1, 64, 64));
	WalkLeft.addFrame(sf::IntRect(8, 1, 64, 64));
	currentAnimation = &WalkLeft;

	WalkUp.setSpriteSheet(texture);
	WalkUp.addFrame(sf::IntRect(1, 0, 64, 64));
	WalkUp.addFrame(sf::IntRect(2, 0, 64, 64));
	WalkUp.addFrame(sf::IntRect(3, 0, 64, 64));
	WalkUp.addFrame(sf::IntRect(4, 0, 64, 64));
	WalkUp.addFrame(sf::IntRect(5, 0, 64, 64));
	WalkUp.addFrame(sf::IntRect(6, 0, 64, 64));
	WalkUp.addFrame(sf::IntRect(7, 0, 64, 64));
	WalkUp.addFrame(sf::IntRect(8, 0, 64, 64));

	state = new EnemyStates(IDLE);
}

void Enemy::Update()
{
	Character::Update();

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::U))
		currentAnimation = &WalkUp;

	States();
}

void Enemy::Draw(sf::RenderWindow &window)
{
	Character::Draw(window);
}

EnemyStates Enemy::GetStates()
{
	return *state;
}

void Enemy::States()
{
	switch (GetStates())
	{
	case IDLE:
		break;
	case SEEK:
		break;
	case FLEE:
		break;
	case WANDER:
		break;
	case PURSUIT:
		break;
	case EVADE:
		break;
	case SOCIAL:
		break;
	}
}

void Enemy::setHealth(int health)
{
	Character::setHealth(health);
}

int Enemy::getHealth()
{
	return Character::getHealth();
}

bool Enemy::Collision(sf::Sprite &s)
{
	return Character::Collision(s);
}