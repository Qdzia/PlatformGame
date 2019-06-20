#include "Platform.h"



void Platform::Effect(Entity* collider, int num)
{
	if (num == 1) 
	{
		collider->gravityForce = false;
		collider->whileJump = false;
		collider->speedValue = 10.f;
				
	}
	else if(num == 2) collider->speedValue = -1.f;
	else if (num == 3) collider->camD = false;
	else if (num == 4) collider->camA = false;
	
}

Platform::Platform(float x, float y):GameObject(x,y)
{
	if (!Tex.loadFromFile("Textures/ground.png"))
		throw "Could not load cat.png";
	sprite.setTexture(Tex);
	sprite.setScale(Vector2f(0.6f, 0.6f));

	width = sprite.getTexture()->getSize().x * sprite.getScale().x;
	hight = sprite.getTexture()->getSize().y * sprite.getScale().y;

}


Platform::~Platform()
{
}



