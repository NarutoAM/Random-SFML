#include "Player.h"

Player::Player(float x, float y, RenderWindow *window)
{
	// Initialize player values
	drawWindow = window;
	rect = new RectangleShape(Vector2f(50, 50));
	rect->setPosition(x, y);
	rect->setFillColor(Color::Black);
	xPos = x;
	yPos = y;
	playerSpeed = 500;
}

void Player::Move(float x, float y)
{
	rect->move(x, y);
	xPos += x;
	yPos += y;
}

void Player::SetSpeed(float newSpeed)
{
	playerSpeed = newSpeed;
}

void Player::SetRect(float x, float y, float width, float height, Color clr)
{
	rect = new RectangleShape(Vector2f(width, height));
	rect->setPosition(x, y);
	rect->setFillColor(clr);
}

void Player::SetRect(RectangleShape &newRect)
{
	rect = &newRect;
}

void Player::SetX(float x)
{
	rect->setPosition(x, yPos);
	xPos = x;
}

void Player::SetY(float y)
{
	rect->setPosition(xPos, y);
	yPos = y;
}

void Player::draw()
{
	drawWindow->draw(*rect);
}

Player::~Player()
{
	rect = nullptr;
	drawWindow = nullptr;
}