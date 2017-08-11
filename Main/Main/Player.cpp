#include "Player.h"


Player::Player(float x, float y, RenderWindow *window)
{
	// Initialize player values
	drawWindow = window;

	Image playerImg;
	playerImg.create(50, 50);

	Texture playerTexture;
	playerTexture.loadFromImage(playerImg);

	playerSprite = new Sprite(playerTexture, IntRect(25, 25, 25, 25));
	playerSprite->setPosition(x, y);
	playerSprite->setColor(Color::Black);
	playerSprite->setOrigin(playerSprite->getLocalBounds().top + playerSprite->getLocalBounds().height / 2.f, playerSprite->getLocalBounds().left + playerSprite->getLocalBounds().width / 2.f);

	xPos = x;
	yPos = y;
	
	bInputEnabled = true;
	bIsVisible = true;
	playerSpeed = 500;
}

void Player::draw()
{
	if (bIsVisible)
	{
		drawWindow->draw(*playerSprite);
	}
}

void Player::handleInput(float deltaTime)
{
	deltaSeconds = deltaTime;

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
	playerSprite->move(x, y);
	xPos += x;
	yPos += y;
}

void Player::moveTowards(Player &chasedPlayer, float speed)
{
	if (xPos != chasedPlayer.getX())
	{
		if (xPos < chasedPlayer.getX())
			setX(xPos + speed * deltaSeconds);
		else
			setX(xPos - speed * deltaSeconds);
	}
	
	if (yPos != chasedPlayer.getY())
	{
		if (yPos < chasedPlayer.getY())
			setY(yPos + speed * deltaSeconds);
		else
			setY(yPos - speed * deltaSeconds);
	}
}

void Player::moveTowards(float x, float y, float speed)
{
	if (xPos != x)
	{
		if (xPos < x)
			setX(xPos + speed * deltaSeconds);
		else
			setX(xPos - speed * deltaSeconds);
	}

	if (yPos != y)
	{
		if (yPos < y)
			setY(yPos + speed * deltaSeconds);
		else
			setY(yPos - speed * deltaSeconds);
	}
}

void Player::setVisible(bool newVisible)
{
	bIsVisible = newVisible;
}

void Player::setInputEnabled(bool canInteract)
{
	bInputEnabled = canInteract;
}
void Player::setColor(const Color &newColor)
{
	playerSprite->setColor(newColor);
}


void Player::setSpeed(float newSpeed)
{
	playerSpeed = newSpeed;
}

void Player::setSprite(float x, float y, int width, int height, Color clr)
{
	Image newImg;
	newImg.create(width, height);

	Texture newTexture;
	newTexture.loadFromImage(newImg);

	playerSprite = new Sprite(newTexture, IntRect(width / 2, height / 2, width / 2, height / 2));
	playerSprite->setPosition(x, y);
	playerSprite->setColor(clr);

	xPos = x;
	yPos = y;
}

void Player::setSprite(Sprite &newSprite)
{
	playerSprite = &newSprite;
}


void Player::setPosition(float x, float y)
{
	xPos = x;
	yPos = y;
	
	playerSprite->setPosition(x, y);
}


void Player::setPosition(const Vector2f &newPos)
{
	xPos = newPos.x;
	yPos = newPos.y;

	playerSprite->setPosition(newPos);
}


void Player::setX(float x)
{
	playerSprite->setPosition(x, yPos);
	xPos = x;
}


void Player::setY(float y)
{
	playerSprite->setPosition(xPos, y);
	yPos = y;
}


void Player::setSize(const Vector2f &newSize)
{
	playerSprite->setTextureRect(IntRect(static_cast<int>(newSize.x/2), static_cast<int>(newSize.y / 2), static_cast<int>(newSize.x / 2), static_cast<int>(newSize.y / 2)));
}

void Player::setSize(int width, int height)
{
	playerSprite->setTextureRect(IntRect(width/2, height/2, width/2, height/2));
}

void Player::setWidth(int newWidth)
{
	playerSprite->setTextureRect(IntRect(static_cast<int>(round(newWidth/2)), static_cast<int>(round(getHeight() / 2)), static_cast<int>(round(newWidth / 2)), static_cast<int>(round(getHeight() / 2))));
}

void Player::setHeight(int newHeight)
{
	playerSprite->setTextureRect(IntRect(static_cast<int>(round(getWidth()/2)), static_cast<int>(round(newHeight / 2)), static_cast<int>(round(getWidth() / 2)), static_cast<int>(round(newHeight/2))));
}


Player::~Player()
{
	playerSprite = nullptr;
	drawWindow = nullptr;
}