#include "SFButton.h"

SFButton::SFButton(RenderWindow *window, char *text, float x, float y, float width, float height)
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
	font->loadFromFile("times.ttf");

	const float btnx = currentButton->getPosition().x, btny = currentButton->getPosition().y;
	const float btnW = currentButton->getGlobalBounds().width, btnH = currentButton->getGlobalBounds().height;

	defaultText = Text(text, *font, 15);
	float txtWidth = defaultText.getGlobalBounds().width, txtHeight = defaultText.getGlobalBounds().height;
	defaultText.setFillColor(Color::Cyan);
	defaultText.setPosition( (btnx + btnW/2) - txtWidth, (btny + btnH/2) - txtHeight );
	defaultText.setStyle(Text::Bold);

	hoveredText = Text(text, *font, 15);
	hoveredText.setFillColor(Color::Green);
	hoveredText.setPosition(btnx + txtWidth, btny + txtHeight / 2);
	hoveredText.setStyle(Text::Bold);

	clickedText = Text(text, *font, 15);
	clickedText.setFillColor(Color::White);
	clickedText.setPosition(btnx + txtWidth, btny + txtHeight / 2);
	clickedText.setStyle(Text::Bold);

	currentText = &defaultText;

	// Initialize window to draw from
	drawWindow = window;
}

void SFButton::SetClicked(bool isClicked)
{
	currentButton = isClicked ? &clickedButton : &hoveredButton;
	currentText = isClicked ? &clickedText : &hoveredText;
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

void SFButton::SetDefaultButton(RectangleShape newButton)
{
	defaultButton = newButton;
}

void SFButton::SetHoveredButton(RectangleShape newButton)
{
	hoveredButton = newButton;
}

void SFButton::SetClickedButton(RectangleShape newButton)
{
	clickedButton = newButton;
}

SFButton::~SFButton()
{
	drawWindow = nullptr;
	currentButton = nullptr;
	currentText = nullptr;
}
