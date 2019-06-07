#include "Platform.h"



void Platform::Effect(RectangleShape * collider, int num)
{
	if (num == 1) collider->move(0.0f, -3.0f);

	
}

Platform::Platform(float x, float y, float width, float hight):GameObject(x,y,width,hight)
{

}


Platform::~Platform()
{
}



