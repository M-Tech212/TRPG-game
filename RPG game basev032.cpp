//Created by: Jack Melvin
//RPG game
//v0.32

//Rules of the program
//Variables are lowercase.
//Functios start with upper case per word

//Known Bugs
//menu quit gets stuck in loop you enter a char.
//Hp doesnt raise after you talk with the inn keeper

//To-Do
//Finish Atk formula
//equip items
//working backpack
//map borders
//working enemies
//working shop

#include <iostream>
#include <iomanip>
#include <cmath>
#include <ctime> 
#include <string>
#include <limits>
#include <stdexcept>
#include <windows.h>
#include <stdio.h>
using namespace std;

//---------------[Global Variables]-----------------------

//Player stats
string name;
int lvl = 1;
int Php = 1;
int PhpT = 20;
int PhpP = Php * 100 / PhpT;
int Patk = 1;
int Parm = 0;
int turns;
int gold = 0;

//Players Position
int Px;
int Py;

//enemy structure
struct enemy
{
	string name;
	int hp;
	int atk;
	int arm;
};


//GameVariables
int mainmenu = 0;
int leavegame = 0;
int activate = 0;
string continuecode;

//Items
int map = 0;
int backpack = 0;

//-------------------[Window size]---------

struct console
{
	console(unsigned width, unsigned height)
	{
		SMALL_RECT r;
		COORD      c;
		hConOut = GetStdHandle(STD_OUTPUT_HANDLE);
		if (!GetConsoleScreenBufferInfo(hConOut, &csbi))
			throw runtime_error("You must be attached to a human.");

		r.Left =
			r.Top = 0;
		r.Right = width - 1;
		r.Bottom = height - 1;
		SetConsoleWindowInfo(hConOut, TRUE, &r);

		c.X = width;
		c.Y = height;
		SetConsoleScreenBufferSize(hConOut, c);
	}

	~console()
	{
		SetConsoleTextAttribute(hConOut, csbi.wAttributes);
		SetConsoleScreenBufferSize(hConOut, csbi.dwSize);
		SetConsoleWindowInfo(hConOut, TRUE, &csbi.srWindow);
	}

	void color(WORD color = 0x07)
	{
		SetConsoleTextAttribute(hConOut, color);
	}

	HANDLE                     hConOut;
	CONSOLE_SCREEN_BUFFER_INFO csbi;
};
console con(55, 30);

//--------------[Established Functions]-------------------

void Opener();
void MainMenu();
void Play();
void Howtoplay();
void HitEnter();
void HUD();
void World();
void Map();
void Input();
void Enemies();
void Attack();
void Backpack();
void GameOver();
void Credits();
void IKO();

//--------------------[Main]-------------------------------

int main()
{

	Opener();

	while (mainmenu != 1)
	{
		MainMenu();
	}
	return 0;
}

//-------------------[Functions]-------------------------

//Opening Screen
void Opener()
{
	cout << "\n\n\n\n\n";
	cout << "\n xXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXx";
	cout << "\n xXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXx";

	cout << "\n   ____      ____       _______                _      ";
	cout << "\n  |    \\    /    |     |__   __|___     ____  | |     ";
	cout << "\n  |     \\  /     |  ___   | |  / _ \\   /  __| | |__   ";
	cout << "\n  |  |\\  \\/  /|  | |___|  | | / |_| \\ /  /    |  _ \\  ";
	cout << "\n  |  | \\    / |  |        | | \\  ___/ \\  \\__  | / \\ \\ ";
	cout << "\n  |__|  \\__/  |__|        |_|  \\___/   \\____| |_| |_| ";
	cout << "\n\n\t\t\tStudios";
	cout << "\n\n\t\tHit [Enter] to continue\n";
	cout << "\n xXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXx";
	cout << "\n xXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXx";
	cout << "\n\n\n\n\n\n\n\n\n";

	HitEnter();

	system("cls");
}

//Main menu
void MainMenu()
{
	int mainmenuchoice;
	char input;

	system("cls");

	cout << "\n\n\n\n\n";
	cout << "\n\t\t|===================|";
	cout << "\n\t\t|       RPG Game    |";
	cout << "\n\t\t|===================|";
	cout << "\n\t\t| 1 -   New Game    |";
	cout << "\n\t\t| 2 - Continue Game |";
	cout << "\n\t\t| 3 -  How to play  |";
	cout << "\n\t\t| 4 -    Credits    |";
	cout << "\n\t\t| 5 -     Quit      |";
	cout << "\n\t\t|===================|";
	cout << "\n\t\t    Choose one: ";
	cin >> mainmenuchoice;

	switch (mainmenuchoice)
	{
	case 1:
		Play();
		break;

	case 2:
		//Code();
		map = 1;
		Play();
		break;

	case 3:
		Howtoplay();
		MainMenu();
		break;

	case 4:
		Credits();
		MainMenu();
		break;


	case 5:
		system("cls");
		cout << "\n\n     Are you sure you want to quit? <Y/N> ";
		cin >> input;
		if (input == 'Y' || input == 'y')
			mainmenu = 1;
		else if (input == 'N' || input == 'n')
			MainMenu();
		else
		{
			cout << "\n\tPlease make a valid selection.\n\n\t";
			system("pause");
			MainMenu();
		}
		break;

	default:
		system("cls");
		cout << "\n\tPlease make a valid selection.\n\n\t";
		MainMenu();
		break;
	}
}

