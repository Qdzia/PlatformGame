#include "Ladder.h"



void Ladder::Effect(Entity* collider, int num)
{


	if (num == 3 && Keyboard::isKeyPressed(Keyboard::W))
	{
		collider->sprite.move(0.0f, -5.0f);
	}
}

Ladder::Ladder(float x, float y, float width, float hight) :GameObject(x, y, width, hight)
{
	
}


Ladder::~Ladder()
{
}
