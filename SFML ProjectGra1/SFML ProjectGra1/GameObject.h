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
	bool isTrigger = false;
	RectangleShape object;

public:
	void SetProperties(float x, float y, float width, float hight);
	Vector2f GetPosition();
	int Collision(Sprite collider, float gravity, float width, float hight);
	void Visible(bool n);
	void Movable(bool n);
	void Move(float x,float y);
	bool MoveAlgorithm(float x, float y, float speed);
	RectangleShape Ref();
	void CameraMove(float x,float y);
	virtual void Effect(Entity* collider, int num);

	GameObject(float x, float y, float width, float hight);
	virtual ~GameObject();
};

