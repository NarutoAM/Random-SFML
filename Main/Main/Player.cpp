#include "Player.h"

Player::Player(float x, float y, RenderWindow *window)
{
	// Initialize player values
	drawWindow = window;
	rect = new RectangleShape(Vector2f(50, 50));
	rect->setPosition(x, y);
	rect->setFillColor(Color::Black);
	rect->setOrigin(rect->getLocalBounds().top + rect->getLocalBounds().height / 2.f, rect->getLocalBounds().left + rect->getLocalBounds().width / 2.f);
	xPos = x;
	yPos = y;
	bInputEnabled = true;
	bIsVisible = true;
	playerSpeed = 500;
}

void Player::handleInput(float deltaTime)
{
	// Keyboard movement
	if (drawWindow->hasFocus() && bInputEnabled)
	{
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
}

void Player::move(float x, float y)
{
	rect->move(x, y);
	xPos += x;
	yPos += y;
}

void Player::setVisible(bool newVisible)
{
	bIsVisible = newVisible;
}

void Player::setInputEnabled(bool canInteract)
{
	bInputEnabled = canInteract;
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

	xPos = x;
	yPos = y;
}

void Player::setRect(RectangleShape &newRect)
{
	rect = &newRect;
}

void Player::setPosition(float x, float y)
{
	xPos = x;
	yPos = y;
	
	rect->setPosition(x, y);
}

void Player::setPosition(const Vector2f &newPos)
{
	xPos = newPos.x;
	yPos = newPos.y;

	rect->setPosition(newPos);
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

void Player::setSize(const Vector2f &newSize)
{
	rect->setSize(newSize);
}

void Player::setSize(float width, float height)
{
	rect->setSize(Vector2f(width, height));
}

void Player::setWidth(float newWidth)
{
	rect->setSize(Vector2f(newWidth, getHeight()));
}

void Player::setHeight(float newHeight)
{
	rect->setSize(Vector2f(getWidth(), newHeight));
}

void Player::draw()
{
	if (bIsVisible)
	{
		drawWindow->draw(*rect);
	}
}

Player::~Player()
{
	rect = nullptr;
	drawWindow = nullptr;
}