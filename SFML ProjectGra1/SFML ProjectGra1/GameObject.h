#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>
#include <iostream>
#include "Entity.h"


#pragma once
using namespace sf;

class GameObject
{
protected:

	bool isMovable = true;
	RectangleShape object;

public:

	GameObject(float x, float y, float width, float hight);
	virtual ~GameObject();


	int Collision(Sprite collider, float gravity, float width, float hight);
	void Move(float x,float y);
	RectangleShape Ref();
	void CameraMove(float x, float y);
	virtual void Effect(Entity* collider, int num);

	bool MoveAlgorithm(float x, float y, float speed);
		
};

