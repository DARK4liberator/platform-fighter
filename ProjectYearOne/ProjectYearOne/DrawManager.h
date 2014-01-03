//DrawManager.h

#pragma once

class Sprite;

class DrawManager{
	friend class SpriteManager;
public:
	DrawManager();
	bool Initialize(struct SDL_Window *window, int width, int height);
	void CleanUp();
	void Clear();
	void Present();
	void Draw(Sprite *sprite, int px, int py);
	~DrawManager();

private:
	struct SDL_Renderer *m_renderer;
};