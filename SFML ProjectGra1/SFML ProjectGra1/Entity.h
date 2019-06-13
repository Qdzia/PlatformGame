#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>
#include <iostream>
#include "DeltaTime.h"


using namespace sf;
using namespace std;

class Entity
{
public:
	friend class Bullet;
	friend class Player;
	int hp;
	Entity();
	virtual ~Entity();
	virtual void move(float x)=0;
	virtual void jump(float x)=0;
	virtual void shot(Bullet &b1, Player &p, RenderWindow &w, vector<CircleShape> &projectiles)=0;
	virtual void setAtributes() = 0;
	
};

