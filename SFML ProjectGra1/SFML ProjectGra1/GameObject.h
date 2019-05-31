#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>
#include <iostream>

#pragma once
using namespace sf;

class GameObject
{

	bool isStatic = true;
	bool isMovable = false;
	RectangleShape object;

public:
	void SetProperties(float x, float y, float width, float hight);
	Vector2f GetPosition();
	int Collision(RectangleShape collider);
	void Visible(bool n);
	void Movable(bool n);
	void Move(float x,float y);
	void MoveAlgorithm();
	void Effect();
	RectangleShape Draw();

	GameObject();
	virtual ~GameObject();
};

