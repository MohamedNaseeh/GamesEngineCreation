//Be grateful for humble beginnings, because the next level will always require so much more of you
#include<iostream>
#include"constants.h"
#include<SDL.h>
#include<SDL_image.h>
#include<SDL_mixer.h>
#include "Texture2D.h"
#include "Commons.h"
#include "GameScreenManager.h"
using namespace std;

//Globals
SDL_Window* g_window = nullptr;
SDL_Renderer* g_renderer = nullptr;
GameScreenManager* game_screen_manager;
Uint32 g_old_time;

bool InitSDL();
void CloseSDL();
bool Update();
void Render();

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
									SDL_WINDOW_RESIZABLE);

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

		//load the background texture
		
	}
	return true;
}

void Render()
{
	//clear the screen
	SDL_SetRenderDrawColor(g_renderer, 0xff, 0xff, 0xff, 0xff);
	SDL_RenderClear(g_renderer);

	game_screen_manager->Render();
	//update the screen
	SDL_RenderPresent(g_renderer);


}

bool Update()
{
	Uint32 new_time = SDL_GetTicks();
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
	}
	game_screen_manager->Update((float)(new_time - g_old_time) / 1000.0f, e);
	g_old_time = new_time;
	return false;
}

void CloseSDL()
{
	//release the window
	SDL_DestroyWindow(g_window);
	g_window = nullptr;

	//release the renderer
	SDL_DestroyRenderer(g_renderer);
	g_renderer = nullptr;

	//destroy game screen manager
	delete game_screen_manager;
	game_screen_manager = nullptr;

	//quit SDL subsystem
	IMG_Quit();
	SDL_Quit();
}

int main(int argc, char* args[])
{
	
	if (InitSDL())
	{
		bool quit = false;
		game_screen_manager = new GameScreenManager(g_renderer, SCREEN_LEVEL1);
		//set the time
		g_old_time = SDL_GetTicks();

		while (!quit)
		{
			Render();
			quit = Update();
		}
	}
	CloseSDL();
	return 0;
}
