#ifndef MAIN_SFBUTTON_CLASS
#define MAIN_SFBUTTON_CLASS

#include <iostream>
#include <SFML\Graphics.hpp>

using namespace std;
using namespace sf;

class SFButton
{
public:
	SFButton(RenderWindow *window, char *functName, char *text = "", float x = 0.f, float y = 0.f, float width = 50.f, float height = 25.f);
	~SFButton();

	void draw();
	void OnClick();
	void SetClicked(bool isClicked);
	void SetHovered(bool isHovered);

	// Setter functions
	void SetDefaultText(Text &newText);
	void setClickedText(Text &newText);
	void setHoveredText(Text &newText);

	void SetDefaultButton(RectangleShape &newButton);
	void SetHoveredButton(RectangleShape &newButton);
	void SetClickedButton(RectangleShape &newButton);

	// Getter functions
	RectangleShape GetDefaultButton() const { return defaultButton; };
	RectangleShape GetHoveredButton() const { return hoveredButton; };
	RectangleShape GetClickedButton() const { return clickedButton; };
	RectangleShape GetCurrentButton() const { return *currentButton; };

	Text GetDefaultText() const { return defaultText; };
	Text GetHoveredText() const { return hoveredText; };
	Text GetClickedText() const { return clickedText; };
	Text GetCurrentText() const { return *currentText; };

	bool IsHovered() const { return bIsHovered; };
	bool IsClicked() const { return bIsClicked; };

private:
	RectangleShape defaultButton;
	RectangleShape hoveredButton;
	RectangleShape clickedButton;
	RectangleShape *currentButton;

	RenderWindow *drawWindow;

	Text defaultText;
	Text clickedText;
	Text hoveredText;
	Text *currentText;

	char *functionName;
	bool bIsClicked = false;
	bool bIsHovered = false;
};

#endif