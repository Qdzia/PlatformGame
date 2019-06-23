#include "Enemy.h"



Enemy::Enemy(float x, float y)
{
	if (!Tex.loadFromFile("Textures/enemy.png"))
		throw "Could not load cat.png";
	sprite.setTexture(Tex);
	sprite.setScale(Vector2f(0.05f, 0.05f));
	sprite.setPosition(Vector2f(x, y));
	hpBar.setFillColor(Color::Red);
	hp = 3;

	hpBar.setPosition(x + 10, y - 10);
	hpBar.setSize(Vector2f(hp * 5.f, 5.f));

	width = sprite.getTexture()->getSize().x * sprite.getScale().x;
	hight = sprite.getTexture()->getSize().y * sprite.getScale().y;

	enemyCenter = Vector2f(sprite.getPosition().x + width / 2, sprite.getPosition().y + hight / 2);
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

Sprite Enemy::Ref()
{
	return sprite;
}

void Enemy::CameraMove(float x, float y)
{
	x += sprite.getPosition().x;
	y += sprite.getPosition().y;
	sprite.setPosition(x, y);

}

void Enemy::shot(Bullet & b1, Player & p, RenderWindow & w, vector<CircleShape>& projectiles, Enemy &e1, vector<CircleShape>& enemyprojectiles)
{
	
	if (hp < 1)
	{
		sprite.setPosition(sprite.getPosition().x, -300.f);
	}

	if (alive) 
	{
		b1.ShootTimerenemy++;

		enemyCenter = Vector2f(sprite.getPosition().x + width / 2, sprite.getPosition().y + hight / 2);

		if (b1.ShootTimerenemy >= 160)
		{
			b1.projectile.setPosition(enemyCenter);
			enemyprojectiles.push_back(CircleShape(b1.projectile));

			if (enemyCenter.x < p.sprite.getPosition().x) enemyprojectiles[numOfShots].move(5.f, 0.f);
			else enemyprojectiles[numOfShots].move(-5.f, 0.f);

			b1.ShootTimerenemy = 0;
			numOfShots++;
		}

		for (size_t i = 0; i < enemyprojectiles.size(); i++)
		{

			if (enemyprojectiles[i].getPosition().x > enemyCenter.x) enemyprojectiles[i].move(2.f, 0.f);
			else enemyprojectiles[i].move(-2.f, 0.f);


			if (enemyprojectiles[i].getPosition().x >= sprite.getPosition().x + 1000 || enemyprojectiles[i].getPosition().x <= sprite.getPosition().x - 1000)
			{
				enemyprojectiles.erase(enemyprojectiles.begin() + i);
				numOfShots--;
			}

		}

	}
}

