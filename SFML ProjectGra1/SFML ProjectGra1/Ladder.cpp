#include "Ladder.h"



void Ladder::Effect(RectangleShape* collider, int num)
{


	if (Trigger(*collider) == 3 && Keyboard::isKeyPressed(Keyboard::W))
	{
		
		collider->move(0.0f, -4.0f);
	}
}

Ladder::Ladder(float x, float y, float width, float hight) :GameObject(x, y, width, hight)
{
	isTrigger = true;
}


Ladder::~Ladder()
{
}
