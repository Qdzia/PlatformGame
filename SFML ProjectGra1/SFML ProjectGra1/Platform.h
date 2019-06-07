#pragma once
#include "GameObject.h"
class Platform :
	public GameObject
{
public:

	void Effect(RectangleShape* collider);
	Platform();
	~Platform();
};

