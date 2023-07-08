#include "Apple.h"

Apple::Apple()
{
	srand(time(nullptr));
	posx = rand() % 32;
	posy = rand() % 24;
	shape.setPosition((posx * 20), (posy * 20));
	shape.setFillColor(sf::Color::Red);
};
