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
	float m_jump_force = 0.0f;     //why
	bool m_moving_right =	false;
	bool m_moving_left =	false;
	bool m_jumping =		false; // why protected
	bool m_can_jump =		false; // why

	virtual void MoveLeft(float deltaTime);
	virtual void MoveRight(float deltaTime);   //why virtual?
	virtual void AddGravity(float deltaTime);
	virtual void Jump();

public:
	Character(SDL_Renderer* renderer,string imagePath, Vector2D start_position);
	~Character();

	virtual void Render();
	virtual void Update(float deltaTime, SDL_Event e);
	
	void SetPosition(Vector2D new_position);//????
	Vector2D GetPosition();					//?????
};

#endif // !CHARATER_H