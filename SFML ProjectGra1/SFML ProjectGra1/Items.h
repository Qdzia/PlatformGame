#pragma once
#include "GameObject.h"
class Items :
	public GameObject
{
public:
	//void PickUp();
	void Effect(RectangleShape* collider, int num);
	Items();
	~Items();
};

