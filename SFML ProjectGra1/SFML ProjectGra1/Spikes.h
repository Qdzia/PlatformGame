#pragma once
#include "GameObject.h"



class Spikes :
	public GameObject
{

public:
	
	void Effect(Entity* collider, int num);
	Spikes(float x, float y, float width, float hight);
	~Spikes();
};

