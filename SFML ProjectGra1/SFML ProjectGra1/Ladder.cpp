#include "Ladder.h"



void Ladder::Effect(Entity* collider, int num)
{


	if (num > 0 && Keyboard::isKeyPressed(Keyboard::W))
	{
		void moveSprite(float x, float y);
		
	}
}

Ladder::Ladder(float x, float y) :GameObject(x, y)
{
	if (!Tex.loadFromFile("Textures/ladder.png"))
		throw "Could not load cat.png";
	sprite.setTexture(Tex);
	sprite.setScale(Vector2f(0.2f, 0.2f));

	width = sprite.getTexture()->getSize().x * sprite.getScale().x;
	hight = sprite.getTexture()->getSize().y * sprite.getScale().y;
	
}


Ladder::~Ladder()
{
}
