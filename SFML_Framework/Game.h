#ifndef _GAME_H_
#define _GAME_H_

#include <SFML\Graphics.hpp>
#include <iostream>

#include "GameStates.h"
#include "Character.h"
#include "Enemy.h"

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

	std::vector<Character*> charVector;
	std::vector<Character*>::iterator charIter;
};


#endif // !_GAME_H_
