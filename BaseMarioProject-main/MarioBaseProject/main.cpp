//Be grateful for humble beginnings, because the next level will always require so much more of you
#include<iostream>
#include "constants.h"
#include<SDL.h>
#include<SDL_image.h>
#include<SDL_mixer.h>
using namespace std;

//Globals
SDL_Window* g_window = nullptr;

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
	}
	return true;
}
void CloseSDL()
{
	//release the window
	SDL_DestroyWindow(g_window);
	g_window = nullptr;

	//quit SDL subsystem
	IMG_Quit();
	SDL_Quit();
}
int main(int argc, char* args[])
{
	if (InitSDL())
	{
		SDL_Delay(5000);
	}
	CloseSDL();
	return 0;
}