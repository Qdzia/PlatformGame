#pragma once
#include "GameObject.h"



class Spikes :
	public GameObject
{

public:
	
	void Effect(RectangleShape* collider, int num);
	Spikes(float x, float y, float width, float hight);
	~Spikes();
};

