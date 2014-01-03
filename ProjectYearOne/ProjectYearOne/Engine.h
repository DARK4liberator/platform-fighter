//Engine.h

#pragma once

#include "Input.h"

class DrawManager;
class SpriteManager;

class Engine{
public:
	Engine();
	bool Initialize();
	void Run();
	void CleanUp();
	~Engine();

private:
	void UpdateEvents();

private:
	struct SDL_Window *m_window;

	DrawManager *m_drawManager;
	SpriteManager *m_spriteManager;

	KeyBoard m_keyboard;

	bool m_running;

	int m_width;
	int m_height;
};