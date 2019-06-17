#include "Player.h"
class DeltaTime;



Player::Player()
{
}


Player::~Player()
{
}

void Player::move(float x, Player & p, Enemy &e)
{
	//Player
	
	if (Keyboard::isKeyPressed(Keyboard::A))
		player.move(-10.f*x, 0.f);
	else if (Keyboard::isKeyPressed(Keyboard::D))
		player.move(10.f*x, 0.f);
	
}
/////////////////
void Player::jump(float x)
{
	speedValue -= gravityAcceleration * x;
	player.move(0, -speedValue);
}
////////////////////////

void Player::shot(Bullet &b1,Player &p,RenderWindow &w, vector<CircleShape> &projectiles, Enemy &e1, vector<CircleShape>& enemyprojectiles)
{
	b1.playerCenter = Vector2f(p.player.getPosition().x + p.player.getGlobalBounds().width, p.player.getPosition().y + p.player.getGlobalBounds().height/2);


	//PROJECTILES


	if (b1.ShootTimer < 80)
		b1.ShootTimer++;

	if (Mouse::isButtonPressed(Mouse::Left) && b1.ShootTimer >= 80) //Shoot
	{
		b1.projectile.setPosition(b1.playerCenter);
		projectiles.push_back(CircleShape(b1.projectile));

		b1.ShootTimer = 0;
	}

	for (size_t i = 0; i < projectiles.size(); i++)
	{
		projectiles[i].move(1.f, 0.f);

		if (projectiles[i].getPosition().x >= w.getSize().x)
			projectiles.erase(projectiles.begin() + i);

	}
	
	}
	

void Player::setAtributes()
{
	if (!playTex.loadFromFile("Textures/wojownik.png"))
		throw "Could not load cat.png";
	player.setTexture(playTex);
	player.setScale(Vector2f(0.25f, 0.25f));
	player.setPosition(Vector2f(0, 0));
	hpBar.setFillColor(Color::Red);
}

void Player::checkCollison(vector<CircleShape> &projectiles, Enemy &e1, Player &p, vector<CircleShape>& enemyprojectiles)
{
	for (size_t i = 0; i < projectiles.size(); i++)
	{
		if (projectiles[i].getGlobalBounds().intersects(e1.enemy.getGlobalBounds()))
		{
			projectiles.erase(projectiles.begin() + i);
			e1.hp--;
			cout << e1.hp;
			
			break; ///ten break jest po to, ze dla jakiegos tam strzalu ktory by juz zniknal sprawdzala by dalej przeciwnika, wiec trzeba breakowac to
		}

	}
	if (p.player.getGlobalBounds().intersects(e1.enemy.getGlobalBounds()))
	{
		cout << "Zdechles!";
		hp = 0;
	}

	for (size_t i = 0; i < enemyprojectiles.size(); i++)
	{
		if (enemyprojectiles[i].getGlobalBounds().intersects(p.player.getGlobalBounds()))
		{
			enemyprojectiles.erase(enemyprojectiles.begin() + i);
			p.hp--;
			cout << p.hp << endl;
			break; ///ten break jest po to, ze dla jakiegos tam strzalu ktory by juz zniknal sprawdzala by dalej przeciwnika, wiec trzeba breakowac to
		}
	}
}


