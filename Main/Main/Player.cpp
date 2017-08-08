#include "Player.h"

Player::Player(float x, float y, RenderWindow *window)
{
	// Initialize player values
	drawWindow = window;
	rect.setSize(Vector2f(50, 50));
	rect.setPosition(x, y);
	rect.setFillColor(Color::Black);
	xPos = x;
	yPos = y;
	playerSpeed = 500;
}

void Player::Move(float x, float y)
{
	rect.move(x, y);
	xPos += x;
	yPos += y;
}

void Player::SetSpeed(float newSpeed)
{
	playerSpeed = newSpeed;
}

void Player::SetX(float x)
{
	rect.setPosition(x, yPos);
	xPos = x;
}

void Player::SetY(float y)
{
	rect.setPosition(xPos, y);
	yPos = y;
}

void Player::draw()
{
	drawWindow->draw(rect);
}

Player::~Player()
{
	drawWindow = nullptr;
}