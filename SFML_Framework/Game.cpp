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
	level = new Level();

	// Working on my own animation class
	PlayerAnimation = new Animation();
	EnemyAnimation = new Animation();

	level->LoadFromFile(""); // load level tilemap from file

	charVector.push_back(player);
	charVector.push_back(enemy);

	animationTexture.loadFromFile("images/animation.png");
	animationSprite.setTexture(animationTexture);

	animation_enemyTexture.loadFromFile("images/animation.png");
	animation_enemySprite.setTexture(animation_enemyTexture);
	animation_enemySprite.setPosition(64, 64);

	// Animation setup
	PlayerAnimation->AddFrames(walk_player, 0, 0, 7);
	PlayerAnimation->AddFrames(walk_player, 0, 6, 0);
	PlayerAnimation->AddAnimation("walk", walk_player, 1.f);

	EnemyAnimation->AddFrames(shoot_enemy, 1, 0, 7);
	EnemyAnimation->AddFrames(shoot_enemy, 1, 7, 0);
	EnemyAnimation->AddAnimation("shoot", shoot_enemy, 1.f); 


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
					player->sprite.move(0.f, -1.f);

					if (player->Collision(enemy->sprite))
						player->sprite.move(0.f, 1.f);
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

			UpdateGameStates();

			for (charIter = charVector.begin(); charIter != charVector.end(); charIter++)
			{
				(*charIter)->Update();
			}

			if (event.type == sf::Event::Closed)
				window.close();
		}

		EnemyAnimation->Update(); // Update the animation
		EnemyAnimation->AnimateSprite(animation_enemySprite); // Animate the sprite

		PlayerAnimation->Update();
		PlayerAnimation->AnimateSprite(animationSprite);

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
		// Draw all characters
		for (auto& it : charVector)
		{
			(it)->Draw(window);
		}
		break;
	case MENU:
		break;
	case GAME:
		level->Draw(window); // draw the level tilemap
		break;
	case PAUSE:
		break;
	case OPTIONS:
		break;
	}

	// End Draw
	window.display();
}