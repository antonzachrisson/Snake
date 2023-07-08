#pragma once

#include "SFML/Graphics.hpp"
#include <time.h>

class Apple
{
public:
	Apple();
	sf::RectangleShape shape{ sf::Vector2f(20.0f, 20.0f) };
	int posx;
	int posy;
};