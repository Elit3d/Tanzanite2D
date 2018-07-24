#include "Game.h"
#include <Thor/Animations.hpp>

Game::Game()
{
}


Game::~Game()
{
}

void Game::Setup()
{
	state = new GameStates(State::SPLASH); // Set the first game state
	player = new Player("images/player.png", 100, sf::Vector2f(10.0f, 100.0f)); // Player setup
	enemy = new Enemy("images/enemy.png", 100, sf::Vector2f(10.0f, 10.0f)); // Enemy setup

	charVector.push_back(player);
	charVector.push_back(enemy);

	animationTexture.loadFromFile("images/eanim.png");
	animationSprite.setTexture(animationTexture);

	animation_enemyTexture.loadFromFile("images/animation.png");
	animation_enemySprite.setTexture(animation_enemyTexture);
	animation_enemySprite.setPosition(64, 64);

	// Animation setup
	WalkRight.setSpriteSheet(animationTexture);
	WalkRight.addFrame(sf::IntRect(32, 64, 32, 32));
	WalkRight.addFrame(sf::IntRect(64, 64, 32, 32));
	WalkRight.addFrame(sf::IntRect(32, 64, 32, 32));
	WalkRight.addFrame(sf::IntRect(0, 64, 32, 32));

	// set up AnimatedSprite
	animatedSprite = new AnimatedSprite(sf::seconds(0.2), true, false);
	animatedSprite->setPosition(sf::Vector2f(1280 / 2, 0.0f));

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
					player->sprite.move(0.f, -1.f);

					if (player->Collision(enemy->sprite))
						player->sprite.move(0.f, 1.f);
					break;
				case sf::Keyboard::A:
					view.move(sf::Vector2f(-10.0f, .0f));
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

			for (charIter = charVector.begin(); charIter != charVector.end(); charIter++)
			{
				(*charIter)->Update();
			}

			if (event.type == sf::Event::Closed)
				window.close();
		}
		
		sf::Time frameTime = frameClock.restart();

		animatedSprite->play(WalkRight);

		// update AnimatedSprite
		animatedSprite->update(frameTime);

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
		// set window view
		window.setView(view);
		// Draw level
		window.draw(*ml);

		// Draw all characters
		for (auto& it : charVector)
		{
			(it)->Draw(window);
		}
		
		window.draw(*animatedSprite);
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