//Play
void Play()
{
	while (leavegame != 1)
	{
		Input();
	}
	GameOver();
}

//How to Play
void Howtoplay()
{
	system("cls");
	cout << "\n\n=======================================================";
	cout << "\n\t\t    N    ";
	cout << "\n\t\t    |    ";
	cout << "\n\t\t W--X--E ";
	cout << "\n\t\t    |    ";
	cout << "\n\t\t    S  \n";
	cout << "\n\t Hit N, E, S, or W to move in that directon";

	cout << "\n\t Hit A to Interact with you surroundings.";
	cout << "\n\t Hit B to open your backpack.";
	cout << "\n\t Hit M to open your map.";
	cout << "\n\t Hit Q to quit.\n\n";
	system("pause");
}

//Displays HUD
void HUD()
{
	cout << "|Name:" << setw(10) << left << name << "|Level:" << setw(2) << lvl;
	cout << "|Life:" << setw(3) << right << PhpP << "%|ATK:+" << setw(2) << left << Patk;
	cout << "|Armour:+" << setw(2) << Parm << "|";
	cout << "|===============|========|=========|=======|==========|";
}

//Enemies
void Enemies()
{
	enemy boar;
	boar.hp = 5;
	boar.atk = 5;
	boar.arm = 10;
}

//World
void World()
{
	int randomenemy;

	srand((unsigned)time(0));
	randomenemy = (rand() % 50);

	cout << "\n Location: " << Px << " ," << Py;

	//dirt road 1
	if (Px == 0 && Py == 1)
	{
		cout << "\n\n\tYou are surrounded by trees.";
		cout << "\n\n\tA dirt road runs east to west.";
		cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n";
	}
	//dirt road 1
	else if (Px == -1 && Py == 1)
	{
		cout << "\n\n\tYou are surrounded by trees.";
		cout << "\n\n\tA dirt road runs east to west.";
		cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n";
	}
	//dirt road 1 w/INN
	else if (Px == 1 && Py == 1)
	{
		if (activate == 1)
		{
			IKO();
			activate = 0;
		}
		else
		{
			cout << "\n\n\tYou enter a clearing.";
			cout << "\n\n\tA dirt road runs east to west with an";
			cout << "\n\n\tInn on the north side of the road.";
			cout << "\n\n\n\n\n\n\n\n\n\n\n";
		}
	}
	//Forest with chance of random enemy
	else
	{
		if (randomenemy != 1)
		{
			cout << "\n\n\tYou are surrounded by trees.";
			cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n";
		}
		else
		{
			cout << "\n\n\tYou are surrounded by trees.";
			cout << "\n\n\tA wild boar appears!";
			cout << "\n\n\n\n\n\n\n\n\n\n\n\n";
		}
	}
}

//Player Controls.
void Input()
{
	char input;

	system("cls");

	if (Php = 0)
		leavegame = 1;

	HUD();

	World();

	cout << "\n\n=======================================================";
	cout << "\n A  N   B\t\t\t\t Turn: " << turns;
	cout << "\n    |    ";
	cout << "\n W--X--E \t\t\t\t Gold: " << gold;
	cout << "\n    |    ";
	cout << "\n M  S   Q\tWhat do you want to do? ";
	cin >> input;

	//Moving
	if (input == 'N' || input == 'n')
	{
		Py = Py + 1;
		turns++;
		Input();
	}
	else if (input == 'E' || input == 'e')
	{
		Px = Px + 1;
		turns++;
		Input();
	}
	else if (input == 'S' || input == 's')
	{
		Py = Py - 1;
		turns++;
		Input();
	}
	else if (input == 'W' || input == 'w')
	{
		Px = Px - 1;
		turns++;
		Input();
	}

	//Activate
	else if (input == 'A' || input == 'a')
	{
		activate = 1;
		turns++;
		Input();
	}

	//Check Map
	else if (input == 'M' || input == 'm')
	{
		if (map == 1)
		{
			Map();
			Input();
		}
		else
		{
			cout << "\n\n\tYou dont have a map.\n\n";
			system("pause");
			Input();
		}
	}

	//Open Backpack
	else if (input == 'B' || input == 'b')
	{
		Backpack();

		Input();
	}

	//Quit game
	else if (input == 'Q' || input == 'q')
	{
		cout << "\n\n     Are you sure you want to quit? <Y/N> ";
		cin >> input;
		if (input == 'Y' || input == 'y')
			leavegame = 1;
		else if (input == 'N' || input == 'n')
			Input();
		else
		{
			cout << "\n\n\tPlease make a valid selection.\n\n ";
			system("pause");
			Input();
		}
	}

	else
	{
		cout << "\n\n\tPlease make a valid selection\n\n ";
		system("pause");
		Input();
	}

}

