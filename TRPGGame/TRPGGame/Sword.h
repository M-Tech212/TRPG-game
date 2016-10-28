#pragma once
#include "Weapon.h"


class Sword : public Weapon
{	
	char* id;
	int quality;

	public:
	Sword();
	Sword(int p,double crit,int b,char* i,int q);
};

