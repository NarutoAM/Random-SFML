#include "Draw.h"

Draw::Draw(const float width, const float height, const char *title,  Uint32 windowStyle, ContextSettings cs)
{
	// Initialize window
	window = new RenderWindow(VideoMode(width, height), title, windowStyle, cs);
	wWidth = width;
	wHeight = height;

	// Initalize player
	player = new Player(200, 300, window);
	player->SetSpeed(500);

<<<<<<< HEAD
	SFButton btn(window, "btn1","EXIT RFN", 400, 400, 100, 25);
=======
	SFButton btn2(window, "draw_btn", "Title");
	SFButton btn(window, "draw_exit","EXIT RFN", 400, 400, 100, 25);
>>>>>>> 08eb9c2a9e7c983ca722ea782ad6a1b52884475d

	// Game loop
	while (window->isOpen())
	{
		// update delta time value
		deltaTime = deltaClock.restart().asSeconds();

		// Event handling 
		Event e;
		while (window->pollEvent(e))
		{
			btn.HandleEvents(e);
			btn2.HandleEvents(e);

			switch (e.type)
			{
			case Event::MouseMoved:
				break;

			// Mouse pressed functions
			case Event::MouseButtonPressed:
				break;

			// Mouse released functions
			case Event::MouseButtonReleased:
<<<<<<< HEAD
				if (btn.IsClicked())
				{
					btn.OnClick();
					btn.SetClicked(false);
				}
=======
>>>>>>> 08eb9c2a9e7c983ca722ea782ad6a1b52884475d
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
				wWidth = e.size.width;
				wHeight = e.size.height;
				break;

			default:
				break;
			}
		}

		/* Non-delayed keyboard input*/

		// Keyboard movement
		if (Keyboard::isKeyPressed(Keyboard::A) || Keyboard::isKeyPressed(Keyboard::Left))
		{
			player->Move(deltaTime * -player->GetSpeed(), 0);
		}

		if (Keyboard::isKeyPressed(Keyboard::D) || Keyboard::isKeyPressed(Keyboard::Right))
		{
			player->Move(deltaTime * player->GetSpeed(), 0);
		}

		if (Keyboard::isKeyPressed(Keyboard::W) || Keyboard::isKeyPressed(Keyboard::Up))
		{
			player->Move(0, deltaTime * -player->GetSpeed());
		}

		if (Keyboard::isKeyPressed(Keyboard::S) || Keyboard::isKeyPressed(Keyboard::Down))
		{
			player->Move(0, deltaTime * player->GetSpeed());
		}

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