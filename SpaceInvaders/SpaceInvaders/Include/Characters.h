// Base class for all characters ( Player, Enemies, etc.)
#pragma once

class Characters
{
private:
	int health;
	int damage;
public:
	Characters();
	void ShootBullet();
	void TakeDamage();
};
