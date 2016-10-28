#pragma once
//Other header files to include


class Character
{
	public:
		Character();

	private:
		char* name;
		char* id;
		int health;
		int defense;
		int attackPow;
		Backpack backpack;
		Hand right;
		Hand left;
};