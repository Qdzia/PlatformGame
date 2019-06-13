#pragma once
#include "Entity.h"
#include "Bullet.h"
#include "Game.h"
#include "GameObject.h"

using namespace sf;

class Player :
	public Entity
{
	friend class DeltaTime;
	friend void ifJump(Player &x, DeltaTime &y);
public:
	int hp;
	Texture playTex;
	Sprite player;
	//a=f/m
	float jumpF = 400;
	float gravityAcceleration = 0.3;
	float mass = 60;
	float speedValue = 0;
	float accelerationValue = 0;

	Player();
	virtual ~Player();
	void move(float x);
	void jump(float x);
	void shot(Bullet &b1, Player &p, RenderWindow &w, vector<CircleShape> &projectiles);
	void setAtributes();
};