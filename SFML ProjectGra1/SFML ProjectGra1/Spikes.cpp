#include "Spikes.h"

using namespace sf;


void Spikes::Effect(RectangleShape* collider, int num)
{
	if(Collision(*collider) == 1)
	object.setFillColor(Color::Red);
	else object.setFillColor(Color::White);
	//narazie tylko si� pod�wietla mo�na doda� ze zabija albo hp tracisz czy co�
}

Spikes::Spikes()
{
}


Spikes::~Spikes()
{
}
