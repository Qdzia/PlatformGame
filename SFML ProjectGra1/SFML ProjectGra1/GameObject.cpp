#include "GameObject.h"

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
	//colizja z boku lub od do³u -- 2, colizja od góry -- 1, brak collizji 0, ta 4.0f to wartoœæ grawitacji

	bool n = collider.getGlobalBounds().intersects(object.getGlobalBounds());
	if (n&& collider.getPosition().y + collider.getSize().y -object.getPosition().y<4.0f) return 1;
	else if (n) return 2;
	else return 0;
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



