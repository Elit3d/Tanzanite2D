#ifndef _ENTITY_H_
#define _ENTITY_H_

#include <SFML\Graphics.hpp>
#include <iostream>
#include "AnimatedSprite.h"

class Entity
{
public:
	sf::Sprite sprite;
	sf::Texture texture;
	AnimatedSprite *animated_sprite;
};

#endif // !1