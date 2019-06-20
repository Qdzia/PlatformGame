#include "GameObject.h"
using namespace sf;

GameObject::GameObject(float x, float y)
{
	sprite.setPosition(Vector2f(x, y));
}

GameObject::~GameObject()
{
}

Sprite GameObject::Ref()
{
	//przekazuje referencje do obiektu
	return sprite;
}

void GameObject::CameraMove(float x, float y)
{
	x += sprite.getPosition().x;
	y += sprite.getPosition().y;
	sprite.setPosition(x, y);
	
	
}

void GameObject::Effect(Entity* collider, int num)
{

}

int GameObject::Collision(Sprite collider, float gravity, float width,float hight)
{

		bool n = collider.getGlobalBounds().intersects(sprite.getGlobalBounds());
		bool vUp = collider.getPosition().y < sprite.getPosition().y;
		bool vDown = collider.getPosition().y + gravity > sprite.getPosition().y + this->hight;
		bool hLeft = collider.getPosition().x + width - gravity < sprite.getPosition().x;
		bool hRight = collider.getPosition().x + gravity > sprite.getPosition().x + this->width;

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
	sprite.move(x, y);
}

bool GameObject::MoveAlgorithm(float x, float y,float speed)
{
	bool m = sprite.getPosition().x == x;
	bool n = sprite.getPosition().y == y;
	if (!m) sprite.move(0.0f, -speed);
	if (!n) sprite.move(speed, 0.0f);
	if (m&&n) return true;
	else return false;
}



