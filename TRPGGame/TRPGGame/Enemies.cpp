#include "Enemies.h"
#include<string>

int atk,def,health;

Enemies::Enemies(int a,int d,int h)
{
	atk = a;
	def = d;
	health = h;
}

Enemies::Enemies()
{}

void Enemies::setAtk(int a)
{
	atk = a;
}

void Enemies::setDef(int d)
{
	def = d;
}

void Enemies::setHealth(int h)
{
	health = h;
}

int Enemies::getHealth()
{
	return health;
}

int Enemies::getAtk()
{
	return atk;
}

/**
 * This function determines if the enemy kills or harms the player
 */
bool Enemies::attack(int attackPow)
{
	if (attackPow > (def+health))
	{
		return false;
	}
	else
	{
		int loss= (attackPow - def);

		if(loss>=0)
		{
			health - loss;
		}

		return true;
	}
}
