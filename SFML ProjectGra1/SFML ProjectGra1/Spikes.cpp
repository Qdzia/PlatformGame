#include "Spikes.h"

using namespace sf;


void Spikes::Effect(Entity* collider, int num)
{
	if (num == 1) 
	{
		collider->gravityForce = false;
		collider->whileJump = false;
		collider->speedValue = 10.f;
		
	}
	

	//narazie tylko siê podœwietla mo¿na dodaæ ze zabija albo hp tracisz czy coœ
}

Spikes::Spikes(float x, float y) :GameObject(x, y)
{
	if (!Tex.loadFromFile("Textures/spikes.png"))
		throw "Could not load cat.png";
	sprite.setTexture(Tex);
	sprite.setScale(Vector2f(0.6f, 0.6f));

	width = sprite.getTexture()->getSize().x * sprite.getScale().x;
	hight = sprite.getTexture()->getSize().y * sprite.getScale().y;
}


Spikes::~Spikes()
{
}
