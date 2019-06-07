#pragma once
#include "GameObject.h"
class Platform :
	public GameObject
{
public:

	void Effect(RectangleShape * collider, int num);
	Platform(float x, float y, float width, float hight);
	~Platform();
};



