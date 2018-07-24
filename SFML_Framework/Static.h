#pragma once
#include "Entity.h"
class Static :
	public Entity
{
public:
	Static();
	Static(sf::Vector2f position);
	~Static();

private:
	sf::Vector2f _position;
};

