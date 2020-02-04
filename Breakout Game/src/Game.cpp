#include "Game.h"
#include "TL.h"
#include <ctime>
#include <map>

void Game::createMainMenu()
{
	sf::Text gameTitle(std::string("Breakout"), font, fontSize);
	gameTitle.setStyle(sf::Text::Bold);
	gameTitle.setColor(sf::Color::Black);
	gameTitle.setOrigin(gameTitle.getGlobalBounds().width / 2.0f, gameTitle.getGlobalBounds().height / 2.0f);
	gameTitle.setPosition(viewWidth / 2.0f, viewHeight / 8.0f);

	sf::Text gameCreatorName(std::string("By Tony Liang"), font, fontSize);
	gameCreatorName.setStyle(sf::Text::Bold);
	gameCreatorName.setColor(sf::Color::Black);
	gameCreatorName.setOrigin(gameCreatorName.getGlobalBounds().width / 2.0f, gameCreatorName.getGlobalBounds().height / 2.0f);
	gameCreatorName.setPosition(viewWidth / 2.0f, viewHeight * 3.0f / 16.0f);

	std::vector<sf::Text> texts;
	texts.push_back(gameTitle);
	texts.push_back(gameCreatorName);

	sf::Text playGameText(std::string("Play Game"), font, fontSize);
	playGameText.setStyle(sf::Text::Bold);
	playGameText.setColor(sf::Color::Black);
	playGameText.setOrigin(playGameText.getGlobalBounds().width / 2.0f, playGameText.getGlobalBounds().height / 2.0f);
	playGameText.setPosition(viewWidth / 2.0f, viewHeight * 3.0f / 8.0f);

	sf::Text howToPlayText(std::string("How To Play"), font, fontSize);
	howToPlayText.setStyle(sf::Text::Bold);
	howToPlayText.setColor(sf::Color::Black);
	howToPlayText.setOrigin(howToPlayText.getGlobalBounds().width / 2.0f, howToPlayText.getGlobalBounds().height / 2.0f);
	howToPlayText.setPosition(viewWidth / 2.0f, viewHeight / 2.0f);

	sf::Text exitText(std::string("Exit"), font, fontSize);
	exitText.setStyle(sf::Text::Bold);
	exitText.setColor(sf::Color::Black);
	exitText.setOrigin(exitText.getGlobalBounds().width / 2.0f, exitText.getGlobalBounds().height / 2.0f);
	exitText.setPosition(viewWidth / 2.0f, viewHeight * 0.9f);

	std::map<std::string, sf::Text> btns = { {std::string("Playing"), playGameText}, {std::string("How To Play"), howToPlayText}, {std::string("Exit"), 
		exitText} };

	mainMenu = Menu(texts, btns);
}

void Game::createHowToPlayMenu()
{
	sf::Text howToPlayTitle(std::string("How To Play"), font, fontSize);
	howToPlayTitle.setStyle(sf::Text::Bold);
	howToPlayTitle.setColor(sf::Color::Black);
	howToPlayTitle.setOrigin(howToPlayTitle.getGlobalBounds().width / 2.0f, howToPlayTitle.getGlobalBounds().height / 2.0f);
	howToPlayTitle.setPosition(viewWidth / 2.0f, viewHeight / 8.0f);

	sf::Text instructions(std::string("A/D or Left/Right keys to move paddle."), font, fontSize);
	instructions.setStyle(sf::Text::Bold);
	instructions.setColor(sf::Color::Black);
	instructions.setOrigin(instructions.getGlobalBounds().width / 2.0f, instructions.getGlobalBounds().height / 2.0f);
	instructions.setPosition(viewWidth / 2.0f, viewHeight * 3.0f / 8.0f);

	sf::Text instructions2(std::string("Destroy all the blocks to win."), font, fontSize);
	instructions2.setStyle(sf::Text::Bold);
	instructions2.setColor(sf::Color::Black);
	instructions2.setOrigin(instructions2.getGlobalBounds().width / 2.0f, instructions2.getGlobalBounds().height / 2.0f);
	instructions2.setPosition(viewWidth / 2.0f, viewHeight / 2.0f);

	std::vector<sf::Text> texts;
	texts.push_back(howToPlayTitle);
	texts.push_back(instructions);
	texts.push_back(instructions2);

	sf::Text returnText(std::string("Return"), font, fontSize);
	returnText.setStyle(sf::Text::Bold);
	returnText.setColor(sf::Color::Black);
	returnText.setOrigin(returnText.getGlobalBounds().width / 2.0f, returnText.getGlobalBounds().height / 2.0f);
	returnText.setPosition(viewWidth * 0.9f, viewHeight * 0.9f);

	std::map<std::string, sf::Text> btns = { { std::string("Return"), returnText } };

	howToPlayMenu = Menu(texts, btns);
}

