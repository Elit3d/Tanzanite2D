#include "Static.h"


Static::Static()
{
	sf::Vector2f position = { 0.f, 0.f };
	sprite.setPosition(position);
}

Static::Static(sf::Vector2f position)
{
	sprite.setPosition(position);
}


Static::~Static()
{
}
