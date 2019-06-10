#pragma once
#include "Player.h"


using namespace sf;


class Bullet
{
public:
	
	CircleShape projectile;
	Vector2f playerCenter;
	int ShootTimer = 0;
	Bullet();
	~Bullet();
	
};

