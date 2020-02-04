#include "Ball.h"
#include "TL.h"

#define PI 3.14159265

void Ball::randomDirection()
{
	goingLeft = TL::getRandomNumber(0, 1) != 0;
}

Ball::Ball(const sf::CircleShape &ballShape, const int ballSpeed, const double minAngleInDegrees, const double maxAngleInDegrees)
	: ball(ballShape), speed(static_cast<float>(ballSpeed)), minDegree(minAngleInDegrees)
{
	originalPosition = ball.getPosition();

	randomDirection();

	if (speed < 0.0f)
		speed = 0.0f;

	double maxDegree = maxAngleInDegrees;

	if (minDegree < 30.0)
		minDegree = 30.0;
	else if (minDegree > 75.0)
		minDegree = 75.0;

	if (maxDegree < 30.0)
		maxDegree = 30.0;
	else if (maxDegree > 75.0)
		maxDegree = 75.0;

	if (minDegree > maxDegree)
	{
		double temp = minDegree;
		minDegree = maxDegree;
		maxDegree = minDegree;
	}

	maxMinDif = maxDegree - minDegree;
}

sf::CircleShape Ball::getBall() const
{
	return ball;
}

bool Ball::getVerticalDirection() const
{
	return goingUp;
}

void Ball::setPercentOfDegreesDifInDecimal(const double decimalPercentOfDegreeDifference)
{
	if ((decimalPercentOfDegreeDifference >= 0.0) && (decimalPercentOfDegreeDifference <= 1.0))
	{
		percentOfDegreesDifInDecimal = decimalPercentOfDegreeDifference;
	}
}

void Ball::setHorizontalDirection(const bool left)
{
	goingLeft = left;
}

void Ball::setVerticalDirection(const bool up)
{
	goingUp = up;
}

void Ball::toggleVerticalDirection()
{
	goingUp = !goingUp;
}

void Ball::move(const float deltaTime)
{
	if (deltaTime > 0.0f)
	{
		float xDir = (goingLeft ? -1.0f : 1.0f);
		float yDir = (goingUp ? -1.0f : 1.0f);
		float cosX = static_cast<float>(cos(((percentOfDegreesDifInDecimal * maxMinDif) + minDegree) * PI / 180.0));
		float sinY = static_cast<float>(sin(((percentOfDegreesDifInDecimal * maxMinDif) + minDegree) * PI / 180.0));
		float x = xDir * speed * cosX * deltaTime;
		float y = yDir * speed * sinY * deltaTime;

		ball.move(sf::Vector2f(x, y));
	}
}

void Ball::update(sf::RenderWindow &window)
{
	window.draw(ball);
}

void Ball::reset()
{
	ball.setPosition(originalPosition);
	randomDirection();
	goingUp = false;
}