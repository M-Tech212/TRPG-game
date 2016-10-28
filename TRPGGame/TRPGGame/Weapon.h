#pragma once
#include "Character.h"

//Classes I think that you should implement as well:
//	1. Backpack -- It would hold all of the backpack items. It would be
//	where you have a data structure to hold all of the items that your
//	character has.
//	2. Item -- Basically an item is something that can be picked up by
//	the character. It does not necessarily have to be something that
//	the character can hold. You can make other subclasses for items
//	that are significant enought to have a specific class; 
//	i.e. a Weapons class.
//	3. Other types of weapons than the sword that I am going to make.
//	I will let you know how I did what I did and why I did it.

class Weapon
{	
	protected:
		int power;
		double critChance;
		int blockPow;
		char* id;
	public:
		Weapon();
		Weapon(int a, int d, double crit,char* i);
		int attack(Character c);
		bool block(Weapon w);
		char* toString();
		int getAttackPow();
		double getCritChance();
		int getDef();
		void setPower(int p);
		void setBlockPow(int b);
		void setCritChance(double c);
};

