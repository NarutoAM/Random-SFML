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
	Draw(const float width = 800, const float height = 600, const char *title = "Default Title", Uint32 windowStyle = 7, ContextSettings cs = ContextSettings());
	~Draw();

private:
	Player *player;
	RenderWindow *window;
	Clock deltaClock;
	float wWidth, wHeight;
	float deltaTime;
};

#endif 