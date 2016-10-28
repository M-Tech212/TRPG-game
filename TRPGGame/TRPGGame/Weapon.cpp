#include "Weapon.h"
#include "Character.h"


int power;
double critChance;
int blockPow;
char* id;

Weapon::Weapon(){}

Weapon::Weapon(int a, int d, double crit,char* i)
{
	power = a;
	blockPow = d;
	critChance = crit;
	id = i;
}

int Weapon::attack(Character c)
{
	//Using attack equation
	return 0;
}

bool Weapon::block(Weapon w)
{
	if (w.getAttackPow() > blockPow)
	{
		return false;
	}
	else
	{
		return true;
	}
}

void Weapon::setPower(int p)
{
	power = p;
}

void Weapon::setCritChance(double c)
{
	critChance = c;
}

void Weapon::setBlockPow(int b)
{
	blockPow = b;
}

int Weapon::getAttackPow()
{
	return power;
}

double Weapon::getCritChance()
{
	return critChance;
}

int Weapon::getDef()
{
	return blockPow;
}

char* Weapon::toString()
{
	//I really dont know if you can do this, and I am too lazy to check right now
	char* out = "Generic weapon. Attack: %d, DefPower: %d, CritChance: %lf", power, blockPow, critChance;
	
	return out;
}