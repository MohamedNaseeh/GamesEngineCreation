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
	delete my_character;
	my_character = nullptr;
}

void GameScreenLevel1::Render()
{
	//draw the BACKGROUND
	m_background_texture->Render(Vector2D(), SDL_FLIP_NONE);
	my_character->Render();
}
void GameScreenLevel1::Update(float deltaTime, SDL_Event e) 
{
	//update character
	my_character->Update(deltaTime, e);
}

bool GameScreenLevel1::setUpLevel()
{
	// set up player character
	my_character = new Character(m_renderer, "Images/Mario.png", Vector2D(64, 330));
	//load the texture
	m_background_texture = new Texture2D(m_renderer);
	if (!m_background_texture->LoadFromFile("Images/test.bmp"))
	{
		cout << "failed to load the backgroud texture! 1" << endl;
		return false;
	}
	return true;
}