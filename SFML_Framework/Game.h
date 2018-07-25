#ifndef _GAME_H_
#define _GAME_H_

#include "GameStates.h"
#include "Character.h"
#include "Player.h"
#include "Enemy.h"
#include "AnimatedSprite.h"
#include <tmx/MapLoader.hpp>

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
	Player *player;
	Enemy *enemy;
	//Animation WalkRight;
	//Animation Idle;
	//Animation WalkLeft;
	//AnimatedSprite *animatedSprite;
	//Animation* currentAnimation;

	sf::Clock frameClock; // for the animation

	std::vector<Character*> charVector;
	std::vector<Character*>::iterator charIter;

	sf::Texture animationTexture;

	tmx::MapLoader *ml;
	sf::View view;
};


#endif // !_GAME_H_
