#ifndef MAIN_DRAW_CLASS
#define MAIN_DRAW_CLASS

#include <iostream>
#include <SFML\Graphics.hpp>
#include "Player.h"
#include "SFButton.h"

using namespace std;
using namespace sf;

class Draw
{
public:
   /*
	* @brief Draw a window 
	* @param width Width of the window
	* @param height Height of the window
	* @paramm title Title of window
	* @param windowStyle Style of the title bar
	* @param cs Context settings for window
	*/
	Draw(unsigned int width = 800, unsigned int height = 600, const char *title = "Default Title", Uint32 windowStyle = 7, ContextSettings cs = ContextSettings());
	~Draw();

   /* 
	* @brief Handle switching levels
	* @param newLevel New level to switch to
	*/
	void switchLevel(int newLevel);

   /*
	* @brief shows a screen for user between switching levels
	*/
	void displayLevelEndScreen();

private:
	// Player
	Player *player;
	
	// Window
	RenderWindow *window;
	
	// Clock used to calculate delta time
	Clock deltaClock;

	// Background color
	Color bgColor;

	// Font of text to display at the end of levels
	Font *levelEndFont;

	// Text to display at the end of levels
	Text levelEndText;

	// Button for end of levels
	SFButton *endOfLevelOk;
	
	// Max width and height of window
	float wWidth, wHeight;

	// Delta time
	float deltaTime;

	// Current level
	int currentLevel;

	// Weather or not game is currently switching levels
	bool bIsEndOfLevel;

	// Events
	Event e;
};

#endif 