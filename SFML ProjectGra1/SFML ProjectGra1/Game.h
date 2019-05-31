#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>

using namespace sf;
#pragma once
class Game
{
	float gravityForce = 3.0f;

public:
	void Run();

	Game();
	virtual ~Game();
};

