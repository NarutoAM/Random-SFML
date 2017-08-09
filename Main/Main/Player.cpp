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

void Player::handleInput(float deltaTime)
{
	// Keyboard movement
	if (Keyboard::isKeyPressed(Keyboard::A) || Keyboard::isKeyPressed(Keyboard::Left))
	{
		move(deltaTime * -playerSpeed, 0);
	}

	if (Keyboard::isKeyPressed(Keyboard::D) || Keyboard::isKeyPressed(Keyboard::Right))
	{
		move(deltaTime * playerSpeed, 0);
	}

	if (Keyboard::isKeyPressed(Keyboard::W) || Keyboard::isKeyPressed(Keyboard::Up))
	{
		move(0, deltaTime * -playerSpeed);
	}

	if (Keyboard::isKeyPressed(Keyboard::S) || Keyboard::isKeyPressed(Keyboard::Down))
	{
		move(0, deltaTime * playerSpeed);
	}
}

void Player::move(float x, float y)
{
	rect->move(x, y);
	xPos += x;
	yPos += y;
}

void Player::setSpeed(float newSpeed)
{
	playerSpeed = newSpeed;
}

void Player::setRect(float x, float y, float width, float height, Color clr)
{
	rect = new RectangleShape(Vector2f(width, height));
	rect->setPosition(x, y);
	rect->setFillColor(clr);
}

void Player::setRect(RectangleShape &newRect)
{
	rect = &newRect;
}

void Player::setX(float x)
{
	rect->setPosition(x, yPos);
	xPos = x;
}

void Player::setY(float y)
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