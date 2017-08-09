#ifndef MAIN_PLAYER_CLASS
#define MAIN_PLAYER_CLASS

#include <SFML\Graphics.hpp>
#include <iostream>

using namespace std;
using namespace sf;

class Player
{
public:
   /*
	* @brief Make new player
	* @param x Set x location
	* @param y Set y location
	* @param window Set window to draw player to
	*/
	Player(float x, float y, RenderWindow *window);
	~Player();

	// Draw player to main window
	void draw();

   /*
	* @brief Handles movement. Put when doing the event loop
	* @param deltaTime delta time used to control movement speed for each computer
	*/
	void handleInput(float deltaTime);

   /*
	* @brief Move player
	* @param x Move player horizontally by x amount
	* @param y Move player vertically by y amount
	*/
	void move(float x, float y);

	/* Setter Functions */
	
   /*
	* @brief Set x location of player
	* @param x New x location for player
	*/
	void setX(float x);

   /*
	* @brief Set y location of player
	* @param y New y location of player
	*/
	void setY(float y);

   /*
	* @brief Set speed of player that is used when handling movement
	* @param newSpeed Set new speed of player
	*/
	void setSpeed(float newSpeed);

   /*
	* @brief Set player rectangle 
	* @param x Set x location of rectangle
	* @param y Set y location of rectangle
	* @param width Set width of rectangle
	* @param height Set height of rectangle
	* @clr Set fill color of rectangle
	*/
	void setRect(float x = 0, float y = 0, float width = 25, float height = 25, Color clr = Color::Black);
	
   /*
	* @brief Set player rectangle
	* @param newRect Set rectangle to clone from
	*/
	void setRect(RectangleShape &newRect);
	
	/* Getter functions */

   /*
	* @return Player rectangle
	*/
	RectangleShape getRect() const { return *rect; }
	
   /*
	* @return Speed of player
	*/
	float getSpeed() const { return playerSpeed; };
	
	/*
	* @return X location of player
	*/
	float getX() const { return xPos; };
	
   /*
	* @return Y location of player
	*/
	float getY() const { return yPos; };

private:
	// Draw window to draw player to
	RenderWindow *drawWindow;

	// Player rectangle
	RectangleShape *rect;

	// x and y position of player
	float xPos, yPos;

	// Player speed
	float playerSpeed;
};

#endif