#include "Snake.h"

Snake::Snake(float x, float y)
{
	headposx = x;
	headposy = y;
	velx = 1.0f;
	vely = 0.0f;
	shape.setPosition(x, y);
	shape.setFillColor(sf::Color::Green);
	numFrames = 0;
};

void Snake::setDirection()
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
	{
		direction = "up";
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
	{
		direction = "down";
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
	{
		direction = "left";
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
	{
		direction = "right";
	}
}

void Snake::changemove_snake(int applesEaten, std::vector<Snake*> &snakeBody)
{
	if (direction == "up")
	{
		velx = 0.0f;
		vely = -1.0f;
	}
	if (direction == "down")
	{
		velx = 0.0f;
		vely = 1.0f;
	}
	if (direction == "left")
	{
		velx = -1.0f;
		vely = 0.0f;
	}
	if (direction == "right")
	{
		velx = 1.0f;
		vely = 0.0f;
	}

	shape.move(velx, vely);

	for (int i = 0; i <= applesEaten; i++)
	{
		snakeBody[i]->lastPos.push_back(snakeBody[i]->shape.getPosition());
		if (i > 0)
		{
			snakeBody[i]->shape.setPosition(snakeBody[i - 1]->lastPos.front());
		}
		if (snakeBody[i]->numFrames >= 20)
		{
			snakeBody[i]->lastPos.pop_front();
		}
		snakeBody[i]->numFrames += 1;
	}
}


