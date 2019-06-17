#pragma once
#include "Entity.h"
using namespace sf;
#pragma once

class DeltaTime
{
	friend class Player;
public:
	Clock clock;
	float dt;
	float multiplier = 60.f;
	DeltaTime();
	virtual ~DeltaTime();
    void getDeltaTime();
	float dtxmulti();
};

