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

Platform::Platform(float x, float y, float width, float hight):GameObject(x,y,width,hight)
{

}


Platform::~Platform()
{
}



