#include "Menu.h"

Menu::Menu(const std::vector<sf::Text> &texts, const std::map<std::string, sf::Text> &buttons)
	: txts(texts), btns(buttons)
{
	name = txts[0].getString();
}

std::string Menu::getName() const
{
	return name;
}

std::map<std::string, sf::Text> Menu::getButtons() const
{
	return btns;
}

std::string Menu::mouseAtButton(sf::RenderWindow &window)
{
	sf::Vector2i pixelPos = sf::Mouse::getPosition(window);

	// Convert mouse position which is in pixels to world coordinates
	sf::Vector2f worldPos = window.mapPixelToCoords(pixelPos);

	currentButton = sf::Text();

	for (const auto &button : btns)
	{
		float buttonX = button.second.getGlobalBounds().left;
		float buttonY = button.second.getGlobalBounds().top;
		float buttonXMax = buttonX + button.second.getGlobalBounds().width;
		float buttonYMax = buttonY + button.second.getGlobalBounds().height;

		if ((worldPos.x >= buttonX)
			&& (worldPos.x <= buttonXMax)
			&& (worldPos.y >= buttonY)
			&& (worldPos.y <= buttonYMax))
		{
			currentButton = button.second;
			return button.second.getString();
		}
	}
	return "";
}

void Menu::update(sf::RenderWindow &window)
{
	for (const sf::Text &text : txts)
		window.draw(text);

	for (const auto &button : btns)
		window.draw(button.second);

	sf::RectangleShape currentButtonSelection(sf::Vector2f(currentButton.getGlobalBounds().width, currentButton.getGlobalBounds().height));
	currentButtonSelection.setOrigin(currentButton.getOrigin().x, currentButton.getOrigin().y);
	currentButtonSelection.setPosition(sf::Vector2f(currentButton.getGlobalBounds().left + (currentButton.getGlobalBounds().width / 2.0f),
		currentButton.getGlobalBounds().top + (currentButton.getGlobalBounds().height / 2.0f)));
	currentButtonSelection.setFillColor(sf::Color::Transparent);
	currentButtonSelection.setOutlineColor(sf::Color::Yellow);
	currentButtonSelection.setOutlineThickness(5.0f);

	window.draw(currentButtonSelection);
}