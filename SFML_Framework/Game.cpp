#include "Game.h"


Game::Game()
{
}


Game::~Game()
{
}

void Game::Setup()
{
	state = new GameStates(State::SPLASH); // Set the first game state
	enemy = new Enemy("images/enemy.png", 100, sf::Vector2f(10.0f, 10.0f)); // Enemy setup
	level = new Level();

	level->LoadFromFile(""); // load level tilemap from file

	charVector.push_back(enemy);
}

void Game::Update(sf::RenderWindow &window)
{
	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			UpdateGameStates();

			for (charIter = charVector.begin(); charIter != charVector.end(); charIter++)
			{
				(*charIter)->Update();
			}

			if (event.type == sf::Event::Closed)
				window.close();
		}

		Draw(window);
	}
}

void Game::UpdateGameStates()
{
	switch (state->GetState())
	{
	case SPLASH:
		std::cout << "In splash" << std::endl;
		break;
	case MENU:
		std::cout << "In menu" << std::endl;
		break;
	case GAME:
		std::cout << "In game" << std::endl;
		break;
	case PAUSE:
		std::cout << "In pause" << std::endl;
		break;
	case OPTIONS:
		std::cout << "In options" << std::endl;
		break;
	}
}

void Game::Draw(sf::RenderWindow &window)
{
	window.clear();
	// Begin Draw

	switch (state->GetState())
	{
	case SPLASH:
		std::cout << "In splash" << std::endl;
		break;
	case MENU:
		std::cout << "In menu" << std::endl;
		break;
	case GAME:
		std::cout << "In game" << std::endl;

		level->Draw(window); // draw the level tilemap
		break;
	case PAUSE:
		std::cout << "In pause" << std::endl;
		break;
	case OPTIONS:
		std::cout << "In options" << std::endl;
		break;
	}

	// End Draw
	window.display();
}