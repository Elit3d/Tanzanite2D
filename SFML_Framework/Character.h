#ifndef _CHARACTER_H_
#define _CHARACTER_H_

#include "Entity.h"
#include "AnimatedSprite.h"

class Character :
	public Entity
{
public:
	Character();
	~Character();
	Character(std::string imgpath, int health, sf::Vector2f position, sf::Time frameTime, bool paused, bool looped);

	virtual void Update() = NULL;
	virtual void Draw(sf::RenderWindow &window) = 0;

	virtual void setHealth(int health) = NULL;
	virtual int getHealth() = NULL;

	/* Might want to look into perfect pixel collision */
	/* for more accurate collision detection and for */
	/* transparent edges of the image files */
	virtual bool Collision(sf::Sprite &s) = NULL;

	sf::Texture getAnimationTexture();
protected:
	Animation *currentAnimation;
private:
	Animation _animation;
	AnimatedSprite *animatedSprite;

	int _health;

	sf::Clock frameClock; // for the animation
};

#endif // !_CHARACTER_H_

