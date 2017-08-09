#include "SFButton.h"

SFButton::SFButton(RenderWindow *window, char *functName, char *text, float x, float y, float width, float height)
{
	// Initialize buttons
	defaultButton = RectangleShape(Vector2f(width, height));
	defaultButton.setFillColor(Color::Red);
	defaultButton.setOutlineThickness(1);
	defaultButton.setOutlineColor(Color::Yellow);
	defaultButton.setPosition(x, y);

	hoveredButton = RectangleShape(Vector2f(width, height));
	hoveredButton.setFillColor(Color(255, 0, 100));
	hoveredButton.setOutlineThickness(3);
	hoveredButton.setOutlineColor(Color::Yellow);
	hoveredButton.setPosition(x, y);

	clickedButton = RectangleShape(Vector2f(width, height));
	clickedButton.setFillColor(Color::Black);
	clickedButton.setOutlineThickness(3);
	clickedButton.setOutlineColor(Color::Yellow);
	clickedButton.setPosition(x, y);

	currentButton = &defaultButton;

	// Initialize button text
	Font *font = new Font();
	if (!font->loadFromFile("times.ttf"))
		cout << "Error loading times.ttf" << endl;

	defaultText = Text(text, *font, 15);
	const float btnx = currentButton->getPosition().x, btny = currentButton->getPosition().y,
		btnw = currentButton->getGlobalBounds().width, btnh = currentButton->getGlobalBounds().height;

	FloatRect txtRect = defaultText.getLocalBounds();
	defaultText.setOrigin(txtRect.left + txtRect.width / 2.f, txtRect.top + txtRect.height / 2.f);
	defaultText.setPosition(btnx + btnw / 2, btny + btnh / 2);
	defaultText.setFillColor(Color::Cyan);
	defaultText.setStyle(Text::Bold);

	hoveredText = Text(text, *font, 15);
	hoveredText.setFillColor(Color::Green);
	hoveredText.setOrigin(txtRect.left + txtRect.width / 2.f, txtRect.top + txtRect.height / 2.f);
	hoveredText.setPosition(btnx + btnw / 2, btny + btnh / 2);
	hoveredText.setStyle(Text::Bold);

	clickedText = Text(text, *font, 15);
	clickedText.setFillColor(Color::White);
	clickedText.setOrigin(txtRect.left + txtRect.width / 2.f, txtRect.top + txtRect.height / 2.f);
	clickedText.setPosition(btnx + btnw / 2, btny + btnh / 2);
	clickedText.setStyle(Text::Bold);

	currentText = &defaultText;

	functionName = functName;

	// Initialize window to draw from
	drawWindow = window;
}

void SFButton::onClick()
{
	if (functionName == "draw_exit")
	{
		drawWindow->close();
	}
	else if (functionName == "draw_btn")
	{
		drawWindow->setTitle("Changed ur meme lol");
		setEnabled(false);
		setVisible(false);
	}
}

void SFButton::handleEvents(Event &e)
{
	if (bIsEnabled)
	{
		switch (e.type)
		{
		case Event::MouseMoved:
			if (currentButton->getGlobalBounds().contains(Vector2f(e.mouseMove.x, e.mouseMove.y)))
				setHovered(true);
			else
				setHovered(false);
			break;

			// Mouse pressed functions
		case Event::MouseButtonPressed:
			if (bIsHovered && e.mouseButton.button == Mouse::Button::Left)
				setClicked(true);
			else
				setClicked(false);
			break;

			// Mouse released functions
		case Event::MouseButtonReleased:
			if (bIsClicked)
			{
				onClick();
				setClicked(false);
			}
			break;

		default:
			break;
		}
	}
}

void SFButton::setEnabled(bool isEnabled)
{
	bIsEnabled = isEnabled;
}

void SFButton::setVisible(bool isVisible)
{
	bIsVisible = isVisible;
}

void SFButton::setClicked(bool isClicked)
{
	currentButton = isClicked ? &clickedButton : bIsHovered ? &hoveredButton : &defaultButton;
	currentText = isClicked ? &clickedText : bIsHovered ? &hoveredText : &defaultText;

	bIsClicked = isClicked;
}

void SFButton::setHovered(bool isHovered)
{
	if (!bIsClicked)
	{
		currentButton = isHovered ? &hoveredButton : &defaultButton;
		currentText = isHovered ? &hoveredText : &defaultText;
	}

	bIsHovered = isHovered;
}

void SFButton::setDefaultText(Text &newText)
{
	defaultText = newText;
}

void SFButton::setClickedText(Text &newText)
{
	clickedText = newText;
}

void SFButton::setHoveredText(Text &newText)
{
	hoveredText = newText;
}

void SFButton::draw()
{
	if (bIsVisible)
	{
		drawWindow->draw(*currentButton);
		drawWindow->draw(*currentText);
	}
}

void SFButton::setDefaultButton(RectangleShape &newButton)
{
	defaultButton = newButton;
}

void SFButton::setHoveredButton(RectangleShape &newButton)
{
	hoveredButton = newButton;
}

void SFButton::setClickedButton(RectangleShape &newButton)
{
	clickedButton = newButton;
}

SFButton::~SFButton()
{
	drawWindow = nullptr;
	currentButton = nullptr;
	currentText = nullptr;
}