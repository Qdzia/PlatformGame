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
	if (b1.ShootTimerenemy < 200)
		b1.ShootTimerenemy++;

	b1.enemyCenter = Vector2f(e1.sprite.getPosition().x + e1.sprite.getGlobalBounds().width/2, e1.sprite.getPosition().y + e1.sprite.getGlobalBounds().height/2);

	if (b1.ShootTimerenemy >= 200)
	{
		b1.projectile.setPosition(b1.enemyCenter);
		enemyprojectiles.push_back(CircleShape(b1.projectile));

		b1.ShootTimerenemy = 0;
	}

	for (size_t i = 0; i < enemyprojectiles.size(); i++)
	{
		if (shotRand == false) enemyprojectiles[i].move(2.f, 0.f);
		if (shotRand == true) enemyprojectiles[i].move(-2.f, 0.f);


		if (enemyprojectiles[i].getPosition().x >= e1.sprite.getPosition().x + 300 + e1.width || enemyprojectiles[i].getPosition().x <= e1.sprite.getPosition().x - 300)
		{
			enemyprojectiles.erase(enemyprojectiles.begin() + i);
			shotRand = !shotRand;
		}

	}

}

