#include<stdio.h>
#include<iostream>
#include"Enemies.h"

using namespace std;

int main()
{
	Enemies e,d;

	e.setAtk(5);
	e.setDef(100);
	e.setHealth(1);

	d.setAtk(10);
	d.setDef(20);
	d.setHealth(50);

	bool survive=d.attack(e.getAtk());

	printf("The health of e is: %d\n", e.getHealth());
	printf("The health of d is: %d\n", d.getHealth());

	if (survive)
	{
		printf("Enemy d survived! with %d health left\n", d.getHealth());
	}
	else
	{
		printf("Enemy d died.\n");
	}

	system("pause");
}
