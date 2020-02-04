#ifndef MENU_H
#define MENU_H

#include <SFML/Graphics.hpp>
#include <map>
#include <string>
#include <vector>

/// <summary>
/// Menu class for creating a menu.
/// </summary>
class Menu
{
private:
	std::string name;
	std::vector<sf::Text> txts;
	std::map<std::string, sf::Text> btns;
	sf::Text currentButton;
public:
	Menu() {}

	/// <summary>
	/// Construct the menu of the game with texts and buttons.
	/// </summary>
	/// <param name="texts">
	/// List of texts to be displayed in this menu which must be created beforehand.
	/// </param>
	/// <param name="buttons">
	/// List of buttons which is created beforehand. Each button is paired with its user defined text as a key.
	/// </param>
	Menu(const std::vector<sf::Text> &texts, const std::map<std::string, sf::Text> &buttons);

	std::string getName() const;
	std::map<std::string, sf::Text> getButtons() const;

	/// <summary>
	/// Check which button the mouse is hovering over on the menu.
	/// </summary>
	/// <param name="window">
	/// The render window.
	/// </param>
	/// <returns>
	/// Returns the button the mouse is currently hovering over if any.
	/// </returns>
	std::string mouseAtButton(sf::RenderWindow &window);

	/// <summary>
	/// Draw the texts and buttons on the render window to represent the menu. Draw selection rectangle outline if the mouse hovers over any buttons.
	/// </summary>
	/// <param name="window">
	/// The render window.
	/// </param>
	void update(sf::RenderWindow &window);
};

#endif