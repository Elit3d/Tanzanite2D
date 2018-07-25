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
	player = new Player("images/player.png", 100, sf::Vector2f(10.0f, 100.0f), sf::seconds(0.2f), false, false); // Player setup
	enemy = new Enemy("images/player.png", 100, sf::Vector2f(10.0f, 10.0f), sf::seconds(0.2f), false, true); // Enemy setup

	charVector.push_back(player);
	charVector.push_back(enemy);

	animationTexture.loadFromFile("images/eanim.png");

	//ml.load("isometric_grass_and_water.tmx");
	ml = new tmx::MapLoader("maps/");
	ml->load("isometric_grass_and_water.tmx");
}

void Game::Update(sf::RenderWindow &window)
{
	view = window.getDefaultView(); // keeps it the same as the window size
	view.setCenter(sf::Vector2f(350.f, 350.f));

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
					break;
				case sf::Keyboard::A:
					break;
				}
			}
			else if (event.type == sf::Event::KeyReleased)
			{
				switch (event.key.code)
				{
					case sf::Keyboard::W:
					break;
				}
			}
			if (event.type == sf::Event::Resized)
			{
				// When game is resized, run an event
			}

			UpdateGameStates();

			if (event.type == sf::Event::Closed)
				window.close();
		}
		
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) // Right
		{
			player->animated_sprite->move(1.f, .0f);

			if (player->Collision(enemy->sprite))
				player->animated_sprite->move(-1.f, .0f);
		}
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) // Left
		{
			player->animated_sprite->move(-1.f, .0f);

			if (player->Collision(enemy->sprite))
				player->animated_sprite->move(1.f, .0f);
		}
		else
		{
			// Do nothing
		}

		sf::Time frameTime = frameClock.restart();

		// Update all characters
		for (charIter = charVector.begin(); charIter != charVector.end(); charIter++)
		{
			(*charIter)->Update();
		}

		Draw(window);
	}
}

void Game::UpdateGameStates()
{
	switch (state->GetState())
	{
	case SPLASH:
		break;
	case MENU:
		break;
	case GAME:
		break;
	case PAUSE:
		break;
	case OPTIONS:
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
		// Set window view
		window.setView(view);
		// Draw level
		window.draw(*ml);

		// Draw all characters
		for (auto& it : charVector)
		{
			(it)->Draw(window);
		}
	
		break;
	case MENU:
		break;
	case GAME:
		break;
	case PAUSE:
		break;
	case OPTIONS:
		break;
	}

	// End Draw
	window.display();
}