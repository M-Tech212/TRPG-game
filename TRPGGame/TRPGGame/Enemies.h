#pragma once

class Enemies
{
	char atk,def,health;

	public:
		Enemies();
		Enemies(int a, int d, int h);
		bool attack(int attackPow);
		void setAtk(int a); 
		void setDef(int d);
		void setHealth(int h);
		int getHealth();
		int getAtk();
};

