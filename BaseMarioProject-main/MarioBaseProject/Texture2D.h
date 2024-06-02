#pragma once
#ifndef _TEXTURE2D_H
#define _TEXTURE2D_H
#include<SDL.h>
#include"Commons.h"
#include<string>
using namespace std;

class Texture2D
{
private:
	SDL_Renderer* m_renderer;
	SDL_Texture* m_texture;

	int m_width;
	int m_height;
public:
	Texture2D(SDL_Renderer* renderer)
	{

	}
	~Texture2D()
	{

	}
	bool LoadFromFile(string path);
	void Free();
	void Render(Vector2D new_position, SDL_RendererFlip flip, double angle = 0.0);

	int getWidth() { return m_width; }
	int getHeight() { return m_height; }
};
#endif // _TEXTURE2D_H	