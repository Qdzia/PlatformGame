#include "Items.h"



void Items::Effect(Entity* collider, int num)
{
	if (type == 1 && num > 0) collider->hp++;
	else if (type == 2 && num > 0) collider->score += 100;

	if (num > 0) sprite.setPosition(-100.f, -100.f);
}


Items::Items(float x, float y, int t) :GameObject(x, y)
{
	type = t;
	if(type == 1)
	{
		if (!Tex.loadFromFile("Textures/hp.png"))
			throw "Could not load cat.png";
		sprite.setTexture(Tex);
		sprite.setScale(Vector2f(0.05f, 0.05f));
	}
	if (type == 2)
	{
		if (!Tex.loadFromFile("Textures/gem.png"))
			throw "Could not load cat.png";
		sprite.setTexture(Tex);
		sprite.setScale(Vector2f(0.03f, 0.03f));

	}

	width = sprite.getTexture()->getSize().x * sprite.getScale().x;
	hight = sprite.getTexture()->getSize().y * sprite.getScale().y;


}

Items::~Items()
{
}