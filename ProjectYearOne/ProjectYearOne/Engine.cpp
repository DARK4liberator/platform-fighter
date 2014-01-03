//Engine.cpp

#include <SDL.h>
#pragma comment(lib,"sdl2.lib")
#pragma comment(lib,"sdl2main.lib")

#include "Engine.h"
#include "DrawManager.h"
#include "SpriteManager.h"

Engine::Engine(){

	m_window = nullptr;
	m_drawManager = nullptr;
	m_spriteManager = nullptr;
	m_running = false;

	m_width = 0;
	m_height = 0;
}

bool Engine::Initialize(){
	m_width = 1024;
	m_height = 640;

	SDL_Init(SDL_INIT_EVERYTHING);

	m_window = SDL_CreateWindow(
		"Project One", 
		SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 
		m_width, m_height, 
		SDL_WINDOW_OPENGL);

	if(m_window == nullptr) {	return false;	}

	m_drawManager = new DrawManager;
	if(!m_drawManager->Initialize(m_window, m_width, m_height)) {return false;}

	m_spriteManager = new SpriteManager(m_drawManager);
	if(!m_spriteManager->Initialize("")) {return false;}


	m_running = true;

	return true;
}

void Engine::Run(){
	while(m_running){
		UpdateEvents();

		m_drawManager->Clear();

		m_drawManager->Present();

		m_keyboard.PostUpdate();

		SDL_Delay(10);
	}
}

void Engine::CleanUp(){
	if(m_window != nullptr){
		SDL_DestroyWindow(m_window);
		m_window = nullptr;
	}

	if(m_spriteManager != nullptr){
		m_spriteManager->CleanUp();
		delete m_spriteManager;
		m_spriteManager = nullptr;
	}

	if(m_drawManager != nullptr){
		m_drawManager->CleanUp();
		delete m_drawManager;
		m_drawManager = nullptr;
	}
}

Engine::~Engine(){

}

//PRIVATE

void Engine::UpdateEvents(){
	SDL_Event event;

	while(SDL_PollEvent(&event)){
		if(event.type == SDL_QUIT){
			m_running = false;
		}
		else if(event.type == SDL_KEYDOWN){
			int index = event.key.keysym.sym & 0xFF;
			m_keyboard.m_current[index] = true;
		}
		else if(event.type == SDL_KEYUP){
			int index = event.key.keysym.sym & 0xFF;
			m_keyboard.m_current[index] = false;
		}
	}
}