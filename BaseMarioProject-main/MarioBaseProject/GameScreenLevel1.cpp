#include "GameScreenLevel1.h"
#include<iostream>
#include "Texture2D.h"

GameScreenLevel1::GameScreenLevel1(SDL_Renderer* renderer) : GameScreen(renderer)
{
	setUpLevel();
}
GameScreenLevel1::~GameScreenLevel1()
{
	delete m_background_texture;
	m_background_texture = nullptr;
	delete mario;
	mario = nullptr;
	delete luigi;
	luigi = nullptr;
}

void GameScreenLevel1::Render()
{
	//draw the BACKGROUND
	m_background_texture->Render(Vector2D(), SDL_FLIP_NONE);
	mario->Render();
	luigi->Render();
}
void GameScreenLevel1::Update(float deltaTime, SDL_Event e) 
{
	//update character
	mario->Update(deltaTime, e);
	luigi->Update(deltaTime, e);
}

bool GameScreenLevel1::setUpLevel()
{
	//load the texture
	m_background_texture = new Texture2D(m_renderer);
	// set up player character
	mario = new CharacterMario(m_renderer, "Images/Mario.png", Vector2D(64, 330));
	luigi = new CharacterLuigi(m_renderer, "Images/Luigi.png", Vector2D(100, 330));
	if (!m_background_texture->LoadFromFile("Images/test.bmp"))
	{
		cout << "failed to load the background texture! 1" << endl;
		return false;
	}
	return true;
}