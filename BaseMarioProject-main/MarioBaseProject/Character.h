#pragma once
#ifndef CHARACTER_H
#define CHARACTER_H
#include<iostream>
#include<SDL.h>
#include "Commons.h"
using namespace std;

class Texture2D;
class Character
{
private:
	FACING m_facing_direction;

protected:
	SDL_Renderer* m_renderer;
	Vector2D m_position;
	Texture2D* m_texture;
	bool m_moving_right;
	bool m_moving_left;
	bool m_jumping;
	bool m_can_jump;
	float m_jump_force;
	virtual void MoveLeft(float deltaTime);
	virtual void MoveRight(float deltaTime);

public:
	Character(SDL_Renderer* renderer,string imagePath, Vector2D start_position);
	~Character();

	virtual void Render();
	virtual void Update(float deltaTime, SDL_Event e);
	virtual void AddGravity(float deltaTime);
	virtual void Jump();
	void setposition(Vector2D new_position);
	Vector2D GetPosition();
};

#endif // !CHARATER_H