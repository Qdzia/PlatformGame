#include "Spikes.h"
#include "Ladder.h"
#include "Items.h"
#include "Platform.h"
#include "ShortPlatform.h"
#include "Entity.h"
#include "Player.h"
#include "Bullet.h"
#include "Enemy.h"
#include "Menu.h"

using namespace sf;
#pragma once
class Game
{
	float gravityForce = 3.0f;
	int NumOfObj = 23;
	int NumOfEnemy = 1;
	float camX = 0.0f, camY = 0.0f;

	vector<CircleShape> projectiles;
	vector<CircleShape> enemyprojectiles;



public:
	GameObject* Objects[23];
	Enemy* Enemys[1];

	void Run();
	void Initialize();
	void CameraUpdate(Player* collider);
	void Collisions(Player* collider);
	void Draw(RenderWindow & w, Player & p1);

	Game();
	virtual ~Game();
};