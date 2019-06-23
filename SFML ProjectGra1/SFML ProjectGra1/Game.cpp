#include "Game.h"
#include "GameObject.h"

using namespace sf;
using namespace std;

Game::Game()
{

}

void Game::Run()
{
	RenderWindow window(VideoMode(1920, 1080), "GamebyLukaszandPawel", Style::Default);
	window.setFramerateLimit(60);

	Player p1(250.f, 50.f);
	Bullet b1;
	Event event;
	Menu menu(float(window.getSize().x), float(window.getSize().y));
	bool isMenu = true;
	bool isGame = false;
	int licznik = 0;
	
	

	Initialize();

	while (window.isOpen())
	{
		//Kolizje
		Collisions(&p1);
		for (int i = 0; i < NumOfEnemy; i++) p1.checkCollison(projectiles, *Enemys[0], p1, enemyprojectiles);

		//HPBars
		p1.hpBar.setSize(Vector2f(p1.hp * 5.f, 5.f));

		//Event
		while (window.pollEvent(event))
		{
			if (event.type == Event::Closed) window.close();

			if (isMenu == true)
			{
				switch (event.type)
				{
				case Event::KeyReleased:
					switch (event.key.code)
					{
					case Keyboard::Up:
						menu.MoveUp();
						break;
					case Keyboard::Down:
						menu.MoveDown();
						break;
					case Keyboard::Enter:
						switch (menu.GetPressedItem())
						{
						case 0:
							cout << "Play buttom";
							isMenu = false;
							break;
						case 1:
							cout << "Option buttom";
							break;
						case 2:
							window.close();
							break;
						}

					}
				}
			}



			if (Event::KeyPressed && event.key.code == Keyboard::Escape) window.close();

			if (event.type == Event::KeyPressed && event.key.code == Keyboard::Space && p1.gravityForce == false)
			{
				p1.whileJump = true;
				p1.gravityForce = true;
			}

		}

		if (isMenu == false && !isGame)
		{
			//Kamera + Os x
			CameraUpdate(&p1);

			//Strzelanie
			p1.shot(b1, p1, window, projectiles, *Enemys[0], enemyprojectiles);
			for (int i = 0; i < NumOfEnemy; i++) Enemys[i]->shot(b1, p1, window, projectiles, *Enemys[0], enemyprojectiles);

			//Skok
			p1.ifJump();
		}

		std::cout << p1.sprite.getPosition().x<<"     "<< p1.sprite.getPosition().y << endl;
		
		if (isGame) licznik++;
		if (licznik >= 200)
		{
			window.close();
			Game game;
			game.Run();
		}
			
		
		//Items(150.f, 750.f, 1)

		//Background
		window.clear(Color::Green);
		//Draw everything
		cout << p1.sprite.getPosition().x << endl;
		cout << p1.sprite.getPosition().y << endl;
		if (p1.hp <= 0)
		{
			menu.drawInfo(window);
			isGame = true;
			
		}
		if (p1.score == 700)
		{
			cout << "Wygrana";
			menu.drawWin(window);
			isGame = true;

		}
		if (isMenu == false) 
		{ 
			Draw(window, p1); 
			menu.drawScore(window,p1.score);
		}
		if (isMenu == true) menu.draw(window);

		window.display();
	}

}

void Game::Initialize()
{
	Objects[0] = new Platform(0.0f, 800.f);
	Objects[1] = new Spikes(490.f, 950.f);
	Objects[2] = new ShortPlatform(570, 680.f);
	Objects[3] = new ShortPlatform(780, 680.f);
	Objects[4] = new Spikes(1200.f, 950.f);
	Objects[5] = new Platform(990.0f, 600.f);// to ustawimy na 990,680, narazie dalem wyzej zeby dalo sie wskakiwac, potem po drabinie bedziemy tu wchodzic
	Objects[6] = new Ladder(1376.f, 450.f); 
	Objects[7] = new ShortPlatform(1445.0f, 460.f);
	Objects[8] = new ShortPlatform(1600.0f, 400.f);
	Objects[9] = new ShortPlatform(1750.0f, 350.f);
	Objects[10] = new Platform(1900.0f, 300.f);
	Objects[11] = new Platform(2390.0f, 800.f);
	Objects[12] = new Ladder(2776.f, 475.f);
	Objects[13] = new Ladder(2776.f, 575.f);
	Objects[14] = new Platform(2840.0f, 490.f);
	Objects[15] = new ShortPlatform(3350.0f, 390.f);
	Objects[16] = new ShortPlatform(3500.0f, 330.f);
	Objects[17] = new ShortPlatform(3650.0f, 260.f);
	Objects[18] = new ShortPlatform(3800.0f, 200.f);
	Objects[19] = new ShortPlatform(3950.0f, 140.f);
	Objects[20] = new Spikes(3300.f, 950.f);
	Objects[21] = new Spikes(4400.f, 950.f);
	Objects[22] = new Platform(4100.0f, 140.f);

	Enemys[0] = new Enemy(1950.f, 230.f);

	itemsVec[0] = new Items(30.f, 750.f, 2);
	itemsVec[1] = new Items(1200.f, 550.f, 2);
	itemsVec[2] = new Items(2500.f, 750.f, 1);
	itemsVec[3] = new Items(3200.f, 430.f, 2);
	itemsVec[4] = new Items(4200.f, 85.f, 2);

	
}

void Game::CameraUpdate(Player* p1)
{
	if (Keyboard::isKeyPressed(Keyboard::D) && p1->camD) { camX += -4.f; }
	if (Keyboard::isKeyPressed(Keyboard::A) && p1->camA) { camX += 4.f; }

	for (int i = 0; i < NumOfObj; i++) { Objects[i]->CameraMove(camX, camY); }
	for (int i = 0; i < NumOfEnemy; i++) { Enemys[i]->CameraMove(camX, camY); }

	for (size_t i = 0; i < projectiles.size(); i++) projectiles[i].move(camX, camY);
	for (size_t i = 0; i < enemyprojectiles.size(); i++) enemyprojectiles[i].move(camX, camY);

	for (int i = 0; i < NumOfItems; i++) itemsVec[i]->CameraMove(camX, camY);
		
	p1->hpBar.setPosition(p1->sprite.getPosition().x, p1->sprite.getPosition().y - 10);

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
		n = Objects[i]->Collision(collider->sprite, collider->speedValue, collider->width, collider->hight);
		Objects[i]->Effect(collider, n);
	}

	for (int i = 0; i < NumOfItems; i++) 
	{
		n = itemsVec[i]->Collision(collider->sprite, collider->speedValue, collider->width, collider->hight);
		itemsVec[i]->Effect(collider, n);
	}

}

void Game::Draw(RenderWindow & window, Player & p1)
{
	
	
	for (int i = 0; i < NumOfEnemy; i++) Enemys[i]->hpBarMove();

	for (size_t i = 0; i < projectiles.size(); i++) window.draw(projectiles[i]);
	for (size_t i = 0; i < enemyprojectiles.size(); i++) window.draw(enemyprojectiles[i]);

	for (int i = 0; i < NumOfObj; i++) window.draw(Objects[i]->Ref());
	for (int i = 0; i < NumOfEnemy; i++) window.draw(Enemys[i]->Ref());

	for (int i = 0; i < NumOfItems; i++) window.draw(itemsVec[i]->Ref());

	window.draw(p1.sprite);
	window.draw(p1.hpBar);

	for (int i = 0; i < NumOfEnemy; i++) window.draw(Enemys[i]->hpBar);
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