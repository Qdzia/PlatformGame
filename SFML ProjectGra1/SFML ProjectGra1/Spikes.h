#pragma once
#include "GameObject.h"



class Spikes :
	public GameObject
{

public:
	
	void Effect(RectangleShape* collider);
	Spikes();
	~Spikes();
};

