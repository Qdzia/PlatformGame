#include "GameObject.h"
#include <iostream>
using namespace sf;

GameObject::GameObject()
{
}

GameObject::~GameObject()
{
}


RectangleShape GameObject::Draw()
{
	//przekazuje referencje do obiektu
	return object;
}

void GameObject::CameraMove(float x, float y)
{
	x += object.getPosition().x;
	y += object.getPosition().y;
	object.setPosition(x, y);
	
	
}

void GameObject::SetProperties(float x, float y,float width,float hight)
{
	// Tak tworzysz ka¿dy objekt

	object.setSize(Vector2f(width, hight));
	object.setPosition(Vector2f(x, y));
	
}

Vector2f GameObject::GetPosition()
{
	return object.getPosition();
}

int GameObject::Collision(RectangleShape collider)
{
	//colizja od do³u -- 2, colizja od góry -- 1, jakakolwiek colizja -- 3, brak collizji 0, ta 4 to wartoœæ grawitacji
	if (!isTrigger)
	{
		bool n = collider.getGlobalBounds().intersects(object.getGlobalBounds());

		if (n && collider.getPosition().y + 4 > object.getPosition().y + object.getSize().y)return 2;
		else if (n && collider.getPosition().y + collider.getSize().y - object.getPosition().y < 4) return 1;
		else if (n) return 3;
		else return 0;
	} 
	
	return 0;
}

int GameObject::Trigger(RectangleShape collider)
{
	int m;
	isTrigger = false;
	m = Collision(collider);
	isTrigger = true;

	return m;
}

void GameObject::Visible(bool n)
{
	//s³ó¿y do tworzenia niewidzialnych obiektów 

	if (n) object.setFillColor(Color::White);
		else object.setFillColor(Color::Transparent);
}

void GameObject::Movable(bool n)
{
	// okreœla czy mo¿na przesuwaæ obiekt czy jest statyczny
	isMovable = n;
}

void GameObject::Move(float x, float y)
{
	if(isMovable)
	object.move(x, y);
}

bool GameObject::MoveAlgorithm(float x, float y,float speed)
{
	bool m = object.getPosition().x == x;
	bool n = object.getPosition().y == y;
	if (!m) object.move(0.0f, -speed);
	if (!n) object.move(speed, 0.0f);
	if (m&&n) return true;
	else return false;
}



