#include "game.h"

int main()
{
	Game game;
	sf::RenderWindow window(sf::VideoMode(200, 200), "My SFML Framework");

	game.Setup();
	game.Update(window);

	return 0;
}