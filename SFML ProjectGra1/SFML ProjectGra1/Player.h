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
	friend void ifJump(Player &x, DeltaTime &y);
	friend class Enemy;
public:
	Texture playTex;
	Sprite player;
	RectangleShape hpBar;
	//a=f/m
	///////////////////////////
	float jumpF=400;
	float gravityAcceleration=0.3;
	float mass = 60;
	float speedValue=0;
	float accelerationValue = 0;
	//////////////////////////////////////
	Player();
	virtual ~Player();
	void move();
	//void move(float x, Player & p, Enemy &e);
	void jump(float x);
	void shot();
	//void shot(Bullet &b1, Player &p, RenderWindow &w, vector<CircleShape> &projectiles, Enemy &e1, vector<CircleShape>& enemyprojectiles);
	void setAtributes();
	void checkCollison(vector<CircleShape> &projectiles, Enemy &e1, Player &p, vector<CircleShape> &enemyprojectiles);
	void ifJump(DeltaTime &y, bool & whilejump);
};

