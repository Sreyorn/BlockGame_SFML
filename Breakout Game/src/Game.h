#ifndef	GAME_H
#define GAME_H

#include "Ball.h"
#include "CollisionManager.h"
#include "Menu.h"
#include "Paddle.h"
#include <SFML/Graphics.hpp>
#include <vector>

/// <summary>
/// Game class for creating the Breakout game.
/// </summary>
class Game
{
private:
	const float viewWidth = 1920, viewHeight = 1080;

	sf::Font font;
	unsigned int fontSize;

	Menu mainMenu, howToPlayMenu, difficultyMenu, gameOverMenu, gameOver2Menu;

	Paddle paddle;
	
	Ball ball;

	CollisionManager collisionManager = CollisionManager();

	void createMainMenu();
	void createHowToPlayMenu();
	void createDifficultyMenu();

	/// <summary>
	/// Create the Game Over menu.
	/// </summary>
	/// <param name="menu">
	/// The Game Over menu. It must be empty. 
	/// </param>
	/// <param name="description">
	/// The text to be displayed on the menu.
	/// </param>
	void createGameOverMenu(Menu &menu, const std::string &description);

	/// <summary>
	/// Generate blocks for the game.
	/// </summary>
	/// <param name="totalBlocks">
	/// The number of blocks to generate for the game.
	/// </param>
	/// <returns>
	/// Returns the list of blocks.
	/// </returns>
	std::map<int, std::vector<sf::RectangleShape>> generateBlocks(const int totalBlocks = 30);
public:
	Game();

	void startGame();
};

#endif