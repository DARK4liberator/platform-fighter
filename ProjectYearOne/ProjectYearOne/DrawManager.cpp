//DrawManager.cpp

#include <SDL.h>
#pragma comment(lib,"sdl2.lib")
#pragma comment(lib,"sdl2main.lib")

#include "Sprite.h"
#include "DrawManager.h"

DrawManager::DrawManager(){
	m_renderer = nullptr;
}

bool DrawManager::Initialize(struct SDL_Window *window, int width, int height){
	m_renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
	
	if(m_renderer == nullptr){  return false;	}

	return true;
}

void DrawManager::CleanUp(){
	if(m_renderer != nullptr){
		SDL_DestroyRenderer(m_renderer);
		m_renderer = nullptr;
	}
}

void DrawManager::Clear(){
	SDL_SetRenderDrawColor(m_renderer, 0x11, 0x22, 0x33, 0xff);
	SDL_RenderClear(m_renderer);
}

void DrawManager::Present(){
	SDL_RenderPresent(m_renderer);
}

void DrawManager::Draw(Sprite *sprite, int px, int py){
	SDL_Rect src = {sprite->m_x, sprite->m_y, sprite->m_width, sprite->m_height};
	SDL_Rect dst = {px, py, sprite->m_width, sprite->m_height};
	SDL_RenderCopy(m_renderer, sprite->m_texture, &src, &dst);
}

DrawManager::~DrawManager(){

}