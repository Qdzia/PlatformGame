#pragma once
#include "GameObject.h"



class Spikes :
	public GameObject
{

public:
	
	void Effect(RectangleShape* collider, int num);
	Spikes();
	~Spikes();
};

