#include "Game.h"
using namespace sf;


Game::Game()
{
}

void Game::Run()
{
	RenderWindow window(VideoMode(800, 600), "Tutorials", Style::Default);
	window.setFramerateLimit(60);

	CircleShape shape(50.0f);
	RectangleShape player(Vector2f(50.0f, 50.0f));

	while (window.isOpen())
	{
		Event event;
		while (window.pollEvent(event))
		{
			if (event.type == Event::Closed)
				window.close();

			if (Event::KeyPressed && event.key.code == Keyboard::Escape)
				window.close();
		}
		//Update
		shape.move(0.1f, 0.5f);
		player.setFillColor(Color::Black);

		if (Keyboard::isKeyPressed(Keyboard::D))
			player.move(4.f, 0.f);

		if (Keyboard::isKeyPressed(Keyboard::A))
			player.move(-4.f, 0.f);

		if (Keyboard::isKeyPressed(Keyboard::S))
			player.move(0.f, 4.f);

		if (Keyboard::isKeyPressed(Keyboard::W))
			player.move(0.f, -4.f);

		//Draw

		window.clear(Color::Green);

		//Draw everything
		window.draw(player);
		window.draw(shape);
		window.display();
	}

}

Game::~Game()
{
}
