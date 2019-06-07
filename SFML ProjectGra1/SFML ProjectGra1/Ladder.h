#pragma once
#include "GameObject.h"
using namespace sf;

class Ladder :
	public GameObject
{
public:
	void Effect(RectangleShape* collider, int num);
	Ladder();
	~Ladder();
};

