#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>
#include <iostream>
#include "Entity.h"
#include "Player.h"
#include "Bullet.h"
#include "Enemy.h"


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
	Enemy e1;
	vector<CircleShape> projectiles;
	vector<CircleShape> enemyprojectiles;
	p1.setAtributes();
	e1.setAtributes();
	
	
	
	

	
	
	

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
		p1.move(d1.dtxmulti(),p1,e1);
		e1.move(d1.dtxmulti(), p1, e1);
		p1.shot(b1, p1, window, projectiles,e1,enemyprojectiles);
		e1.shot(b1, p1, window, projectiles, e1,enemyprojectiles);
		p1.checkCollison(projectiles, e1, p1,enemyprojectiles);
		e1.hpBar.setPosition(e1.enemy.getPosition().x+10, e1.enemy.getPosition().y-10);
		e1.hpBar.setSize(Vector2f(e1.hp * 5.f, 5.f));
		//////////////////////
		p1.hpBar.setPosition(p1.player.getPosition().x + 10, p1.player.getPosition().y - 10);
		p1.hpBar.setSize(Vector2f(p1.hp * 5.f, 5.f));
		//Draw
		window.clear();
		window.draw(p1.player);
		window.draw(e1.enemy);
		window.draw(e1.hpBar);
		window.draw(p1.hpBar);
		
		//window.draw(e1.enemy);
		for (size_t i = 0; i < projectiles.size(); i++)
		{
			window.draw(projectiles[i]);
		}
		for (size_t i = 0; i < enemyprojectiles.size(); i++)
		{
			window.draw(enemyprojectiles[i]);
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
		if (x.player.getPosition().y>500)
		{
			x.player.setPosition(x.player.getPosition().x, 500);
			whileJump = false;
			x.accelerationValue = 0;
		}
	}


}