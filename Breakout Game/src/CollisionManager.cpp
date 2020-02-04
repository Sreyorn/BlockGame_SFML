#include "CollisionManager.h"

bool CollisionManager::isPaddleCollision(Ball &ball, const Paddle &paddle)
{
	float paddleXMin = paddle.getPaddle().getGlobalBounds().left;
	float paddleXMax = paddleXMin + paddle.getPaddle().getGlobalBounds().width;
	float paddleYMin = paddle.getPaddle().getGlobalBounds().top;
	float paddleYMax = paddleYMin + paddle.getPaddle().getGlobalBounds().height;

	float ballX = ball.getBall().getPosition().x;
	float ballY = ball.getBall().getPosition().y + ball.getBall().getRadius();

	if ((ballX >= paddleXMin) && (ballX <= paddleXMax) && (ballY >= paddleYMin) && (ballY <= paddleYMax))
	{
		float midPaddleX = paddle.getPaddle().getPosition().x;
		if (ballX < midPaddleX)
		{
			ball.setHorizontalDirection(true);
			ball.setPercentOfDegreesDifInDecimal(static_cast<double>(((midPaddleX - ballX) / (midPaddleX - paddleXMin))));
		}
		else if (ballX > midPaddleX)
		{
			ball.setHorizontalDirection(false);
			ball.setPercentOfDegreesDifInDecimal(static_cast<double>(((ballX - midPaddleX) / (paddleXMax - midPaddleX))));
		}
		else
		{
			ball.setPercentOfDegreesDifInDecimal(0.0);
		}
		return true;
	}
	return false;
}

bool CollisionManager::isBlockCollision(Ball &ball, const sf::RectangleShape &block)
{
	float blockLeft = block.getGlobalBounds().left;
	float blockRight = blockLeft + block.getGlobalBounds().width;
	float blockTop = block.getGlobalBounds().top;
	float blockBottom = blockTop + block.getGlobalBounds().height;

	sf::Vector2f ballTopCenter(ball.getBall().getPosition().x, ball.getBall().getGlobalBounds().top);
	sf::Vector2f ballBottomCenter(ball.getBall().getPosition().x, ball.getBall().getPosition().y + (ball.getBall().getRadius()));
	sf::Vector2f ballLeftCenter(ball.getBall().getGlobalBounds().left, ball.getBall().getPosition().y);
	sf::Vector2f ballRightCenter((ball.getBall().getPosition().x + ball.getBall().getRadius()), ball.getBall().getPosition().y);

	if (ball.getVerticalDirection() == true)
	{
		if ((ballTopCenter.x >= blockLeft) && (ballTopCenter.x <= blockRight) && (ballTopCenter.y >= blockTop) &&
			(ballTopCenter.y <= blockBottom))
		{
			ball.setVerticalDirection(false);
			return true;
		}
	}
	else
	{
		if ((ballBottomCenter.x >= blockLeft) && (ballBottomCenter.x <= blockRight) && (ballBottomCenter.y >= blockTop) &&
			(ballBottomCenter.y <= blockBottom))
		{
			ball.setVerticalDirection(true);
			return true;
		}
	}

	if ((ballLeftCenter.x >= blockLeft) && (ballLeftCenter.x <= blockRight) && (ballLeftCenter.y >= blockTop) && 
		(ballLeftCenter.y <= blockBottom))
	{
		ball.setHorizontalDirection(false);
		return true;
	}
	
	else if ((ballRightCenter.x >= blockLeft) && (ballRightCenter.x <= blockRight) && (ballRightCenter.y >= blockTop) && 
		(ballRightCenter.y <= blockBottom))
	{
		ball.setHorizontalDirection(true);
		return true;
	}

	return false;
}