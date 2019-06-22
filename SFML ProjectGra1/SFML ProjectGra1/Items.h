#pragma once
#include "GameObject.h"
class Items :
	public GameObject
{
public:
	//void PickUp();
	void Effect(Entity* collider, int num);
	Items(float x, float y, float width, float hight);
	~Items();
};
