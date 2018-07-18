#ifndef _ANIMATION_H_
#define _ANIMATION_H_

#include <Thor/Animations.hpp>
#include <SFML/Graphics.hpp>

class Animation
{
public:
	Animation();
	Animation(sf::Texture &texture);
	void AnimTexture(sf::Texture &texture);
	sf::Texture GetTexture();
	void AddFrame(sf::IntRect rect);
	void Play();
	~Animation();

	void AddFrames(thor::FrameAnimation& animation, int x, int yFirst, int yLast, float duration = 1.f);
	void AddAnimation(std::string id, thor::FrameAnimation &animation, float seconds);
	void Update();
	void AnimateSprite(sf::Sprite &sprite);
	void PlayAnimation(std::string id, bool loop);
	void StopAnimation();
	bool bIsAnimPlaying();
private:
	thor::Animator<sf::Sprite, std::string> animator;
	sf::Clock DeltaTime;


	//new anim class
	sf::Sprite _sprite;
	std::vector<sf::IntRect> _frames;
};

#endif