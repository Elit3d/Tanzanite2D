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
	enemy = new Enemy("images/enemy.png", 100, sf::Vector2f(10.0f, 10.0f)); // Enemy setup
	level = new Level();
	PlayerAnimation = new Animation();
	EnemyAnimation = new Animation();

	level->LoadFromFile(""); // load level tilemap from file

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
					PlayerAnimation->PlayAnimation("walk", true); // play the animation
					break;
				case sf::Keyboard::A:
					EnemyAnimation->PlayAnimation("shoot", true);
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
		window.draw(animation_enemySprite);
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