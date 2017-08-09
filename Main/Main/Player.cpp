#include "Player.h"

template <typename T>
Player<T>::Player(float x, float y, RenderWindow *window)
{
	// Initialize player values
	drawWindow = window;
<<<<<<< HEAD
	
	RectangleShape grect = static_cast<RectangleShape>(T);
	if (grect)
	{
		grect->setPosition(x, y);
		grect->setFillColor(Color::Black);
		grect->setOrigin(rect->getLocalBounds().top + rect->getLocalBounds().height / 2.f, rect->getLocalBounds().left + rect->getLocalBounds().width / 2.f);

		xPos = x;
		yPos = y;
	}
=======
	rect = new RectangleShape(Vector2f(50, 50));
	rect->setPosition(x, y);
	rect->setFillColor(Color::Black);
	rect->setOrigin(rect->getLocalBounds().top + rect->getLocalBounds().height / 2.f, rect->getLocalBounds().left + rect->getLocalBounds().width / 2.f);
	xPos = x;
	yPos = y;
>>>>>>> 3d6a0c28818b898ad432dd221f604639888630d5
	bInputEnabled = true;
	bIsVisible = true;
	playerSpeed = 500;
}

template <typename T>
void Player<T>::handleInput(float deltaTime)
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
<<<<<<< HEAD

		if (Keyboard::isKeyPressed(Keyboard::S) || Keyboard::isKeyPressed(Keyboard::Down))
		{
			move(0, deltaTime * playerSpeed);
		}
	}
}

template <typename T>
void Player<T>::move(float x, float y)
{
	RectangleShape grect = static_cast<RectangleShape>(T);
	if (grect)
	{
		grect->move(x, y);
		xPos += x;
		yPos += y;
=======

		if (Keyboard::isKeyPressed(Keyboard::S) || Keyboard::isKeyPressed(Keyboard::Down))
		{
			move(0, deltaTime * playerSpeed);
		}
>>>>>>> 3d6a0c28818b898ad432dd221f604639888630d5
	}
}

template <typename T>
void Player<T>::setVisible(bool newVisible)
{
	bIsVisible = newVisible;
}

template <typename T>
void Player<T>::setInputEnabled(bool canInteract)
{
	bInputEnabled = canInteract;
}

template <typename T>
void Player<T>::setSpeed(float newSpeed)
{
	playerSpeed = newSpeed;
}

template <typename T>
void Player<T>::setRect(float x, float y, float width, float height, Color clr)
{
	if (T == RectangleShape)
	{
		rect = new RectangleShape(Vector2f(x, y));
		rect->setSize(width, hegith);
		rect->setFillColor(clr);

		xPos = x;
		yPos = y;
	}
}

template <typename T>
void Player<T>::setRect(T &newRect)
{
	rect = &newRect;
}

template <typename T>
void Player<T>::setPosition(float x, float y)
{
	xPos = x;
	yPos = y;
	
	rect->setPosition(x, y);
}

template <typename T>
void Player<T>::setPosition(const Vector2f &newPos)
{
	xPos = newPos.x;
	yPos = newPos.y;

	rect->setPosition(newPos);
}

template <typename T>
void Player<T>::setX(float x)
{
	rect->setPosition(x, yPos);
	xPos = x;
}

template <typename T>
void Player<T>::setY(float y)
{
	rect->setPosition(xPos, y);
	yPos = y;
}

template <typename T>
void Player<T>::setSize(const Vector2f &newSize)
{
	rect->setSize(newSize);
}

template <typename T>
void Player<T>::setSize(float width, float height)
{
	rect->setSize(Vector2f(width, height));
}

template <typename T>
void Player<T>::setWidth(float newWidth)
{
	rect->setSize(Vector2f(newWidth, getHeight()));
}

template <typename T>
void Player<T>::setHeight(float newHeight)
{
	rect->setSize(Vector2f(getWidth(), newHeight));
}

template <typename T>
void Player<T>::draw()
{
	if (bIsVisible)
	{
		drawWindow->draw(*rect);
	}
}

template <typename T>
Player<T>::~Player<T>()
{
	rect = nullptr;
	drawWindow = nullptr;
}