void Game::createDifficultyMenu()
{
	sf::Text gameTitle(std::string("Choose A Difficulty"), font, fontSize);
	gameTitle.setStyle(sf::Text::Bold);
	gameTitle.setColor(sf::Color::Black);
	gameTitle.setOrigin(gameTitle.getGlobalBounds().width / 2.0f, gameTitle.getGlobalBounds().height / 2.0f);
	gameTitle.setPosition(viewWidth / 2.0f, viewHeight / 8.0f);

	std::vector<sf::Text> texts;
	texts.push_back(gameTitle);

	sf::Text easyModeText(std::string("Easy"), font, fontSize);
	easyModeText.setStyle(sf::Text::Bold);
	easyModeText.setColor(sf::Color::Black);
	easyModeText.setOrigin(easyModeText.getGlobalBounds().width / 2.0f, easyModeText.getGlobalBounds().height / 2.0f);
	easyModeText.setPosition(viewWidth / 2.0f, viewHeight * 3.0f / 8.0f);

	sf::Text mediumModeText(std::string("Medium"), font, fontSize);
	mediumModeText.setStyle(sf::Text::Bold);
	mediumModeText.setColor(sf::Color::Black);
	mediumModeText.setOrigin(mediumModeText.getGlobalBounds().width / 2.0f, mediumModeText.getGlobalBounds().height / 2.0f);
	mediumModeText.setPosition(viewWidth / 2.0f, viewHeight / 2.0f);

	sf::Text hardModeText(std::string("Hard"), font, fontSize);
	hardModeText.setStyle(sf::Text::Bold);
	hardModeText.setColor(sf::Color::Black);
	hardModeText.setOrigin(hardModeText.getGlobalBounds().width / 2.0f, hardModeText.getGlobalBounds().height / 2.0f);
	hardModeText.setPosition(viewWidth / 2.0f, viewHeight * 5.0f / 8.0f);

	sf::Text returnText(std::string("Return"), font, fontSize);
	returnText.setStyle(sf::Text::Bold);
	returnText.setColor(sf::Color::Black);
	returnText.setOrigin(returnText.getGlobalBounds().width / 2.0f, returnText.getGlobalBounds().height / 2.0f);
	returnText.setPosition(viewWidth * 0.9f, viewHeight * 0.9f);

	std::map<std::string, sf::Text> btns = { { std::string("Easy"), easyModeText } ,{ std::string("Medium"), mediumModeText } ,{ std::string("Hard"), 
		hardModeText } ,{ std::string("Return"), returnText } };

	difficultyMenu = Menu(texts, btns);
}

void Game::createGameOverMenu(Menu &menu, const std::string &description)
{
	sf::Text gameTitle(std::string("Game Over"), font, fontSize);
	gameTitle.setStyle(sf::Text::Bold);
	gameTitle.setColor(sf::Color::Black);
	gameTitle.setOrigin(gameTitle.getGlobalBounds().width / 2.0f, gameTitle.getGlobalBounds().height / 2.0f);
	gameTitle.setPosition(viewWidth / 2.0f, viewHeight / 8.0f);

	sf::Text youWinOrLoseText(description, font, fontSize);
	youWinOrLoseText.setStyle(sf::Text::Bold);
	youWinOrLoseText.setColor(sf::Color::Black);
	youWinOrLoseText.setOrigin(youWinOrLoseText.getGlobalBounds().width / 2.0f, youWinOrLoseText.getGlobalBounds().height / 2.0f);
	youWinOrLoseText.setPosition(viewWidth / 2.0f, viewHeight * 3.0f / 8.0f);

	std::vector<sf::Text> texts;
	texts.push_back(gameTitle);
	texts.push_back(youWinOrLoseText);


	sf::Text returnText(std::string("Return"), font, fontSize);
	returnText.setStyle(sf::Text::Bold);
	returnText.setColor(sf::Color::Black);
	returnText.setOrigin(returnText.getGlobalBounds().width / 2.0f, returnText.getGlobalBounds().height / 2.0f);
	returnText.setPosition(viewWidth * 0.9f, viewHeight * 0.9f);

	std::map<std::string, sf::Text> btns = { { std::string("Return"), returnText } };

	menu = Menu(texts, btns);
}

