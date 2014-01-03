//SpriteManager.cpp

#include <SDL_image.h>
#pragma comment(lib,"sdl2_image.lib")

#include "Sprite.h"
#include "DrawManager.h"
#include "SpriteManager.h"
#include "AnimatedSprite.h"

#include <fstream>
#include <sstream>

SpriteManager::SpriteManager(DrawManager *pdraw_manager){
	m_drawManager = pdraw_manager;
}

bool SpriteManager::Initialize(const std::string &directory){
	IMG_Init(IMG_INIT_PNG);

	m_directory = directory;

	return true;
}

void SpriteManager::CleanUp(){
	std::map<std::string,Pair>::iterator it = m_sprites.begin();

	while(it != m_sprites.end()){
		SDL_FreeSurface(it->second.surface);
		SDL_DestroyTexture(it->second.texture);
		++it;
	}
	m_sprites.clear();

	IMG_Quit();
}

Sprite* SpriteManager::Load(const std::string &filename, int px, int py, int pwidth, int pheight){
	std::map<std::string,Pair>::iterator it = m_sprites.find(filename);

	if(it == m_sprites.end()){
		if(!LoadImage(filename)){
			return nullptr;
		}
		it = m_sprites.find(filename);
	}

	return new Sprite(it->second.surface, it->second.texture, px, py, pwidth, pheight);
}

AnimatedSprite *SpriteManager::Load(const std::string &filename){
	std::ifstream stream;
	stream.open(filename.c_str());

	if(!stream.is_open()){
		return nullptr;
	}

	std::string row;
	stream >> row;
	std::map<std::string,Pair>::iterator it = m_sprites.find(row);

	if(it == m_sprites.end()){
		if(!LoadImage(row)){
			stream.close();
			return nullptr;
		}
		it = m_sprites.find(row);
	}
	SDL_Surface *surface = it->second.surface;
	SDL_Texture *texture = it->second.texture;
	AnimatedSprite *sprite = new AnimatedSprite(surface, texture, 0, 0, 0, 0);

	while(!stream.eof()){
		std::getline(stream, row);

		if(row.length() == 0){continue;}

		std::stringstream ss(row);

		AnimatedSprite::Frame frame;
		ss >> frame.duration;
		ss >> frame.x;
		ss >> frame.y;
		ss >> frame.w;
		ss >> frame.h;
		sprite->AddFrame(frame);
	}
	stream.close();

	return sprite;
}

bool SpriteManager::LoadImage(const std::string &filename){
	std::string path = m_directory + filename;
	SDL_Surface* surface = IMG_Load(path.c_str());
	const char *error = IMG_GetError();

	if(surface == nullptr){
		return false;
	}

	SDL_Texture* texture = SDL_CreateTextureFromSurface(m_drawManager->m_renderer, surface);

	Pair pair = {surface, texture};
	m_sprites.insert(std::pair<std::string,Pair>(filename, pair));

	return true;
}

SpriteManager::~SpriteManager(){

}