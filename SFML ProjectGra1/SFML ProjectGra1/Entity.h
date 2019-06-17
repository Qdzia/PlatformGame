#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>
#include <iostream>




using namespace sf;
using namespace std;

class Entity
{
public:
	friend class Bullet;
	friend class Player;
	friend class Enemy;
	int hp=10;
	Entity();
	virtual ~Entity();
	//virtual void move(float x, Player & p, Enemy &e)=0;
	virtual void move() = 0;
	virtual void jump(float x)=0;
	virtual void shot()=0;
	//virtual void shot(Bullet &b1, Player &p, RenderWindow &w, vector<CircleShape> &projectiles, Enemy &e1, vector<CircleShape>& enemyprojectiles) = 0;
	virtual void setAtributes() = 0;
	//virtual void checkCollison(vector<CircleShape> &projectiles, Enemy &e1)=0;
	
};

