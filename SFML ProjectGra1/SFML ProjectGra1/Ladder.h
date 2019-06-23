#pragma once
#include "GameObject.h"
using namespace sf;

class Ladder :
	public GameObject
{
public:
	void Effect(Entity* collider, int num);
	Ladder(float x, float y);
	~Ladder();
};
