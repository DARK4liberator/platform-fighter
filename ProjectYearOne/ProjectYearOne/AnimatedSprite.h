//AnimatedSprite.h

#pragma once

#include <vector>
#include "Sprite.h"

class AnimatedSprite : public Sprite{
public:
	struct Frame{
		float duration;
		int x,y,w,h;
	};

	AnimatedSprite(SDL_Surface *surface, SDL_Texture *texture, int x, int y, int width, int height);

	void Update(float deltatime);
	void AddFrame(Frame &frame);

private:
	float m_time;
	int m_current_frame;
	std::vector<Frame> m_animation;
};