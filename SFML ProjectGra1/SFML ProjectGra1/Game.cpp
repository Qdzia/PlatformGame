#include "Game.h"
#include "GameObject.h"

using namespace sf;
using namespace std;


// TU jest moje pole do tesów korzystaj z pozosta³ych klas tam masz wszystko ³adnie opisane za playera u¿ywam RectangleShape
Game::Game()
{
}

void Game::Run()
{
	RenderWindow window(VideoMode(800, 600), "Tutorials", Style::Default);
	window.setFramerateLimit(60);

	
	RectangleShape player(Vector2f(50.0f, 50.0f));
	RectangleShape* wskplay = &player;
	player.setPosition(100.f, 200.f);



	bool ground = true;
	bool jump = false;
	float currentHight;

	this->Initialize();

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
		{
			//player.move(4.f, 0.f);
			camX += -4.f;
		}
			

		if (Keyboard::isKeyPressed(Keyboard::A))

		{
			//player.move(-4.f, 0.f);
			camX += 4.f;
		}
			
		

		
		if (Keyboard::isKeyPressed(Keyboard::Space)) 
		{
		
			player.move(0.f,-6.f);
		}
		/*
		//Sila grawitacji
		if (ground && 1 != platform1.Collision(player))
			player.move(0.f, gravityForce);

		//Skok
		if (jump && currentHight-100.0f < player.getPosition().y) {
			
			if(2== platform1.Collision(player)) { jump = false; ground = true; }
			else player.move(0.f, -gravityForce);
		
		}
		else { jump = false; ground = true; }
		*/

		//Sila grawitacji
		if (ground)
			player.move(0.f, gravityForce);

	
		Collisions(wskplay);
		CameraUpdate();
		camX = 0.f;
		camY = 0.f;

		//Draw

		window.clear(Color::Green);

		//Draw everything
		window.draw(player);
		for (int i = 0; i < NumOfObj; i++) window.draw(Objects[i]->Ref());
		
		
		//window.draw(l1.Ref());
		
		window.display();
	}

}

void Game::Initialize()
{
	Objects[0] = new Ladder(410.0f, 100.0f, 10.0f,400.0f);
	Objects[1] = new Platform(0.0f, 500.0f, 500.0f, 50.0f);
	Objects[2] = new Platform(500.0f, 400.0f, 500.0f, 50.0f);
	Objects[3] = new Platform(1300.0f, 200.0f, 500.0f, 50.0f);
	Objects[4] = new Spikes(1000.0f, 500.0f, 500.0f, 30.0f);
}

void Game::CameraUpdate()
{
	for (int i = 0; i < NumOfObj; i++)
	{
		Objects[i]->CameraMove(camX, camY);
	}
}

void Game::Collisions(RectangleShape* player)
{
	int n;
	
	
	for (int i = 0; i < NumOfObj; i++)
	{
		n = Objects[i]->Collision(*player);
		Objects[i]->Effect(player, n);
	}
	
}

Game::~Game()
{

}
