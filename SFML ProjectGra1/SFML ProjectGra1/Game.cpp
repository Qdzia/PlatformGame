#include "Game.h"
using namespace sf;


Game::Game()
{
}

void Game::Run()
{
	RenderWindow window(VideoMode(800, 600), "Tutorials", Style::Default);
	window.setFramerateLimit(60);

	
	RectangleShape player(Vector2f(50.0f, 50.0f));

	

	


	bool ground = true;
	bool jump = false;
	float currentHight;


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
		if (player.getPosition().y >= window.getSize().y - player.getSize().y)
			ground = false;


		if (Keyboard::isKeyPressed(Keyboard::D))
			player.move(4.f, 0.f);

		if (Keyboard::isKeyPressed(Keyboard::A))
			player.move(-4.f, 0.f);


		if (Keyboard::isKeyPressed(Keyboard::Space) && !ground) 
		{
			
			jump = true;
			currentHight = player.getPosition().y;
		}
			
		//Sila grawitacji
		if (ground)
			player.move(0.f, gravityForce);

		//Skok
		if (jump && currentHight-100.0f < player.getPosition().y) {
			
			player.move(0.f, -gravityForce);
		
		}
		else { jump = false; ground = true; }
		

		//Draw

		window.clear(Color::Green);

		//Draw everything
		window.draw(player);
		
		window.display();
	}

}

Game::~Game()
{
}
