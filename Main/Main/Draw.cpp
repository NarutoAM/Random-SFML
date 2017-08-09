#include "Draw.h"

Draw::Draw(unsigned int width, unsigned int height, const char *title,  Uint32 windowStyle, ContextSettings cs)
{
	// Initialize window
	window = new RenderWindow(VideoMode(width, height), title, windowStyle, cs);
	wWidth = static_cast<float>(width);
	wHeight = static_cast<float>(height);
	bgColor = Color::White;
	currentLevel = 0;

	// Initalize player
	player = new Player(200, 300, window);

	// Game loop
	while (window->isOpen())
	{
		// update delta time value
		deltaTime = deltaClock.restart().asSeconds();

		// Event handling 
		Event e;
		while (window->pollEvent(e))
		{			
			switch (e.type)
			{
			case Event::MouseMoved:
				break;

			// Mouse pressed functions
			case Event::MouseButtonPressed:
				break;

			// Mouse released functions
			case Event::MouseButtonReleased:
				break;

			// Exit application when user closes it
			case Event::Closed:
				window->close();
				break;

			// Delayed keyboard input
			case Event::KeyPressed:
				if (e.key.code == Keyboard::LAlt)
					window->close();
				break;

			// Resize View of window when user resizes it
			case Event::Resized:
				window->setView(View(FloatRect(0, 0, static_cast<float>(e.size.width), static_cast<float>(e.size.height))));
				wWidth = static_cast<float>(e.size.width);
				wHeight = static_cast<float>(e.size.height);
				break;

			default:
				break;
			}
		}

		// Non-delayed keyboard input
		player->handleInput(deltaTime);
		
		// Gameplay checks
		if (currentLevel == 0 && player->getPosition().x > wWidth * 0.8)
			switchLevel(1);

		// Clear window
		window->clear(bgColor);

		// Draw
		player->draw();

		// Display buffer
		window->display();
	}
}

void Draw::switchLevel(int newLevel)
{
	switch (newLevel)
	{
	case 1:
		player->setPosition(wWidth / 2, wHeight / 2);

	default: 
		break;
	}

	currentLevel = newLevel;
}

Draw::~Draw()
{
	window = nullptr;
	player = nullptr;
}