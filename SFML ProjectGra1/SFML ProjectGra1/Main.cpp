#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>
#include <iostream>
#include "Entity.h"
#include "Player.h"
#include "Bullet.h"


using namespace sf;
bool whileJump = false;


void ifJump(Player &x, DeltaTime &y);



int main()
{
	RenderWindow window(VideoMode(800, 600), "Example 03!", Style::Default);
	window.setFramerateLimit(200);
	DeltaTime d1;
	Player p1;
	Bullet b1;
	vector<CircleShape> projectiles;
	
	p1.setAtributes();
	

	while (window.isOpen())
	{
		d1.getDeltaTime();
		Event event;
		while (window.pollEvent(event))
		{
			if (event.type == Event::Closed)
				window.close();
///////////////////////////////////////////////Warunek na skok/////////////////////////////
			if (event.type == Event::KeyPressed && event.key.code == Keyboard::Space && whileJump == false)
			{
				p1.speedValue = p1.jumpF / p1.mass;
				whileJump = true;
			}
		}
		
		//Update
		ifJump(p1,d1);
		p1.move(d1.dtxmulti());
		p1.shot(b1, p1, window, projectiles);
		//Draw
		window.clear();
		window.draw(p1.player);
		for (size_t i = 0; i < projectiles.size(); i++)
		{
			window.draw(projectiles[i]);
		}
		window.display();
	}

	return 0;
}
void ifJump(Player &x,DeltaTime &y)
{
	if (whileJump) 
	{
		x.jump(y.dtxmulti());
		if (x.player.getPosition().y>400)
		{
			x.player.setPosition(x.player.getPosition().x, 400);
			whileJump = false;
			x.accelerationValue = 0;
		}
	}


}