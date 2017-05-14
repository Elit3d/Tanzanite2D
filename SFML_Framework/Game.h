#ifndef _GAME_H_
#define _GAME_H_

#include <SFML\Graphics.hpp>
#include <iostream>

#include "GameStates.h"
#include "Character.h"
#include "Enemy.h"
#include "Level.h"
#include "Animation.h"

class Game
{
public:
	Game();
	~Game();

	// Begin Main functions
	void Setup();
	void Update(sf::RenderWindow &window);
	void Draw(sf::RenderWindow &window);
	// End Main functions

	void UpdateGameStates();

private:
	GameStates *state;
	Enemy *enemy;
	Level *level;

	Animation *PlayerAnimation;
	Animation *EnemyAnimation;

	std::vector<Character*> charVector;
	std::vector<Character*>::iterator charIter;

	sf::Texture animationTexture;
	sf::Sprite animationSprite;

	sf::Texture animation_enemyTexture;
	sf::Sprite animation_enemySprite;

	thor::FrameAnimation walk_player;

	thor::FrameAnimation shoot_enemy;

	thor::Animator<sf::Sprite, std::string> animator;

};


#endif // !_GAME_H_
