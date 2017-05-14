#include "Game.h"
#include <Thor/Animations.hpp>

Game::Game()
{
}


Game::~Game()
{
}

void addFrames(thor::FrameAnimation& animation, int x, int yFirst, int yLast, float duration = 1.f)
{
	const int step = (yFirst < yLast) ? +1 : -1;
	yLast += step; // so yLast is excluded in the range

	for (int y = yFirst; y != yLast; y += step)
		animation.addFrame(duration, sf::IntRect(36 * x, 39 * y, 36, 39));
}

void Game::Setup()
{
	state = new GameStates(State::SPLASH); // Set the first game state
	enemy = new Enemy("images/enemy.png", 100, sf::Vector2f(10.0f, 10.0f)); // Enemy setup
	level = new Level();

	level->LoadFromFile(""); // load level tilemap from file

	charVector.push_back(enemy);

	animationTexture.loadFromFile("images/animation.png");
	animationSprite.setTexture(animationTexture);

	addFrames(walk, 0, 0, 7);
	addFrames(walk, 0, 6, 0);

	animator.addAnimation("walk", walk, sf::seconds(1.f));
}

void Game::Update(sf::RenderWindow &window)
{
	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::KeyPressed)
			{
				switch (event.key.code)
				{
				case sf::Keyboard::W:		
					animator.playAnimation("walk", true);
					break;
				}
			}

			UpdateGameStates();

			for (charIter = charVector.begin(); charIter != charVector.end(); charIter++)
			{
				(*charIter)->Update();
			}

			if (event.type == sf::Event::Closed)
				window.close();
		}

		animator.update(frameClock.restart());
		animator.animate(animationSprite);

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
		window.draw(animationSprite);
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