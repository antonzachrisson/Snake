#pragma once

#include "SFML/Graphics.hpp"
#include <list>

class Snake
{
public:
	Snake(float x, float y);
	sf::RectangleShape shape{ sf::Vector2f(20.0f, 20.0f) };
	void changemove_snake(int applesEaten, std::vector<Snake*> &snakeBody);
	void setDirection();
	float headposx;
	float headposy;
	float velx;
	float vely;
	int numFrames;
	std::list<sf::Vector2f> lastPos;
	std::string direction;
};

