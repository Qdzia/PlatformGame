#pragma once
#include "Entity.h"

using namespace sf;


class Bullet
{
public:

	CircleShape projectile;
	Vector2f playerCenter;
	Vector2f enemyCenter;
	int ShootTimer = 0;
	int ShootTimerenemy = 0;
	Bullet();
	~Bullet();

};