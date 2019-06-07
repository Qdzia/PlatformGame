#include "Spikes.h"

using namespace sf;


void Spikes::Effect(RectangleShape* collider, int num)
{
	if(Collision(*collider) == 1)
	object.setFillColor(Color::Red);
	else object.setFillColor(Color::White);
	//narazie tylko siê podœwietla mo¿na dodaæ ze zabija albo hp tracisz czy coœ
}

Spikes::Spikes()
{
}


Spikes::~Spikes()
{
}
