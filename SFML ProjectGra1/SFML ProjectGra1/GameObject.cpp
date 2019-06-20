#include "GameObject.h"
using namespace sf;

GameObject::GameObject(float x, float y, float width, float hight)
{
	object.setSize(Vector2f(width, hight));
	object.setPosition(Vector2f(x, y));

}

GameObject::~GameObject()
{
}


RectangleShape GameObject::Ref()
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

void GameObject::Effect(Entity* collider, int num)
{

}

int GameObject::Collision(Sprite collider, float gravity, float width,float hight)
{
	//colizja od do³u -- 2, colizja od góry -- 1, jakakolwiek colizja -- 3, brak collizji 0, ta 4 to wartoœæ grawitacji
	
	
		bool n = collider.getGlobalBounds().intersects(object.getGlobalBounds());
		bool vUp = collider.getPosition().y < object.getPosition().y;
		bool vDown = collider.getPosition().y + gravity > object.getPosition().y + object.getSize().y;
		bool hLeft = collider.getPosition().x + width - gravity < object.getPosition().x;
		bool hRight = collider.getPosition().x + gravity > object.getPosition().x + object.getSize().x;

		if (hLeft && n) return 3;
		if (hRight && n) return 4;
		if (vUp && n) return 1;
		if (vDown && n) return 2;
		
		if (n) return 5;

		return 0;
		
		/*float width = collider.getTexture()->getSize().x * collider.getScale().x;
		float hight = collider.getTexture()->getSize().y * collider.getScale().y;

		if (n && collider.getPosition().y + gravity > object.getPosition().y + object.getSize().y)return 2;
		else if (n && collider.getPosition().y + hight - object.getPosition().y < gravity) return 1;
		else if (n) return 3;
		else return 0;*/

		//if (n && collider.getPosition().y + hight - object.getPosition().y < gravity) return 1;

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



