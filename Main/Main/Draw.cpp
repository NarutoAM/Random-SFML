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

	SFButton btn(window, "Text", 300, 300, 100, 25);

	// Game loop
	while (window->isOpen())
	{
		deltaTime = deltaClock.restart().asSeconds();

		// Event handling
		Event e;
		while (window->pollEvent(e))
		{
			switch (e.type)
			{
			// Stop application when user closes the window
			case Event::MouseMoved:
				if (btn.GetCurrentButton().getGlobalBounds().contains(Vector2f(e.mouseMove.x, e.mouseMove.y)))
					btn.SetHovered(true);
				else
					btn.SetHovered(false);
				break;

			case Event::MouseButtonPressed:
				if (btn.IsHovered() && e.mouseButton.button == Mouse::Button::Left)
					btn.SetClicked(true);
				else
					btn.SetClicked(false);
				break;

			case Event::MouseButtonReleased:
				btn.SetClicked(false);
				break;

			case Event::Closed:
				window->close();
				break;

			// Delayed keyboard input
			case Event::KeyPressed:
				if (e.key.code == Keyboard::LAlt)
					window->close();
				break;

			case Event::Resized:
				window->setView(View(FloatRect(0, 0, static_cast<float>(e.size.width), static_cast<float>(e.size.height))));
				wWidth = e.size.width;
				wHeight = e.size.height;
				break;

			default:
				break;
			}
		}

		// Non-delayed keyboard input
		if (Keyboard::isKeyPressed(Keyboard::A))
		{
			player->Move(deltaTime * -player->GetSpeed(), 0);
		}

		if (Keyboard::isKeyPressed(Keyboard::D))
		{
			player->Move(deltaTime * player->GetSpeed(), 0);
		}

		if (Keyboard::isKeyPressed(Keyboard::W))
		{
			player->Move(0, deltaTime * -player->GetSpeed());
		}

		if (Keyboard::isKeyPressed(Keyboard::S))
		{
			player->Move(0, deltaTime * player->GetSpeed());
		}

		window->clear(Color::White);
		player->draw();
		btn.draw();
		window->display();
	}
}

Draw::~Draw()
{
	window = nullptr;
	player = nullptr;
}