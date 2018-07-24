#include "game.h"

int main()
{
	Game game;
	sf::ContextSettings settings;
	settings.antialiasingLevel = 8;

	sf::RenderWindow window(sf::VideoMode(1280, 720), "My SFML Framework", sf::Style::Default ,settings);

	game.Setup();
	game.Update(window);

	return 0;
}