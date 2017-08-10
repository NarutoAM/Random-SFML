#include "Draw.h"

Draw::Draw(unsigned int width, unsigned int height, const char *title,  Uint32 windowStyle, ContextSettings cs)
{
	// Initialize window
	window = new RenderWindow(VideoMode(width, height), title, windowStyle, cs);
	wWidth = static_cast<float>(width);
	wHeight = static_cast<float>(height);
	bgColor = Color::White;
	currentLevel = 0;
	bIsEndOfLevel = false;

	levelEndFont = new Font();

	if (!levelEndFont->loadFromFile("times.ttf"))
		cerr << "Level end font loading error" << endl;
	levelEndText = Text("", *levelEndFont);

	endOfLevelOk = new SFButton(window, "draw_endOfLevelOk", "OK", wWidth / 2, wHeight / 2, 50, 25);
	endOfLevelOk->setEnabled(false);
	endOfLevelOk->setVisible(false);

	// Initalize player
	player = new Player(200, 300, window);

	// Game loop
	while (window->isOpen())
	{
		if (!endOfLevelOk->isVisible())
			bIsEndOfLevel = false;
		else
			bIsEndOfLevel = true;

		player->setInputEnabled(!bIsEndOfLevel);
		player->setVisible(!bIsEndOfLevel);

		// update delta time value
		deltaTime = deltaClock.restart().asSeconds();

		// Event handling 
		while (window->pollEvent(e))
		{			
			endOfLevelOk->handleEvents(e);

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
		switch (currentLevel)
		{
		case 0:
			switchLevel(1);

		default:
			break;
		}

		// Clear window
		window->clear(bgColor);

		// Draw
		player->draw();
		endOfLevelOk->draw();
		
		if(bIsEndOfLevel)
			window->draw(levelEndText);

		// Display buffer
		window->display();
	}
}

void Draw::switchLevel(int newLevel)
{
	// Display level switching screen
	displayLevelEndScreen();

	// Set values based on the new level switching to
	switch (newLevel)
	{
	case 1:
		player->setPosition(wWidth / 2, wHeight / 2);

	default: 
		break;
	}

	currentLevel = newLevel;
}

void Draw::displayLevelEndScreen()
{
	bIsEndOfLevel = true;

	// Set level end screen values
	levelEndText.setString("Level Completed: " + to_string(currentLevel));
	levelEndText.setOrigin(levelEndText.getLocalBounds().left + levelEndText.getLocalBounds().width / 2.f, levelEndText.getLocalBounds().top + levelEndText.getLocalBounds().height / 2.f);
	levelEndText.setPosition(wWidth * 0.5f, wHeight * 0.2f);
	levelEndText.setFillColor(Color::Black);
	
	// Enable end of level button
	endOfLevelOk->setVisible(true);
	endOfLevelOk->setEnabled(true);
}

Draw::~Draw()
{
	window = nullptr;
	player = nullptr;
}