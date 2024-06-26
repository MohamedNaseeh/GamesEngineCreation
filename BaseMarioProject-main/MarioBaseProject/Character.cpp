#include "Character.h"
#include "Texture2D.h"
#include "Constants.h"

Character::Character(SDL_Renderer* renderer, string imagePath, Vector2D start_position)
{
	m_renderer = renderer;
	m_position = start_position;
	m_texture = new Texture2D(m_renderer);
	if (!m_texture->LoadFromFile(imagePath))
	{
		cout << "failed to load the background texture! 2" << endl;
	}
	m_facing_direction = FACING_RIGHT;
}
Character::~Character()
{
	m_renderer = nullptr;
}
void Character::Render()
{  
	if (m_facing_direction == FACING_RIGHT)
	{
		m_texture->Render(m_position, SDL_FLIP_NONE);
	}
	else
	{
		m_texture->Render(m_position, SDL_FLIP_HORIZONTAL);
	}
}
void Character::Update(float deltaTime, SDL_Event e)
{
	//deal with jumping first
	if (m_jumping)
	{
		//adjust position
		m_position.y -= m_jump_force * deltaTime;

		//reduce jump force
		m_jump_force -= JUMP_FORCE_DECREMENT * deltaTime;

		//check jump force at 0 (bottom of the screen)
		if (m_jump_force <= 0.0f)
			m_jumping = false;
	}
	AddGravity(deltaTime);

	if (m_moving_left)
	{
		MoveLeft(deltaTime);
	}
	else if (m_moving_right)
	{
		MoveRight(deltaTime);
	}
	
}
void Character::SetPosition(Vector2D new_position)//?????
{
	m_position = new_position;
}
Vector2D Character::GetPosition()//????????
{
	return m_position;
}
void Character::MoveLeft(float deltaTime)
{
	m_facing_direction = FACING_LEFT;
	m_position.x -= deltaTime * MOVEMENTSPEED;
}
void Character::MoveRight(float deltaTime)
{
	m_facing_direction = FACING_RIGHT;
	m_position.x += deltaTime * MOVEMENTSPEED;
}
void Character::AddGravity(float deltaTime)
{

	if (m_position.y + 64 <= SCREEN_HEIGHT)
	{
		m_position.y += GRAVITY * deltaTime;
		
	}
	else
	{
		m_can_jump = true;
	}
	
}
void Character::Jump()
{
	//jump
	m_jump_force = INITIAL_JUMP_FORCE;
	m_jumping = true;
	m_can_jump = false;
}