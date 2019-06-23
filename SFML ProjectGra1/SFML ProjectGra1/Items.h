#pragma once
#include "GameObject.h"
class Items :
	public GameObject
{
public:
	int type = 0;//1- hp potion 2 - gem
	void Effect(Entity* collider, int num);

	Items(float x, float y, int t);
	~Items();
};
