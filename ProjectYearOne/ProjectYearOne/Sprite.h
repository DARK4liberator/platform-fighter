//Sprite.h

#pragma once

struct SDL_Texture;
struct SDL_Surface;

class Sprite{
	friend class DrawManager;
	friend class AnimatedSprite;
public:
	Sprite(SDL_Surface *surface, SDL_Texture *texture, int px, int py, int pwidth, int pheight);

private:
	SDL_Surface *m_surface;
	SDL_Texture *m_texture;

	int m_x;
	int m_y;
	int m_width;
	int m_height;
};