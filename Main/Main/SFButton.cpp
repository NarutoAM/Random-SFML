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

void SFButton::OnClick()
{
	if (functionName == "btn1")
	{
		drawWindow->close();
	}
}

void SFButton::HandleEvents(Event &e)
{
	switch (e.type)
	{
	case Event::MouseMoved:
		if (currentButton->getGlobalBounds().contains(Vector2f(e.mouseMove.x, e.mouseMove.y)))
			SetHovered(true);
		else
			SetHovered(false);
		break;

		// Mouse pressed functions
	case Event::MouseButtonPressed:
		break;

		// Mouse released functions
	case Event::MouseButtonReleased:
		break;

	default:
		break;
	}
}

void SFButton::HandleHover(float mousex, float mousey)
{
	if (currentButton->getGlobalBounds().contains(Vector2f(e.mouseMove.x, e.mouseMove.y)))
		SetHovered(true);
	else
		SetHovered(false);
}

void SFButton::HandleClick(Mouse::Button mouseButton, bool bIsPressedEvent)
{
	if (bIsPressedEvent)
	{
		if (bIsHovered && mouseButton == Mouse::Button::Left)
			SetClicked(true);
		else
			SetClicked(false);
	}
	else
	{
		if (bIsClicked)
		{
			OnClick();
			SetClicked(false);
		}
	}
}

void SFButton::SetClicked(bool isClicked)
{
	currentButton = isClicked ? &clickedButton : bIsHovered ? &hoveredButton : &defaultButton;
	currentText = isClicked ? &clickedText : bIsHovered ? &hoveredText : &defaultText;

	bIsClicked = isClicked;
}

void SFButton::SetHovered(bool isHovered)
{
	if (!bIsClicked)
	{
		currentButton = isHovered ? &hoveredButton : &defaultButton;
		currentText = isHovered ? &hoveredText : &defaultText;
	}

	bIsHovered = isHovered;
}

void SFButton::SetDefaultText(Text &newText)
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
	drawWindow->draw(*currentButton);
	drawWindow->draw(*currentText);
}

void SFButton::SetDefaultButton(RectangleShape &newButton)
{
	defaultButton = newButton;
}

void SFButton::SetHoveredButton(RectangleShape &newButton)
{
	hoveredButton = newButton;
}

void SFButton::SetClickedButton(RectangleShape &newButton)
{
	clickedButton = newButton;
}

SFButton::~SFButton()
{
	drawWindow = nullptr;
	currentButton = nullptr;
	currentText = nullptr;
}
