#include "Game.h"
#include "GameObject.h"
using namespace sf;

// TU jest moje pole do tesów korzystaj z pozosta³ych klas tam masz wszystko ³adnie opisane za playera u¿ywam RectangleShape
Game::Game()
{
}
bool Collision(RectangleShape player, RectangleShape object)
{
	return !player.getGlobalBounds().intersects(object.getGlobalBounds());

}
void Game::Run()
{
	RenderWindow window(VideoMode(800, 600), "Tutorials", Style::Default);
	window.setFramerateLimit(60);

	
	RectangleShape player(Vector2f(50.0f, 50.0f));

	GameObject platform1;
	platform1.SetProperties(600.0f, 500.0f,400.0f,50.0f);

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


		if (Keyboard::isKeyPressed(Keyboard::D)&& 3!= platform1.Collision(player))
			player.move(4.f, 0.f);

		if (Keyboard::isKeyPressed(Keyboard::A) && 3!= platform1.Collision(player))
			player.move(-4.f, 0.f);


		if (Keyboard::isKeyPressed(Keyboard::Space) && !ground) 
		{
			jump = true;
			currentHight = player.getPosition().y;
		}
			
		//Sila grawitacji
		if (ground && 1 != platform1.Collision(player))
			player.move(0.f, gravityForce);

		//Skok
		if (jump && currentHight-100.0f < player.getPosition().y) {
			
			if(2== platform1.Collision(player)) { jump = false; ground = true; }
			else player.move(0.f, -gravityForce);
		
		}
		else { jump = false; ground = true; }
		

		//Draw

		window.clear(Color::Green);

		//Draw everything
		
		window.draw(platform1.Draw());
		window.draw(player);
		

		window.display();
	}

}

Game::~Game()
{
}
