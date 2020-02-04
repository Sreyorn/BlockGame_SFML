#include "Paddle.h"

Paddle::Paddle(const sf::RectangleShape &paddleShape, const int paddleSpeed, const int maximumX)
	: paddle(paddleShape), speed(static_cast<float>(paddleSpeed)), maxX(static_cast<float>(maximumX))
{
	originalPosition = paddle.getPosition();

	if (speed < 0.0f)
		speed = 0.0f;

	if (maxX < 0.0f)
		maxX = 0.0f;
}

sf::RectangleShape Paddle::getPaddle() const
{
	return paddle;
}

void Paddle::move(const float deltaTime, const bool left)
{
	if (deltaTime > 0.0f)
	{
		float x = speed * deltaTime;
		if (left)
		{
			if ((paddle.getPosition().x - x) > (paddle.getSize().x / 2.0f))
			{
				paddle.move(sf::Vector2f(-x, 0.0f));
			}
			else
			{
				paddle.move(sf::Vector2f((paddle.getSize().x / 2.0f) - paddle.getPosition().x, 0.0f));
			}
		}
		else
		{
			if ((paddle.getPosition().x + x) < (maxX - (paddle.getSize().x / 2.0f)))
			{
				paddle.move(sf::Vector2f(x, 0.0f));
			}
			else
			{
				paddle.move(sf::Vector2f(maxX - paddle.getPosition().x - (paddle.getSize().x / 2.0f), 0.0f));
			}
		}
	}
}

void Paddle::update(sf::RenderWindow &window)
{
	window.draw(paddle);
}

void Paddle::reset()
{
	paddle.setPosition(originalPosition);
}