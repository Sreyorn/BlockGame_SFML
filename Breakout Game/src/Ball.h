#ifndef BALL_H
#define BALL_H

#include <SFML/Graphics.hpp>

/// <summary>
/// Ball class for creating the ball.
/// </summary>
class Ball
{
private:
	sf::CircleShape ball;
	sf::Vector2f originalPosition = sf::Vector2f(0.0f, 0.0f);

	double minDegree = 30.0, maxMinDif = 45.0, percentOfDegreesDifInDecimal = 0.0;
	float speed = 0.0f;
	bool goingUp = false, goingLeft = false;

	void randomDirection();
public:
	Ball() {}

	/// <summary>
	/// Construct the ball of the game and set its speed and movement ranges.
	/// </summary>
	/// <param name="ballShape">
	/// The circle shape object that represents the ball. The object's radius, origin, position, color, outline color, and outline thickness need to be 
	/// set beforehand.
	/// </param>
	/// <param name="ballSpeed">
	/// The max speed in pixels of the ball. Min: 0
	/// </param>
	/// <param name="minAngleInDegrees">
	/// The minimum angle in degrees that the ball can travel. Degree range(30 to 75)
	/// </param>
	/// <param name="maxAngleInDegrees">
	/// The maximum angle in degrees that the ball can travel. Degree range(30 to 75)
	/// </param>
	Ball(const sf::CircleShape &ballShape, const int ballSpeed = 0, const double minAngleInDegrees = 30.0,
		const double maxAngleInDegrees = 75.0);

	sf::CircleShape getBall() const;
	bool getVerticalDirection() const;

	/// <summary>
	/// Set the percent of the difference between the minimum and maximum degree in decimal.
	/// </summary>
	/// <param name="decimalPercentOfDegreeDifference">
	/// The percentage of the difference between the minimum and maximum degree in decimal that the ball can travel. Range: (0.00 to 1.00)
	/// </param>
	void setPercentOfDegreesDifInDecimal(const double decimalPercentOfDegreeDifference);

	void Ball::setHorizontalDirection(const bool left);
	void Ball::setVerticalDirection(const bool up);
	void Ball::toggleVerticalDirection();

	/// <summary>
	/// Move the ball using deltatime because of frame dependent.
	/// </summary>
	/// <param name="deltaTime">
	/// The change in time per frame in seconds.
	/// </param>
	void move(const float deltaTime);

	/// <summary>
	/// Draw the ball on the render window.
	/// </summary>
	/// <param name="window">
	/// The render window.
	/// </param>
	void update(sf::RenderWindow &window);

	void reset();
};

#endif