//attack sequence
void Attack()
{
	Enemies();
	//input enemy dat
	cout << Php;

	//Ehp-Patk/Earm

}

//Map
void Map()
{
	system("cls");
	system("Color 21");
	cout << "|=====================================================|";
	cout << "|#####################################################|";
	cout << "|#####################################################|";
	cout << "|####################            #####################|";
	cout << "|################                       ##############|";
	cout << "|##############                   #          #########|";
	cout << "|#############                   ###          ########|";
	cout << "|#############                #######         ########|";
	cout << "|############                 #####            #######|";
	cout << "|############                                #########|";
	cout << "|##############CC                           ##########|";
	cout << "|#############CCC\\                         ###########|";
	cout << "|############     \\                     ##############|";
	cout << "|#########         \\                    ##############|";
	cout << "|######             \\-------I-----\\     ##############|";
	cout << "|#####                     X        \\-H###############|";
	cout << "|####                                    #############|";
	cout << "|####                                    #############|";
	cout << "|####                                     ############|";
	cout << "|###                                         #########|";
	cout << "|##                                             ######|";
	cout << "|###                                             #####|";
	cout << "|####                                            #####|";
	cout << "|############                                   ######|";
	cout << "|###################                           #######|";
	cout << "|##############################               ########|";
	cout << "|###################################       ###########|";
	cout << "|#####################################################|";
	cout << "|=====================================================|";
	system("pause");
	system("color 07");
}

//Displays Items in backpack
void Backpack()
{
	system("cls");

	if (backpack == 1)
	{
		cout << " Small backpack || 10 slots\n";
		cout << "=======================================================";
	}
	else if (backpack == 2)
	{
		cout << " Medium Backpack || 20 slots\n";
		cout << "=======================================================";
	}
	else if (backpack == 3)
	{
		cout << " Large Backpack || 40 slots\n";
		cout << "=======================================================";
	}
	else
	{
		cout << "you dont have a backpack";
	}
	system("pause");
}

//Game over display
void GameOver()
{
	system("cls");


	cout << "\n\t        __                   __";
	cout << "\n\t       /  \\    /\\    |\\  /| | ";
	cout << "\n\t      /  __   /__\\   | \\/ | |_";
	cout << "\n\t      \\    / /    \\  |    | |";
	cout << "\n\t       \\__/ /      \\ |    | |__";
	cout << "\n\t         __            __   _";
	cout << "\n\t        /  \\ \\      / |    | \\";
	cout << "\n\t       /    \\ \\    /  |_   |_/";
	cout << "\n\t       \\    /  \\  /   |    |\\";
	cout << "\n\t        \\__/    \\/    |__  | \\";

	cout << "\n\n|===============|========|=========|=======|==========|";
	HUD();

	cout << "\n\n\t\tTotal Turns: " << turns;
	cout << "\n\n\t";
	system("pause");
	leavegame = 1;
}

//hit enter to continue
void HitEnter()
{
	int enter;
	fflush(stdout);
	do enter = getchar(); while ((enter != '\n') && (enter != EOF));
}

//credits
void Credits()
{
	system("cls");
	cout << "\n\n\n\n\tMade in C++.";
	cout << "\n\tProgramed by: Jack Melvin.\n\n\t Hit [Enter] to continue\n\n\t";
	HitEnter();
}

