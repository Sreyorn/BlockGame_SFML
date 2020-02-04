#ifndef	COLLISIONMANAGER_H
#define COLLISIONMANAGER_H

#include <SFML/Graphics.hpp>
#include "Ball.h"
#include "Paddle.h"

/// <summary>
/// Collision Manager class for collision detections between a ball and (a paddle or a block).
/// </summary>
class CollisionManager
{
public:
	CollisionManager() {}

	/// <summary>
	/// If there is a collision between the ball and the paddle, the ball needs to bounce away in the opposite direction. The percentage of the minimum 
	/// degree in decimal that the ball travels must be recalculated.
	/// </summary>
	/// <returns>
	/// Returns if there is a collision between the ball and the paddle.
	/// </returns>
	bool isPaddleCollision(Ball &ball, const Paddle &paddle);

	/// <summary>
	/// If there is a collision between the ball and a block, the ball needs to bounce away in the opposite direction. The percentage of the minimum 
	/// degree in decimal that the ball travels must be recalculated.
	/// </summary>
	/// <returns>
	/// Returns if there is a collision between the ball and a block.
	/// </returns>
	bool isBlockCollision(Ball &ball, const sf::RectangleShape &block);
};

#endif