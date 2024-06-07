#pragma once
#ifndef CHARACTERLUIGI_H
#define CHARACTERLUIGI_H
#include "Character.h"

class CharacterLuigi : public Character
{
private:

public:
	CharacterLuigi(SDL_Renderer* renderer, string imagePath, Vector2D start_position);
	~CharacterLuigi();
	void Update(float deltaTime, SDL_Event e);
	void Render();
};
#endif // !CHARACTERLUIGI_H