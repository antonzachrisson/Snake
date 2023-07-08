#include "Game.h"


Game::Game(unsigned int &screenWidth, unsigned int &screenHeight, const char* &title)
{
	screenWidth = 640;
	screenHeight = 480;
	title = "Snake";
	Apple* apple = new Apple();
	Snake* snake = new Snake(10.0f, 10.0f);
	snakeBody.push_back(snake);
	applesEaten = 0;
	appleptr = apple;
	snakeptr = snake;
	elapsedTime = 0.0f;
	running = true;
};

Game::~Game()
{
}

void Game::collision(Apple* $apple, Snake*& snake)
{
	sf::Vector2f position = snakeptr->shape.getPosition();
	if (position.x > 620.0f || position.x < 0.0f || position.y > 460.0f || position.y < 0.0f)
	{
		running = false;
	}
	sf::Rect<float> snakeRect = snakeptr->shape.getGlobalBounds();
	for (int i = 2; i <= applesEaten; i++)
	{
		colliders.push_back(snakeBody[i]->shape.getGlobalBounds());
	}
	sf::Rect<float> appleRect = appleptr->shape.getGlobalBounds();
	for (int i = 0; i <= applesEaten - 2; i++)
	{
		if (snakeRect.intersects(colliders[i]))
		{
			running = false;
		}
	}
	if (snakeRect.intersects(appleRect))
	{
		delete appleptr;
		Apple* apple = new Apple();
		appleptr = apple;
		sf::Vector2f position = snakeBody[applesEaten]->lastPos.front();
		snakeBody.push_back(new Snake(position.x, position.y));
		applesEaten += 1;
	}
	colliders.clear();
}

bool Game::Update(float deltaTime)
{
	if (running == true)
	{
		elapsedTime += deltaTime;
		snakeptr->setDirection();
		collision(appleptr, snakeptr);
		snakeptr->changemove_snake(applesEaten, snakeBody);
		return true;
	}
	return false;
}

void Game::Draw(sf::RenderWindow& window)
{
	window.draw(appleptr->shape);
	for (int i = 0; i <= applesEaten; i++)
	{
		window.draw(snakeBody[i]->shape);
	}
}