std::map<int, std::vector<sf::RectangleShape>> Game::generateBlocks(const int totalBlocks)
{
	std::map<int, std::vector<sf::RectangleShape>> blocks;

	const float blockWidth = 200.0f, blockHeight = 50.0f;
	const int rows = 10, cols = 9;

	int totalBlocksRemoved = ((totalBlocks >= 0) && (totalBlocks <= rows * cols)) ? ((rows * cols) - totalBlocks) : (rows * cols);

	for (int row = 0; row < rows; ++row)
	{
		sf::Color color(TL::getRandomNumber(0, 255), TL::getRandomNumber(0, 255), TL::getRandomNumber(0, 255), 255);

		for (int col = 0; col < cols; ++col)
		{
			sf::RectangleShape block(sf::Vector2f(blockWidth, blockHeight));
			block.setOrigin(blockWidth / 2.0f, blockHeight / 2.0f);
			block.setPosition(sf::Vector2f(60.0f + (blockWidth / 2.0f) + (blockWidth * static_cast<float>(col)), 50.0f + (blockHeight / 2.0f)
				+ (blockHeight * static_cast<float>(row))));
			block.setFillColor(color);
			block.setOutlineColor(sf::Color::Black);
			block.setOutlineThickness(1.0f);
			blocks[row].push_back(block);
		}
	}

	if (totalBlocksRemoved != rows * cols)
	{
		int currentBlocksRemoved = 0;

		while (currentBlocksRemoved != totalBlocksRemoved)
		{
			int r = TL::getRandomNumber(0, 9);

			if (blocks[r].size() > 0)
			{
				int c = (blocks[r].size() == 1) ? 0 : TL::getRandomNumber(0, blocks[r].size() - 1);

				blocks[r].erase(blocks[r].begin() + c);
				++currentBlocksRemoved;
			}
		}
	}

	return blocks;
}

Game::Game()
{
	font.loadFromFile("Fonts/TooneyNoodleNF.ttf");
	fontSize = 30;

	createMainMenu();
	createHowToPlayMenu();
	createDifficultyMenu();
	createGameOverMenu(gameOverMenu, std::string("You win!"));
	createGameOverMenu(gameOver2Menu, std::string("You lose!"));

	sf::RectangleShape paddleShape(sf::Vector2f(200, 25));
	paddleShape.setOrigin(sf::Vector2f(paddleShape.getSize().x / 2.0f, paddleShape.getSize().y / 2.0f));
	paddleShape.setPosition(sf::Vector2f(viewWidth / 2.0f, viewHeight - 2.0f * paddleShape.getSize().y));
	paddleShape.setFillColor(sf::Color::Blue);
	paddleShape.setOutlineColor(sf::Color::Black);
	paddleShape.setOutlineThickness(1.0f);

	paddle = Paddle(paddleShape, 1000, static_cast<int>(viewWidth));

	sf::CircleShape ballShape(15.0f);
	ballShape.setOrigin(sf::Vector2f(ballShape.getRadius(), ballShape.getRadius()));
	ballShape.setPosition(sf::Vector2f(viewWidth / 2.0f, viewHeight - 4.0f * paddleShape.getSize().y));
	ballShape.setFillColor(sf::Color::Red);
	ballShape.setOutlineColor(sf::Color::Black);
	ballShape.setOutlineThickness(1.0f);
	ball = Ball(ballShape, 500);
}

