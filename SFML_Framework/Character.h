#ifndef _CHARACTER_H_
#define _CHARACTER_H_

#include "Entity.h"
#include "Animation.h"
#include <iostream>

class Character :
	public Entity
{
public:
	Character();
	~Character();
	Character(std::string imgpath, int health, sf::Vector2f location);

	virtual void Update() = NULL;
	virtual void Draw(sf::RenderWindow &window) = 0;

	virtual void setHealth(int health) = NULL;
	virtual int getHealth() = NULL;

	/* Might want to look into perfect pixel collision */
	/* for more accurate collision detection and for */
	/* transparent edges of the image files */
	virtual bool Collision(sf::Sprite &s) = NULL;
private:
	int _health;
};

#endif // !_CHARACTER_H_

