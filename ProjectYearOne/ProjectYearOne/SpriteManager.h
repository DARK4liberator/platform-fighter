//SpriteManager.h

#pragma once

#include <map>
#include <string>

class Sprite;
class DrawManager;
class AnimatedSprite;

class SpriteManager{
	struct Pair{
		struct SDL_Surface *surface;
		struct SDL_Texture *texture;
	};

public:
	SpriteManager(DrawManager *pdraw_manager);
	bool Initialize(const std::string &directory);
	void CleanUp();
	~SpriteManager();

	Sprite* Load(const std::string &filename, int x, int y, int width, int height);
	AnimatedSprite *Load(const std::string &filename);

private:
	bool LoadImage(const std::string &filename);

private:
	DrawManager *m_drawManager;
	std::string m_directory;
	std::map<std::string,Pair> m_sprites;
};