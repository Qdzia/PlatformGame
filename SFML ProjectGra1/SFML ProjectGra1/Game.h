#include "Spikes.h"
#include "Ladder.h"
#include "Items.h"
#include "Platform.h"
#include "Entity.h"
#include "Player.h"
#include "Bullet.h"
#include "Enemy.h"

using namespace sf;
#pragma once
class Game
{
	float gravityForce = 3.0f;
	int NumOfObj = 5;
	int NumOfEnemy = 1;
	float camX =0.0f, camY=0.0f;

public:
	GameObject* Objects[5];
	Enemy* Enemys[1];
	
	void Run();
	void Initialize();
	void CameraUpdate(Player* collider);
	void Collisions(Player* collider);

	Game();
	virtual ~Game();
};

