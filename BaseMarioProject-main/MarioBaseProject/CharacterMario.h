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
	void Update(float deltaTime, SDL_Event e);
	void Render();
};

#endif // !CHARACTERMARIO_H