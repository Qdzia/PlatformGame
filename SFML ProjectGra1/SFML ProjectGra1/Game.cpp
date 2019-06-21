#include "Game.h"
#include "GameObject.h"

using namespace sf;
using namespace std;

Game::Game()
{
	
}

void Game::Run()
{
	RenderWindow window(VideoMode(800, 600), "Tutorials", Style::Default);
	window.setFramerateLimit(60);

	Player p1(250.f,50.f);
	
	
	Bullet b1;

	

	this->Initialize();

	while (window.isOpen())
	{
		Event event;

		Collisions(&p1);
		for (int i = 0; i < NumOfEnemy; i++) p1.checkCollison(projectiles, *Enemys[0], p1, enemyprojectiles);

		while (window.pollEvent(event))
		{
			if (event.type == Event::Closed) window.close();

			if (Event::KeyPressed && event.key.code == Keyboard::Escape) window.close();

			if (event.type == Event::KeyPressed && event.key.code == Keyboard::Space && p1.gravityForce == false)
			{
				p1.whileJump = true;
				p1.gravityForce = true;
			}

		}


		CameraUpdate(&p1);

		p1.shot(b1, p1, window, projectiles, *Enemys[0], enemyprojectiles);
		p1.ifJump();

		//Background
		window.clear(Color::Green);


		for (size_t i = 0; i < projectiles.size(); i++)
		{
			window.draw(projectiles[i]);
		}
		for (size_t i = 0; i < enemyprojectiles.size(); i++)
		{
			window.draw(enemyprojectiles[i]);
		}
	
		//Draw everything

		for (int i = 0; i < NumOfObj; i++) window.draw(Objects[i]->Ref());
		for (int i = 0; i < NumOfEnemy; i++) window.draw(Enemys[i]->Ref());

		window.draw(p1.sprite);
		window.display();
	}

}

void Game::Initialize()
{
	Objects[0] = new Ladder(1500.0f, 100.0f);
	Objects[1] = new Platform(0.0f, 200.0f);
	Objects[2] = new Platform(500.0f, 400.0f);
	Objects[3] = new Platform(1100.0f, 300.0f);
	Objects[4] = new Spikes(1000.0f, 500.0f);

	Enemys[0] = new Enemy(550.f, 330.f);
}

void Game::CameraUpdate(Player* p1)
{
	if (Keyboard::isKeyPressed(Keyboard::D) && p1->camD) { camX += -4.f; }
	if (Keyboard::isKeyPressed(Keyboard::A) && p1->camA) { camX += 4.f; }
	
	for (int i = 0; i < NumOfObj; i++) { Objects[i]->CameraMove(camX, camY); }
	for (int i = 0; i < NumOfEnemy; i++) { Enemys[i]->CameraMove(camX, camY); }
	
	for (size_t i = 0; i < projectiles.size(); i++) projectiles[i].move(camX, camY);
	
		
	


	camX = 0.f;
	camY = 0.f;
	p1->camD = true;
	p1->camA = true;
}

void Game::Collisions(Player* collider)
{
	int n;
	
	for (int i = 0; i < NumOfObj; i++)
	{
		n = Objects[i]->Collision(collider->sprite, collider->speedValue, collider->width,collider->hight);
		Objects[i]->Effect(collider, n);
	}

}

Game::~Game()
{

}
//#pragma once
//#include <SFML/Graphics.hpp>
//#include <SFML/Window.hpp>
//#include <SFML/System.hpp>
//#include <iostream>
//#include "Entity.h"
//#include "Player.h"
//#include "Bullet.h"
//#include "Enemy.h"
//
//
//using namespace sf;
//
//
//bool whileJump = false;
//
//
//void ifJump(Player &x, DeltaTime &y);
//
//
//
//int main()
//{
//	RenderWindow window(VideoMode(800, 600), "Example 03!", Style::Default);
//	window.setFramerateLimit(200);
//	DeltaTime d1;
//	Player p1;
//	Bullet b1;
//	Enemy e1;
//	vector<CircleShape> projectiles;
//	vector<CircleShape> enemyprojectiles;
//	p1.setAtributes();
//	e1.setAtributes();

//	while (window.isOpen())
//	{
//		d1.getDeltaTime();
//		Event event;
//		while (window.pollEvent(event))
//		{
//			if (event.type == Event::Closed)
//				window.close();
//			///////////////////////////////////////////////Warunek na skok/////////////////////////////
//			if (event.type == Event::KeyPressed && event.key.code == Keyboard::Space && whileJump == false)
//			{
//				p1.speedValue = p1.jumpF / p1.mass;
//				whileJump = true;
//			}
//		}
//
//		//Update
//		ifJump(p1, d1);
//		p1.move(d1.dtxmulti(), p1, e1);
//		e1.move(d1.dtxmulti(), p1, e1);
//		p1.shot(b1, p1, window, projectiles, e1, enemyprojectiles);
//		e1.shot(b1, p1, window, projectiles, e1, enemyprojectiles);
//		p1.checkCollison(projectiles, e1, p1, enemyprojectiles);
//		e1.hpBar.setPosition(e1.enemy.getPosition().x + 10, e1.enemy.getPosition().y - 10);
//		e1.hpBar.setSize(Vector2f(e1.hp * 5.f, 5.f));
//		//////////////////////
//		p1.hpBar.setPosition(p1.player.getPosition().x + 10, p1.player.getPosition().y - 10);
//		p1.hpBar.setSize(Vector2f(p1.hp * 5.f, 5.f));
//		//Draw
//		window.clear();
//		window.draw(p1.player);
//		window.draw(e1.enemy);
//		window.draw(e1.hpBar);
//		window.draw(p1.hpBar);
//
//		//window.draw(e1.enemy);
//		for (size_t i = 0; i < projectiles.size(); i++)
//		{
//			window.draw(projectiles[i]);
//		}
//		for (size_t i = 0; i < enemyprojectiles.size(); i++)
//		{
//			window.draw(enemyprojectiles[i]);
//		}
//
//		window.display();
//	}
//
//	return 0;
//}
//void ifJump(Player &x, DeltaTime &y)
//{
//	if (whileJump)
//	{
//		x.jump(y.dtxmulti());
//		if (x.player.getPosition().y > 500)
//		{
//			x.player.setPosition(x.player.getPosition().x, 500);
//			whileJump = false;
//			x.accelerationValue = 0;
//		}
//	}
//
//
//}