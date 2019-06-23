#pragma once
#include "GameObject.h"
class ShortPlatform :
	public GameObject
{
public:
	void Effect(Entity* collider, int num);
	ShortPlatform(float x, float y);
	~ShortPlatform();
};

