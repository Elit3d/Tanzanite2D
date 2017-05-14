#include "Animation.h"


Animation::Animation()
{
}


Animation::~Animation()
{
}

void Animation::AddFrames(thor::FrameAnimation& animation, int x, int yFirst, int yLast, float duration)
{
	//thor::FrameAnimation animation1;
	const int step = (yFirst < yLast) ? +1 : -1;
	yLast += step; // so yLast is excluded in the range

	for (int y = yFirst; y != yLast; y += step)
		animation.addFrame(duration, sf::IntRect(36 * x, 39 * y, 36, 39));
}

void Animation::AddAnimation(std::string id, thor::FrameAnimation &animation, float seconds)
{
	animator.addAnimation(id, animation, sf::seconds(seconds));
}

void Animation::PlayAnimation(std::string id, bool loop)
{
	animator.playAnimation(id, loop);
}

void Animation::StopAnimation()
{
	animator.stopAnimation(); // stop current animation
}

void Animation::Update()
{
	animator.update(DeltaTime.restart());
}

void Animation::AnimateSprite(sf::Sprite &sprite)
{
	animator.animate(sprite);
}