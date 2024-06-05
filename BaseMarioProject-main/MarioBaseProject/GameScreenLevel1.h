#pragma once
#ifndef GAMESCREENLEVEL1_H
#define GAMESCREENLEVEL1_H
#include "GameScreen.h"
#include "Commons.h"
#include "Character.h"
using namespace std;

class Texture2D;
class Character;
class GameScreenLevel1 : GameScreen
{
private:
	Texture2D* m_background_texture;
	Character* my_character;
	bool setUpLevel();

public:
	GameScreenLevel1(SDL_Renderer* renderer);
	~GameScreenLevel1();

	void Render() override;
	void Update(float deltaTime, SDL_Event e) override;
};
#endif // !GAMESCREENLEVEL1_H