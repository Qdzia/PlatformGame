#pragma once
#include "Entity.h"
#include "Bullet.h"
#include "Enemy.h"
#include "DeltaTime.h"

using namespace sf;

class Player :
	public Entity
{
	friend class DeltaTime;
	friend class Enemy;
public:
	Texture Tex;
	Sprite sprite;
	RectangleShape hpBar;
	//a=f/m
	
	///////////////////////////
	
	
	//////////////////////////////////////
	Player(float x, float y);
	virtual ~Player();
	void move();
	//void move(float x, Player & p, Enemy &e);
	void shot();
	//void shot(Bullet &b1, Player &p, RenderWindow &w, vector<CircleShape> &projectiles, Enemy &e1, vector<CircleShape>& enemyprojectiles);
	void checkCollison(vector<CircleShape> &projectiles, Enemy &e1, Player &p, vector<CircleShape> &enemyprojectiles);
	void ifJump(DeltaTime &y);
};

