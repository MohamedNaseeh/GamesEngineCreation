#pragma once
#ifndef GAMESCREENLEVEL1_H
#define GAMESCREENLEVEL1_H
#include "GameScreen.h"
#include "Commons.h"
#include "Character.h"
#include "CharacterLuigi.h"
#include "CharacterMario.h"
using namespace std;

class Texture2D;
class Character; //header included for this !!!!
class GameScreenLevel1 : GameScreen
{
private:
	Texture2D* m_background_texture;

	bool setUpLevel();

public:
	GameScreenLevel1(SDL_Renderer* renderer);
	~GameScreenLevel1();
	Character* mario;// what's the main difference when type is CharacterMario/CharacterLuigi ?
	Character* luigi;

	void Render() override;
	void Update(float deltaTime, SDL_Event e) override;
};
#endif // !GAMESCREENLEVEL1_H