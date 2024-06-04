#pragma once
#ifndef GAMESCREEN_H
#define GAMESCREEN_H
#include<SDL.h>

class GameScreen
{
private:

protected:
	SDL_Renderer* m_renderer;

public:
	GameScreen(SDL_Renderer* renderer);
	~GameScreen();

	virtual void Render();
	virtual void Update(float deltaTime, SDL_Event e);
};
#endif // !GAMESCREEN_H