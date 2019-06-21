#include "Entity.h"
#include "DeltaTime.h"



Entity::Entity()
{
	
}

Entity::~Entity()
{
}

void Entity::hpBarMove()
{
	hpBar.setPosition(sprite.getPosition().x + 10, sprite.getPosition().y - 10);
	
	hpBar.setSize(Vector2f(hp * 5.f, 5.f));

}









