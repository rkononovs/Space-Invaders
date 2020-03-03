#include "../Include/Characters.h"

Characters::Characters()
{
	health = 1;
	damage = 1;
}

void Characters::ShootBullet()
{
}

void Characters::TakeDamage() 
{
	health--;
}
