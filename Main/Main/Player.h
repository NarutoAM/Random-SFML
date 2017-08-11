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

   /*
	* @brief Move player towards a location
	* @param chasedPlayer Player to go after
	* @param speed Speed of the chase
	*/
	void moveTowards(Player &chasedPlayer, float speed = 100.f);

   /*
	* @brief Move player towards a location
	* @param x X location to move to
	* @param y Y location to move to
	* @param speed Move speed
	*/
	void moveTowards(float x, float y, float speed = 100.f);

	/* Setter Functions */

   /*
	* @brief Set weather or not the player is visible
	* @param newVisible If true, draws player, if false doesn't
	*/
	void setVisible(bool newVisible);

   /*
	* @brief Set if user can interact with player
	* @param canInteract Weather or not the user can interact with player
	*/
	void setInputEnabled(bool canInteract);

   /*
	* @brief Sets color of sprite
	* @param newColor New color of sprite
	*/
	void setColor(const Color &newColor);

   /*
	* @brief Set position of player
	* @param x New x location of player
	* @param y New y location of player
	*/
	void setPosition(float x, float y);

   /*
	* @brief Set position of player
	* @param newPos New location of player
	*/
	void setPosition(const Vector2f &newPos);
	
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
	* @brief Set size of player rectangle
	* @param newSize New size of player rectangle
	*/
	void setSize(const Vector2f &newSize);

   /*
	* @brief Set size of player rectangle
	* @param width New width of player rectangle
	* @param height New height of player rectangle
	*/
	void setSize(int width, int height);
	
   /*
	* @brief Set width of player rectangle
	* @param newWidth New width of player rectangle
	*/
	void setWidth(int newWidth);

   /*
	* @brief Set height of player rectangle
	* @param newHeight New height of player rectangle
	*/
	void setHeight(int newHeight);

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
	* @param clr Set fill color of rectangle
	*/
	void setSprite(float x = 0.f, float y = 0.f, int width = 25, int height = 25, Color clr = Color::Black);
	
   /*
	* @brief Set player rectangle
	* @param newRect Set rectangle to clone from
	*/
	void setSprite(Sprite &newSprite);
	
	/* Getter functions */

   /*
	* @return Player rectangle
	*/
	Sprite getSprite() const { return *playerSprite; }
	
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

   /*
	* @return Vector2f location of player
	*/
	Vector2f getPosition() const { return playerSprite->getPosition(); };

   /*
	* @return Width of player rectangle
	*/
	float getWidth() const { return playerSprite->getLocalBounds().width; };
	
   /*
    * @return Height of player rectangle
    */
	float getHeight() const { return playerSprite->getLocalBounds().height; };

   /*
	* @return Size of player rectangle
	*/
	Vector2f getSize() const { return Vector2f(playerSprite->getLocalBounds().width, playerSprite->getLocalBounds().height); };

   /*
    * @return Local bounds of player rectangle
    */
	FloatRect getBounds() const { return playerSprite->getLocalBounds(); };

   /*
	* @return Weather or not the player is drawn to draw window
	*/
	bool isVisible() const { return bIsVisible; };

   /*
	* @return Weather or not user can interact with player
	*/
	bool isInputEnabled() const { return bInputEnabled; };

private:
	// Draw window to draw player to
	RenderWindow *drawWindow;

	// Player sprite
	Sprite *playerSprite;

	// x and y position of player
	float xPos, yPos;

	// Player speed
	float playerSpeed;

	// Delta time used for AI movement
	float deltaSeconds;

	// Weather or not the player is visible
	bool bIsVisible;

	// Weather or not the user can interact with the player
	bool bInputEnabled;
};

#endif