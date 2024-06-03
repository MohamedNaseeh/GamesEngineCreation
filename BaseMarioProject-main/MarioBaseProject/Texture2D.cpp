#include"Texture2D.h"
#include<iostream>
#include<SDL_image.h>
using namespace std;

Texture2D::Texture2D(SDL_Renderer* renderer) 
{
	m_renderer = renderer;
}
Texture2D::~Texture2D()
{
	//free up memory
	Free();
	m_renderer = nullptr;
}

bool Texture2D::LoadFromFile(string path)
{
	//remove memory used for previous texture
	Free();

	SDL_Texture* m_texture = nullptr;

	//Load the image
	SDL_Surface* p_surface = IMG_Load(path.c_str());
	if (p_surface != nullptr)
	{
		//colour key the image to be transparent
		SDL_SetColorKey(p_surface, SDL_TRUE, SDL_MapRGB(p_surface->format, 0, 0x00, 0x00));

		m_texture = SDL_CreateTextureFromSurface(m_renderer, p_surface);
		if (m_texture == nullptr)
		{
			cout << "Unable to create texture from surface. Error: " << SDL_GetError();
		}
		else
		{
			m_width = p_surface->w;
			m_height = p_surface->h;
		}
		//remove the loaded surface now that we have  a texture
		SDL_FreeSurface(p_surface);
	}
	else
	{
		cout << "Unable to create texture from surface. Error: " << IMG_GetError();
	}
	//return whether the process was successful
	return m_texture != nullptr;
}
void Texture2D::Free()
{
	if (m_texture != nullptr)
	{
		SDL_DestroyTexture(m_texture);
		m_texture = nullptr;
		m_width = 0;
		m_height = 0;
	}
}
void Texture2D::Render(Vector2D new_position, SDL_RendererFlip flip, double angle)
{
	//placing where to render the texture
	SDL_Rect renderLoaction = { 0,0,m_width,m_height};

	//Render to the screen
	SDL_RenderCopyEx(m_renderer, m_texture, NULL, &renderLoaction, 0, NULL, SDL_FLIP_NONE);
}