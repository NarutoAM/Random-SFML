#include "Draw.h"

Draw::Draw(unsigned int width, unsigned int height, const char *title,  Uint32 windowStyle, ContextSettings cs)
{
	// Initialize window
	window = new RenderWindow(VideoMode(width, height), title, windowStyle, cs);
	wWidth = static_cast<float>(width);
	wHeight = static_cast<float>(height);

	// Initalize player
	player = new Player(200, 300, window);
	player->setSpeed(500);

	SFButton btn2(window, "draw_exit", "Exit", wWidth - 100, wHeight - 25, 100, 25);
	SFButton btn(window, "draw_btn", "", window->getView().getCenter().x, window->getView().getCenter().y, 100, 25);

	// Game loop
	while (window->isOpen())
	{
		// update delta time value
		deltaTime = deltaClock.restart().asSeconds();

		// Event handling 
		Event e;
		while (window->pollEvent(e))
		{
			btn.handleEvents(e);
			btn2.handleEvents(e);
			
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

		// Clear window
		window->clear(Color::White);

		// Draw window components
		player->draw();
		btn.draw();
		btn2.draw();

		// Display buffer
		window->display();
	}
}

Draw::~Draw()
{
	window = nullptr;
	player = nullptr;
}