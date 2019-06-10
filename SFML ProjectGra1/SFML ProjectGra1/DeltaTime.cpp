#include "DeltaTime.h"


DeltaTime::DeltaTime()
{
}


DeltaTime::~DeltaTime()
{
}

void DeltaTime::getDeltaTime()
{
	dt = clock.restart().asSeconds();
	
}

float DeltaTime::dtxmulti()
{
	return dt*multiplier;
}
