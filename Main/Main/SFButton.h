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
	void onClick();

   /*
	* @brief Handle all input for button, execute function at start of event loop
	* @param e Event for the function to use to handle input events
	*/
	void handleEvents(Event &e);

   /*
	* @brief Set visibility of button
	* @param isVisible Weather or not the button is visible
	*/
	void setVisible(bool isVisible);

   /*
	* @brief Set if the button is clicked
	* @param isClicked Sets bisClicked to new bool
	*/
	void setClicked(bool isClicked);

   /*
	* @brief Set if the button is being hovered on
	* @param isHovered Sets bisHovered to new bool
	*/
	void setHovered(bool isHovered);
	
	/* Setter functions */

	/*
	* @brief Set color of button
	* @param type Which state to change color
	* @param newColor Color to set the button to
	*/
	void setButtonFillColor(const uint8_t &type, const Color &newColor);

   /*
	* @brief Set color of text
	* @param type Which state to change color
	* @param newColor Color to set the text to
	*/
	void setTextFillColor(const uint8_t &type, const Color &newColor);

   /*
	* @brief Set the text when not being hovered or clicked on
	* @param type Which state is being changed
	* @param newText Text to set old text to
	*/
	void setText(const uint8_t &type, Text &newText);

   /*
	* @brief Set button when not being hovered or clicked
	* @param type Which state is being changed
	* @param newButton New button to set old button to
	*/
	void setButton(const uint8_t &type, RectangleShape &newButton);

   /*
	* @brief Sets weather or not the user can interact with the button
	* @param isEnabled true if button is enabled, false if button is disabled
	*/
	void setEnabled(bool isEnabled);

	/* Getter functions */

	/*
	* @param type Clicked, hovered, or default to return
	* @return Button that is specified in parameter
	*/
	RectangleShape &getButton(uint8_t type);
	
   /*
	* @param type Clicked, hovered, or default to return
	* @return Text that is specified in parameter
	*/
	Text getText(uint8_t type) const;

   /*
	* @return Weather or not the button is being hovered
	*/
	bool isHovered() const { return bIsHovered; };

   /*
	* @return Weather or not the button is being clicked
	*/
	bool isClicked() const { return bIsClicked; };

   /*
	* @return Weather or not the button is visible
	*/
	bool isVisible() const { return bIsVisible; };

   /*
	* @return Weather or not the button lets user interaction
	*/
	bool isEnabled() const { return bIsEnabled; };

	// Enum for easier way to change button types
	enum EButtonType : uint8_t
	{
		BT_Clicked,
		BT_Hovered,
		BT_Default,
		BT_Current
	};

	// Enum for easier way to change button types
	enum ETextType :uint8_t
	{
		TT_Clicked,
		TT_Hovered,
		TT_Default,
		TT_Current
	};

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

	// Weather or not the button is visible
	bool bIsVisible = true;

	// Weather or not the button is enabled
	bool bIsEnabled = true;
};

#endif