#include "Ladder.h"



void Ladder::Effect(RectangleShape* collider)
{


	if (Trigger(*collider) == 3 && Keyboard::isKeyPressed(Keyboard::W))
	{
		
		collider->move(0.0f, -4.0f);
	}
}

Ladder::Ladder()
{
	isTrigger = true;
}


Ladder::~Ladder()
{
}
