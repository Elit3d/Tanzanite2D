#ifndef _ANIMATION_H_
#define _ANIMATION_H_

#include <Thor/Animations.hpp>
#include <SFML/Graphics.hpp>

class Animation
{
public:
	Animation();
	~Animation();

	void AddFrames(thor::FrameAnimation& animation, int x, int yFirst, int yLast, float duration = 1.f);
	void AddAnimation(std::string id, thor::FrameAnimation &animation, float seconds);
	void AnimateSprite(sf::Sprite sprite, sf::Time dt);
	void PlayAnimation(std::string id, bool loop = false);
	void StopAnimation();
private:
	thor::Animator<sf::Sprite, std::string> animator;
};

#endif