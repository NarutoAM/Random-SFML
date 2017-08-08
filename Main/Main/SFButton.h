#ifndef MAIN_SFBUTTON_CLASS
#define MAIN_SFBUTTON_CLASS

#include <iostream>
#include <SFML\Graphics.hpp>

using namespace std;
using namespace sf;

class SFButton
{
public:
	/*
	* @brief Make new button
	* @param window Window to draw button to
	* @param functName name to distinguish between buttons and for their clicked actions
	* @param text Button text
	* @param x Set x location of button
	* @param y Set y location of button
	* @param width Set width of button
	* @param height Set height of button
	*/
	SFButton(RenderWindow *window, char *functName, char *text = "", float x = 0.f, float y = 0.f, float width = 50.f, float height = 25.f);
	~SFButton();

	// Draw button components to draw window
	void draw();

	// Executes when user clicks on button
	void OnClick();

	/*
	* @brief Handle all input for button, execute function at start of event loop
	* @param e Event for the function to use to handle input events
	*/
	void HandleEvents(Event &e);

	/*
	* @brief Set if the button is clicked
	* @param isClicked Sets bIsClicked to new bool
	*/
	void SetClicked(bool isClicked);

	/*
	* @brief Set if the button is being hovered on
	* @param isHovered Sets bIsHovered to new bool
	*/
	void SetHovered(bool isHovered);
	
	/* Setter functions */

	/* 
	* @brief Set the text when not being hovered or clicked on 
	* @param newText Text to show when drawn
	*/
	void SetDefaultText(Text &newText);

	/*
	* @brief Set the text when being hovered on but not clicked
	* @param newText Text to show when drawn
	*/
	void setClickedText(Text &newText);

	/*
	* @brief Set the text when being clicked
	* @param newText Text to show when drawn
	*/
	void setHoveredText(Text &newText);

	/*
	* @brief Set button when not being hovered or clicked
	* @param newButton Button to draw to window
	*/
	void SetDefaultButton(RectangleShape &newButton);

	/*
	* @brief Set button when being hovered but not clicked
	* @param newButton Button to draw to window
	*/
	void SetHoveredButton(RectangleShape &newButton);

	/*
	* @brief Set button when being hovered and clicked
	* @param newButton Button to draw to window
	*/
	void SetClickedButton(RectangleShape &newButton);

	/* Getter functions */
	
	/*
	* @return Button when not being hovered or clicked
	*/
	RectangleShape GetDefaultButton() const { return defaultButton; };

	/*
	* @return Button when being hovered but not clicked
	*/
	RectangleShape GetHoveredButton() const { return hoveredButton; };
	
	/*
	* @return Button when being hovered and clicked
	*/
	RectangleShape GetClickedButton() const { return clickedButton; };

	/*
	* @return Button thats currently being used
	*/
	RectangleShape GetCurrentButton() const { return *currentButton; };

	/*
	* @return Text when not being hovered or clicked
	*/
	Text GetDefaultText() const { return defaultText; };
	
	/*
	* @return Text when being hovered but not clicked
	*/
	Text GetHoveredText() const { return hoveredText; };
	
	/*
	* @return Text when being hovered and clicked
	*/
	Text GetClickedText() const { return clickedText; };

	/*
	* @return Text currently being used
	*/
	Text GetCurrentText() const { return *currentText; };

	/*
	* @return Weather or not the button is being hovered
	*/
	bool IsHovered() const { return bIsHovered; };

	/*
	* @return Weather or not the button is being clicked
	*/
	bool IsClicked() const { return bIsClicked; };

private:
	// Button when not being hovered or clicked
	RectangleShape defaultButton;

	// Button when being hovered but not clicked
	RectangleShape hoveredButton;

	// Button when being hovered and clicked
	RectangleShape clickedButton;

	// Button that is currently being used
	RectangleShape *currentButton;

	// Window to draw button components to
	RenderWindow *drawWindow;

	// Text when not being hovered or clicked
	Text defaultText;

	// Text when being hovered and clicked
	Text clickedText;

	// Text when being hovered but not clicked
	Text hoveredText;

	// Text currently being used
	Text *currentText;
	// Function name to distinguish between buttons
	char *functionName;

	// Weather or not the button is clicked
	bool bIsClicked = false;

	// Weather or not the button is being hovered on
	bool bIsHovered = false;
};

#endif