#pragma once

#include "SFML/Graphics.hpp"
#include "Apple.h"
#include "Snake.h"
#include <iostream>
#include <list>


class Game
{
public:
	Game(unsigned int &screenWidth, unsigned int &screenHeight, const char* &title);
	~Game();
	bool running;
	bool Update(float deltaTime); 
	void Draw(sf::RenderWindow& window);
	Apple* appleptr;
	Snake* snakeptr;
	int applesEaten;
	std::vector<Snake*> snakeBody;
	void collision(Apple* $apple, Snake* &snake);
	float elapsedTime;
	std::vector<sf::Rect<float>> colliders;
private:

};
