#ifndef	PADDLE_H
#define PADDLE_H

#include <SFML/Graphics.hpp>

/// <summary>
/// Paddle class for creating the paddle.
/// </summary>
class Paddle
{
private:
	sf::RectangleShape paddle;
	sf::Vector2f originalPosition = sf::Vector2f(0.0f, 0.0f);

	float speed = 0.0f, maxX = 0.0f;
public:
	Paddle() {}

	/// <summary>
	/// Construct the paddle of the game and set its speed and its max X bound.
	/// </summary>
	/// <param name="paddleShape">
	/// The rectangle shape object that represents the paddle. The object's size, origin, position, color, outline color, and outline thickness need to be 
	/// set beforehand.
	/// </param>
	/// <param name="paddleSpeed">
	/// The speed of the paddle in pixels. Min: 0
	/// </param>
	/// <param name="maximumX">
	/// The maximum x position the paddle can go in pixels(Recommended: Use the screen's width pixel value).
	/// </param>
	Paddle(const sf::RectangleShape &paddleShape, const int paddleSpeed, const int maximumX);

	sf::RectangleShape getPaddle() const;

	/// <summary>
	/// Move the paddle left or right using deltatime because of frame dependent.
	/// </summary>
	/// <param name="deltaTime">
	/// The change in time per frame in seconds.
	/// </param>
	/// <param name="left">
	/// Move left or right.
	/// </param>
	void move(const float deltaTime, const bool left);

	/// <summary>
	/// Draw the paddle on the render window.
	/// </summary>
	/// <param name="window">
	/// The render window.
	/// </param>
	void update(sf::RenderWindow &window);

	void reset();
};

#endif