//Innkeeper
void IKO()
{
	system("cls");

	HUD();
	cout << "\n *you step into a seemingly empty Inn.*";

	cout << "\n\n";
	cout << "\t|=================|\n";
	cout << "\t|Gus the Innkeeper|\n";
	cout << "\t|=================|\n\n";

	cout << "\tso Traveler,";
	cout << "\n\tWhat be your name?";
	cout << "\n\n\t Name: ";
	cin >> name;

	system("cls");
	//------------------------------------------------------------
	HUD();

	cout << "\n\n\n";
	cout << "\t|=================|\n";
	cout << "\t|Gus the Innkeeper|\n";
	cout << "\t|=================|\n\n";

	cout << "\tYou look weary from travel,\n";
	cout << "\tWhy dont you take a rest.";
	cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n -";

	Php = PhpT; //Not working. not sure if i shoud be referencing Php.

	system("pause");
	system("cls");
	//------------------------------------------------------------
	HUD();

	cout << "\n\n\n";
	cout << "\t|=================|\n";
	cout << "\t|Gus the Innkeeper|\n";
	cout << "\t|=================|\n\n";

	cout << "\tSo you say your on an adveture eh?\n";
	cout << "\tSounds like your gonna need some\n";
	cout << "\tprotection. Here, take this! \n\n";
	cout << "\t(You obtained a Rusty Sword +1 ATK)\n";
	Patk++;
	cout << "\t(You obtained a leather armour +1 Armour)\n\n";
	Parm++;
	cout << "\tSome bum traded it for a pint of beer,\n";
	cout << "\tand I have no use for it, so keep it.\n\n\n\n\n\n\n\n\n -";


	system("pause");
	system("cls");
	//------------------------------------------------------------

}


/*
cout << "\n\n\n\t Welcome to your"; //DOOM
cout << "\n ____			  __      __";
cout << "\n|    \\     ___     ___   |  \\    /  |";
cout << "\n|  |\\ \\   / _ \\   / _ \\	 |   \\  /   |";
cout << "\n|  | \\ \\ / / \\ \\ / / \\ \\ | |\\ \\/ /| |";
cout << "\n|  |_/ / \\ \\_/ / \\ \\_/ / | | \\__/ | |";
cout << "\n|_____/   \\___/   \\___/  |_|      |_|";

cout << "\n1234567891123456789212345678932345678941234567895123456";//L=56
*/
/*
if (Px >= 0 && Py >= 0)
{
if (Px >= 0 && Px <= 10 && Py >= 0 && Py <= 10)
{

}
else if (Px >= 11 && Px <= 20 && Py >= 0 && Py <= 10)
{

}
else if (Px >= 21 && Px <= 30 && Py >= 0 && Py <= 10)
{

}
else if (Px >= 31 && Px <= 40 && Py >= 0 && Py <= 10)
{

}
else if (Px >= 41 && Px <= 50 && Py >= 0 && Py <= 10)
{

}
else if (Px >= 0 && Px <= 10 && Py >= 11 && Py <= 20)
{

}
else if (Px >= 11 && Px <= 20 && Py >= 11 && Py <= 20)
{

}
else if (Px >= 21 && Px <= 30 && Py >= 11 && Py <= 20)
{

}
else if (Px >= 31 && Px <= 40 && Py >= 11 && Py <= 20)
{

}
else if (Px >= 41 && Px <= 50 && Py >= 11 && Py <= 20)
{

}
else if (Px >= 0 && Px <= 10 && Py >= 21 && Py <= 30)
{

}
else if (Px >= 11 && Px <= 20 && Py >= 21 && Py <= 30)
{

}
else if (Px >= 21 && Px <= 30 && Py >= 21 && Py <= 30)
{

}
else if (Px >= 31 && Px <= 40 && Py >= 21 && Py <= 30)
{

}
else if (Px >= 41 && Px <= 50 && Py >= 21 && Py <= 30)
{

}
else if (Px >= 0 && Px <= 10 && Py >= 31 && Py <= 40)
{

}
else if (Px >= 11 && Px <= 20 && Py >= 31 && Py <= 40)
{

}
else if (Px >= 21 && Px <= 30 && Py >= 31 && Py <= 40)
{

}
else if (Px >= 31 && Px <= 40 && Py >= 31 && Py <= 40)
{

}
else if (Px >= 41 && Px <= 50 && Py >= 31 && Py <= 40)
{

}
else if (Px >= 0 && Px <= 10 && Py >= 41 && Py <= 50)
{

}
else if (Px >= 11 && Px <= 20 && Py >= 41 && Py <= 50)
{
8888888888888
}
else if (Px >= 21 && Px <= 30 && Py >= 41 && Py <= 50)
{

}
else if (Px >= 31 && Px <= 40 && Py >= 41 && Py <= 50)
{

}
else if (Px >= 41 && Px <= 50 && Py >= 41 && Py <= 50)
{

}
}
else if (Px >= 0 && Py <= -1)
{
if (Px >= 0 && Px <= 10 && Py <= -1 && Py >= -10)
{

}
}
else if (Px <= -1 && Py >= 1)
{
if (Px <= -1 && Px >= -10 && Py >= 1 && Py <= 10)
{

}
}
else if (Px <= -1 && Py <= -1)
{
if (Px <= -1 && Px >= -10 && Py <= -1 && Py >= -10)
{

}
}
*/