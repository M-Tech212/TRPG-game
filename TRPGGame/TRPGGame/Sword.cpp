#include "Sword.h"

int quality;

Sword::Sword(){}


Sword::Sword(int p, double crit, int b, char* i, int q)
{
	power = p;
	critChance = crit;
	blockPow = b;
	quality = q;
	id = i;
}
