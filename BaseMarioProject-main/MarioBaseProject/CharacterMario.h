#pragma once
#ifndef CHARACTERMARIO_H
#define CHARACTERMARIO_H
#include "Character.h"

class CharacterMario : public Character
{
private:

public:
	CharacterMario(SDL_Renderer* renderer, string imagePath, Vector2D start_position);
	~CharacterMario();

	void Render();
	void Update(float deltaTime, SDL_Event e);
};
#endif // !CHARACTERMARIO_H