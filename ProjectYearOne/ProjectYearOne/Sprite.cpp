//Sprite.cpp

#include <SDL.h>
#pragma comment(lib,"sdl2.lib")

#include "Sprite.h"

Sprite::Sprite(SDL_Surface *surface, SDL_Texture *texture, int px, int py, int pwidth, int pheight){
	m_surface = surface;
	m_texture = texture;

	m_x = px;
	m_y = py;
	m_width = pwidth;
	m_height = pheight;
}