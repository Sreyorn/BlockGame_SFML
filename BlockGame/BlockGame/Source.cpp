#include <SFML/Graphics.hpp>
#include<Windows.h>
#include<string>
#include<iostream>
using namespace std;
using namespace sf;
const float BALL_SPEED = 5.0;
Font font;
Text text;
string status;
//Class Paddle
class Paddle :public RectangleShape {
	float init_x, init_y;
public:
	Paddle(float x, float y) :init_x(x), init_y(y) {
		setSize({ 80,20 });
		setPosition(x, y);
		setFillColor(Color(0, 255, 64));
		setOrigin(0, 0);
	}
	void update(int x) { setPosition(x, init_y); }
};
//class Ball
class Ball : public CircleShape {
public:
	float speedx = BALL_SPEED, speedy = BALL_SPEED;
	Ball(float x, float y) :CircleShape(12.0) {
		setPosition(x, y);
		setFillColor(Color(255, 128, 0));
		setOrigin(0, 0);
	}
	void update();
	bool isIntersecting(Paddle &paddle);
	void handleCollision(Paddle &paddle);
};

//Class Brick
class Brick :public RectangleShape {
public:
	bool deleted = false;
	Brick(float x, float y) {
		setSize({ 60,20 });
		setPosition(x, y);
		setFillColor(Color::Yellow);
		setOrigin(0, 0);
	}
	bool isIntersecting(Ball &ball) {
		return getGlobalBounds().intersects(ball.getGlobalBounds());
	}
	void handleCollision(Ball &ball) {
		if (!isIntersecting(ball)) return;
		deleted = true;
	}
};
//Update Function
void Ball::update() {
	move(speedx, speedy);
	if ((getPosition().x) < 0)
		speedx = BALL_SPEED;
	else if ((getPosition().x + 2 * 20) > 800)
		speedx = -BALL_SPEED;
	if (getPosition().y < 0)
		speedy = BALL_SPEED;
	else if ((getPosition().y + 2 * 20) > 600)
		speedy = -BALL_SPEED;
}
bool Ball::isIntersecting(Paddle &paddle) {
	return getGlobalBounds().intersects(paddle.getGlobalBounds());
}
void Ball::handleCollision(Paddle &paddle) {
	if (!isIntersecting(paddle)) return;
	speedy = -BALL_SPEED;
	if (getPosition().x < paddle.getPosition().x)
		speedx = -BALL_SPEED;
	else
		speedx = BALL_SPEED;
}


int main() {
	//for displaying text
	/*if (!font.loadFromFile("../OpenSans_Bold.ttf")) {
		cout << "Cannot open file";
	}
	status = "Use mouse to move!";
	*/


	Ball ball = { 800.0 / 2,600.0 / 2 };
	Paddle paddle = { 800 / 2,550 };
	vector<Brick>bricks;
	for (int x = 0; x < 10; x++)
		for (int y = 0; y < 5; y++)
			bricks.push_back(Brick(x*(60 + 3) + 20, y*(20 + 3) + 40));
	RenderWindow window(VideoMode(800, 600), "My window");
	window.setFramerateLimit(60);
	while (window.isOpen()) {
		window.clear(sf::Color::Blue);
		Event event;
		while (window.pollEvent(event)) {
			if (event.type == sf::Event::Closed)
				window.close();
		}
		sf::Vector2i position = sf::Mouse::getPosition(window);
		paddle.update(position.x);
		ball.handleCollision(paddle);
		for (auto &brick : bricks)
			brick.handleCollision(ball);
		bricks.erase(remove_if(begin(bricks), end(bricks), [](Brick &b) {
			return b.deleted; }), end(bricks));
		ball.update();
		window.draw(ball);
		window.draw(paddle);
		for (auto&brick : bricks)
			window.draw(brick);
		window.display();
		// display text
		/*text.setFont(font);
		text.setString(status);
		text.setCharacterSize(20);
		text.setPosition(10, 100);*/
	}
}
