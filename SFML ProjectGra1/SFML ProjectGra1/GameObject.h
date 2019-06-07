#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>
#include <iostream>



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
	int Collision(RectangleShape collider);
	int Trigger(RectangleShape collider);
	void Visible(bool n);
	void Movable(bool n);
	void Move(float x,float y);
	bool MoveAlgorithm(float x, float y, float speed);
	RectangleShape Ref();
	void CameraMove(float x,float y);
	virtual void Effect(RectangleShape* collider, int num);

	GameObject();
	virtual ~GameObject();
};

