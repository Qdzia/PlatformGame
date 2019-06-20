#include "Enemy.h"



Enemy::Enemy()
{
}


Enemy::~Enemy()
{
}

//void Enemy::move(float x, Player & p,Enemy &e)
//{
//		if(e.enemy.getPosition().x > p.player.getPosition().x)
//		{
//			e.enemy.move(-0.5f, 0.f);
//		}
//		if (e.enemy.getPosition().x < p.player.getPosition().x)
//		{
//			e.enemy.move(0.5f, 0.f);
//		}
//}

void Enemy::move()
{
}

void Enemy::jump(float x)
{
}

void Enemy::shot()
{
}

//void Enemy::shot(Bullet & b1, Player & p, RenderWindow & w, vector<CircleShape>& projectiles,Enemy &e1, vector<CircleShape>& enemyprojectiles)
//{
//
//	if (b1.ShootTimerenemy < 400)
//		b1.ShootTimerenemy++;
//
//	b1.enemyCenter = Vector2f(e1.enemy.getPosition().x + e1.enemy.getGlobalBounds().width/2, e1.enemy.getPosition().y + e1.enemy.getGlobalBounds().height / 2);
//
//	if (b1.ShootTimerenemy >= 400)
//	{
//		b1.projectile.setPosition(b1.enemyCenter);
//		enemyprojectiles.push_back(CircleShape(b1.projectile));
//
//		b1.ShootTimerenemy = 0;
//	}
//	
//	for (size_t i = 0; i < enemyprojectiles.size(); i++)
//	{
//		if (shotRand == false)
//			enemyprojectiles[i].move(2.f, 0.f);
//		if (shotRand == true)
//			enemyprojectiles[i].move(-2.f, 0.f);
//			
//
//		if (enemyprojectiles[i].getPosition().x >= e1.enemy.getPosition().x+300+e1.enemy.getGlobalBounds().width || enemyprojectiles[i].getPosition().x <= e1.enemy.getPosition().x - 300)
//		{
//			enemyprojectiles.erase(enemyprojectiles.begin() + i);
//			shotRand = !shotRand;
//		}
//		
//	}
//
//}

void Enemy::setAtributes()
{
	if (!Tex.loadFromFile("Textures/enemy.png"))
		throw "Could not load cat.png";
	sprite.setTexture(Tex);
	sprite.setScale(Vector2f(0.05f, 0.05f));
	sprite.setPosition(Vector2f(500, 500));
	hpBar.setFillColor(Color::Red);
	
}


