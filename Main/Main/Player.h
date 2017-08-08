#ifndef MAIN_PLAYER_CLASS
#define MAIN_PLAYER_CLASS

#include <SFML\Graphics.hpp>
#include <iostream>

using namespace std;
using namespace sf;

class Player
{
public:
	Player(float x, float y, RenderWindow *window);
	~Player();

	void draw();

	void Move(float x, float y);

	// Setter functions
	void SetX(float x);
	void SetY(float y);
	void SetSpeed(float newSpeed);

	// Getter functions
	RectangleShape GetRect() const { return rect; }
	float GetSpeed() const { return playerSpeed; };
	float GetX() const { return xPos; };
	float GetY() const { return yPos; };

private:
	RenderWindow *drawWindow;
	RectangleShape rect;
	float xPos, yPos;
	float playerSpeed;
};

#endif