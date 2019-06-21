#pragma once
#include "Entity.h"
#include "Bullet.h"
#include "Player.h"

using namespace sf;
class Enemy :
	public Entity
{
public:
	Enemy(float x, float y);
	virtual ~Enemy();
	bool shotRand = false;
	//void move(float x, Player & p, Enemy &e);
	
	
	//void shot(Bullet &b1, Player &p, RenderWindow &w, vector<CircleShape> &projectiles, Enemy &e1, vector<CircleShape>& enemyprojectiles);
	void shot(Bullet & b1, Player & p, RenderWindow & w, vector<CircleShape>& projectiles, Enemy &e1, vector<CircleShape>& enemyprojectiles);

	Sprite Ref();
	void CameraMove(float x, float y);
};

