//Be grateful for humble beginnings, because the next level will always require so much more of you
#include<iostream>
#include"constants.h"
#include<SDL.h>
#include<SDL_image.h>
#include<SDL_mixer.h>
using namespace std;

//Globals
SDL_Window* g_window = nullptr;
SDL_Renderer* g_renderer = nullptr;
SDL_Texture* g_texture = nullptr;
double angle = 0.0;

bool InitSDL();
void CloseSDL();
bool Update();
void Render();
SDL_Texture* LoadTextureFromFile(string path);
void FreeTexture();

bool InitSDL()
{
	if (SDL_Init(SDL_INIT_VIDEO) < 0)
	{
		cout << "SDL did not initialize. Error" << SDL_GetError();
		return false;
	}
	else
	{
		//setup passed, so create window
		g_window = SDL_CreateWindow("Games Engine Creation",
									SDL_WINDOWPOS_UNDEFINED,
									SDL_WINDOWPOS_UNDEFINED,
									SCREEN_WIDTH,
									SCREEN_HEIGHT,
									SDL_WINDOW_SHOWN);

		//did the window get created?
		if (g_window == nullptr)
		{
			//window failed
			cout << "window was not created. Error: " << SDL_GetError();
			return false;
		}

		//renderer setup
		g_renderer = SDL_CreateRenderer(g_window, -1, SDL_RENDERER_ACCELERATED);

		if (g_renderer != nullptr)
		{
			// init PNG loading
			int imageFlags = IMG_INIT_PNG;
			if (!(IMG_Init(imageFlags) & imageFlags))
			{
				cout << "SDL_image could not initialize, Error: " << IMG_GetError();
				return false;
			}
		}
		else
		{
			cout << "renderer could not initialise. Error: " << SDL_GetError();
			return false;
		}

		//loaf the background texture
		g_texture = LoadTextureFromFile("Images/test.bmp");
		if (g_texture == nullptr)
		{
			return false;
		}
	}
	return true;
}
void CloseSDL()
{
	//release the window
	SDL_DestroyWindow(g_window);
	g_window = nullptr;

	//clear the texture
	FreeTexture();
	//release the renderer
	SDL_DestroyRenderer(g_renderer);
	g_renderer = nullptr;

	//quit SDL subsystem
	IMG_Quit();
	SDL_Quit();
}

bool Update()
{
	//event handler
	SDL_Event e;

	//get events
	SDL_PollEvent(&e);

	//handle the events
	switch (e.type)
	{
		//click the X to quit
	case SDL_QUIT:
		return true;
		break;

	case SDL_MOUSEBUTTONDOWN:
		if (e.button.button == SDL_BUTTON_RIGHT)
		{
			return true; // Quit the program if the right mouse button is clicked
		}
		break;

	case SDL_KEYDOWN:
	{
		switch (e.key.keysym.sym)
		{
		case SDLK_q:
			return true;
			break;

		case SDLK_LEFT:
			angle -= 5.0;
			if (angle < 0.0)
			{
				angle += 360.0;
			}
			break;
		case SDLK_RIGHT:
			angle += 5.0;
			if (angle > 360.0)
			{
				angle -= 360.0;

			}
			break;
		}
		cout << angle << endl;
	}
	}
	return false;
}

void Render()
{
	//clear the screen
	SDL_SetRenderDrawColor(g_renderer, 0x00, 0x00, 0x00, 0x00);
	SDL_RenderClear(g_renderer);
	//placing where to render the texture
	SDL_Rect renderLoaction = { 0,0,SCREEN_WIDTH,SCREEN_HEIGHT};

	//Render to the screen
	SDL_RenderCopyEx(g_renderer, g_texture, NULL, &renderLoaction, angle, NULL, SDL_FLIP_NONE);
	//update the screen
	SDL_RenderPresent(g_renderer);
}

SDL_Texture* LoadTextureFromFile(string path)
{
	//remove memory used for previous texture
	FreeTexture();

	SDL_Texture* p_texture = nullptr;

	//Load the image
	SDL_Surface* p_surface = IMG_Load(path.c_str());
	if (p_surface != nullptr)
	{
		p_texture = SDL_CreateTextureFromSurface(g_renderer, p_surface);
		if (p_texture == nullptr)
		{
			cout << "Unable to create texture from surface. Error: " << SDL_GetError();
		}
		//remove the loaded surface now that we have a texture
		SDL_FreeSurface(p_surface);
	}
	else
	{
		cout << "Unable to create texture from surface. Error: " << IMG_GetError();
	}
	//return the texture
	return p_texture;
}

void FreeTexture()
{
	//check if texture exists before removing it
	if (g_texture != nullptr)
	{
		SDL_DestroyTexture(g_texture);
		g_texture = nullptr;
	}	
}


int main(int argc, char* args[])
{
	bool quit = false;
	if (InitSDL())
	{
		while (!quit)
		{
			Render();
			quit = Update();
		}
	}
	CloseSDL();
	return 0;
}
