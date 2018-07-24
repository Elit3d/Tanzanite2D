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
	Animation WalkRight;
	AnimatedSprite *animatedSprite;

	sf::Clock frameClock; // for the animation

	std::vector<Character*> charVector;
	std::vector<Character*>::iterator charIter;

	sf::Texture animationTexture;
	sf::Sprite animationSprite;

	sf::Texture animation_enemyTexture;
	sf::Sprite animation_enemySprite;

	tmx::MapLoader *ml;
	sf::View view;
};


#endif // !_GAME_H_