void Game::startGame()
{
	using namespace sf;

	RenderWindow window(VideoMode::getDesktopMode(), "Breakout", Style::Fullscreen);
	window.setFramerateLimit(60);

	View view(FloatRect(0, 0, viewWidth, viewHeight));

	window.setView(view);

	Clock clock;

	std::map<int, std::vector<RectangleShape>> blocks;

	bool isPlaying = false;
	bool isMainMenu = true, isHowToPlayMenu = false, isChooseDifficultyMenu = false, isGameOverMenu = false;
	bool isWin = false;

	time_t previousTimeForPaddleCollision = time(0) - 1.0;

	while (window.isOpen())
	{
		Event event;

		// Record deltatime every frame
		float dt = clock.restart().asSeconds();

		while (window.pollEvent(event))
		{

			// Exit the game
			if ((event.type == Event::Closed) || Keyboard::isKeyPressed(Keyboard::Escape))
			{
				window.close();
			}

			if (!isPlaying)
			{
				std::string mMCurrentButtonSelected = mainMenu.mouseAtButton(window);
				std::string hTPMCurrentButtonSelected = howToPlayMenu.mouseAtButton(window);
				std::string dMCurrentButtonSelected = difficultyMenu.mouseAtButton(window);
				std::string gOMCurrentButtonSelected = gameOverMenu.mouseAtButton(window);
				std::string gO2MCurrentButtonSelected = gameOver2Menu.mouseAtButton(window);

				if (event.type == Event::MouseButtonReleased && event.mouseButton.button == sf::Mouse::Left)
				{
					if (isMainMenu)
					{
						if (mMCurrentButtonSelected == "Play Game")
						{
							isMainMenu = false;
							isChooseDifficultyMenu = true;
						}
						else if (mMCurrentButtonSelected == "How To Play")
						{
							isMainMenu = false;
							isHowToPlayMenu = true;
						}
						else if (mMCurrentButtonSelected == "Exit")
						{
							window.close();
						}
					}
					else if (isHowToPlayMenu && (hTPMCurrentButtonSelected == "Return"))
					{
						isMainMenu = true;
						isHowToPlayMenu = false;
					}
					else if (isChooseDifficultyMenu)
					{
						if (dMCurrentButtonSelected == "Easy")
						{
							isPlaying = true;
							isChooseDifficultyMenu = false;
							blocks = generateBlocks(30);
						}
						else if (dMCurrentButtonSelected == "Medium")
						{
							isPlaying = true;
							isChooseDifficultyMenu = false;
							blocks = generateBlocks(60);
						}
						else if (dMCurrentButtonSelected == "Hard")
						{
							isPlaying = true;
							isChooseDifficultyMenu = false;
							blocks = generateBlocks(90);
						}
						else if (dMCurrentButtonSelected == "Return")
						{
							isMainMenu = true;
							isChooseDifficultyMenu = false;
						}
					}
					else if (isGameOverMenu && ((gOMCurrentButtonSelected == "Return") || (gO2MCurrentButtonSelected == "Return")))
					{
						isMainMenu = true;
						isGameOverMenu = false;
						isWin = false;
						blocks.clear();
						paddle.reset();
						ball.reset();
					}
				}
			}
		}

		if (isPlaying)
		{
			// Use left and right arrow keys or A and D keys for paddle movement
			if (Keyboard::isKeyPressed(Keyboard::Left) || Keyboard::isKeyPressed(Keyboard::A))
			{
				paddle.move(dt, true);
			}

			if (Keyboard::isKeyPressed(Keyboard::Right) || Keyboard::isKeyPressed(Keyboard::D))
			{
				paddle.move(dt, false);
			}

			ball.move(dt);

			if ((ball.getBall().getPosition().x - ball.getBall().getRadius()) < 0)
			{
				ball.setHorizontalDirection(false);
			}
			else if ((ball.getBall().getPosition().x + ball.getBall().getRadius()) > viewWidth)
			{
				ball.setHorizontalDirection(true);
			}
			else if ((ball.getBall().getPosition().y - ball.getBall().getRadius()) < 0)
			{
				ball.setVerticalDirection(false);
			}
			else if ((ball.getBall().getPosition().y + ball.getBall().getRadius()) > viewHeight)
			{
				isGameOverMenu = true;
				isPlaying = false;
			}

			// Delay this check so the ball doesn't occasionally hug the paddle and fall down the screen.
			if (difftime(time(0), previousTimeForPaddleCollision) >= (1/60.0))
			{
				if (collisionManager.isPaddleCollision(ball, paddle))
				{
					ball.toggleVerticalDirection();
					previousTimeForPaddleCollision = time(0);
				}
			}

			for (int i = 0; i < static_cast<int>(blocks.size()); ++i)
			{
				if (blocks[i].size() > 0)
				{
					if ((ball.getBall().getPosition().y >= blocks[i][0].getGlobalBounds().top) &&
						(ball.getBall().getPosition().y <= (blocks[i][0].getGlobalBounds().top + blocks[i][0].getGlobalBounds().height)))
					{
						for (int j = 0; j < static_cast<int>(blocks[i].size()); ++j)
						{
							if (collisionManager.isBlockCollision(ball, blocks[i][j]))
							{
								if (j != (blocks[i].size() - 1))
								{
									blocks[i][j] = std::move(blocks[i].back());
								}
								blocks[i].pop_back();
								break;
							}
						}
						break;
					}
				}
			}

			bool noMoreBlocks = true;
			for (int i = 0; i < static_cast<int>(blocks.size()); ++i)
			{
				if (blocks[i].size() > 0)
				{
					noMoreBlocks = false;
					break;
				}
			}

			if (noMoreBlocks)
			{
				isWin = true;
				isGameOverMenu = true;
				isPlaying = false;
			}
		}

		// Draw the game
		window.clear(Color(200, 200, 200, 255));

		if (!isPlaying)
		{
			if (isMainMenu)
			{
				mainMenu.update(window);
			}
			else if (isHowToPlayMenu)
			{
				howToPlayMenu.update(window);
			}
			else if (isChooseDifficultyMenu)
			{
				difficultyMenu.update(window);
			}
			else if (isGameOverMenu)
			{
				if (isWin)
				{
					gameOverMenu.update(window);
				}
				else
				{
					gameOver2Menu.update(window);
				}
			}
		}
		else
		{
			for (int row = 0; row < static_cast<int>(blocks.size()); ++row)
			{
				for (sf::RectangleShape block : blocks[row])
				{
					window.draw(block);
				}
			}

			paddle.update(window);

			ball.update(window);
		}

		window.display();
	}
}