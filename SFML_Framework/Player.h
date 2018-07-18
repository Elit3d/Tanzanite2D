#ifndef _PLAYER_H_
#define _PLAYER_H_

#include "Character.h"
class Player :
	public Character
{
public:
	Player();
	~Player();
	Player(std::string imgpath, int health, sf::Vector2f location);

	void Update();
	void Draw(sf::RenderWindow &window);

	void setHealth(int health);
	int getHealth();

	bool Collision(sf::Sprite &s);
private:
};


#endif // !_PLAYER_H_
