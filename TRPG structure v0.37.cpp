//Created by: Jack Melvin
//RPG game
//v0.37

//Rules of the program
//Variables are lowercase.
//Functios start with upper case per word

//Known Bugs
//none :)

//To-Do
//items
//map borders
//working enemies
//working shop

// V0.37
// * Added Backpacks
// * Fixed minor bugs
// V0.36
// * Added Input Logic Function
// * Advanced Combat System
// V0.35 updates
// * Added attack formula and combat test system
// V0.34 updates
// * if to switch for Input function.
// * Valid to invalid function.
// * Moved world and HUD from input into play loop around play
// * DOOOOOOOOM!


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
double Php;
int PhpT;
int Patk = 1;
int Pdef = 0;
int turns = 1;
int gold = 0;
string Armour[1] = { "Nothing  " };

//Inventory arrays
string Hands[2] = { "Nothing  " , "Nothing  " };
string BP15[15];
string BP30[30];
string bp60[60];
//Items
int map = 0;
int backpack = 0;

//Players Position
int Px;
int Py;

//enemy
int Eatk;
double Ehp = 0;
int Edef = 50;

//GameVariables
int mainmenu = 0;
int leavegame = 0;
int activate = 0;
int doom = 0;
string continuecode;
int Pchoice, Echoice;

//----------------------[Classes]--------------

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
void Credits();
void GameOver();

//world functions
void World();
void EWDR();
void NWSEDR();
void LH();
void IKO();
void Doom();

//game
void HUD();
void Input();
void InputLogic(char);
void CombatTraining();
void Attack(int, int, double&, int, int, int, double&, int);
double HitType(int);
void Inventory();
void Map();
void Key();

//system
void Invalid();
void HitEnter();

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
	cout << "\n\t\t||===================||";
	cout << "\n\t\t||       RPG Game    ||";
	cout << "\n\t\t||===================||";
	cout << "\n\t\t|| 1 -   New Game    ||";
	cout << "\n\t\t|| 2 - Continue Game ||";
	cout << "\n\t\t|| 3 -Combat Training||";
	cout << "\n\t\t|| 4 -  How to play  ||";
	cout << "\n\t\t|| 5 -    Credits    ||";
	cout << "\n\t\t|| 6 -     Quit      ||";
	cout << "\n\t\t||===================||";
	cout << "\n\t\t    Choose one: ";
	cin >> mainmenuchoice;

	switch (mainmenuchoice)
	{
	case 1:
		Php = 1;
		PhpT = 20;
		Play();
		break;

	case 2:
		map = 1;
		Php = 100;
		PhpT = 100;
		cout << "\n\n\tName: ";
		cin >> name;
		Play();
		break;

	case 3:
		CombatTraining();
		MainMenu();
		break;

	case 4:
		Howtoplay();
		MainMenu();
		break;

	case 5:
		Credits();
		MainMenu();
		break;

	case 6:
		system("cls");
		cout << "\n\n     Are you sure you want to quit? <Y/N> ";
		cin >> input;
		if (input == 'Y' || input == 'y')
			mainmenu = 1;
		else if (input == 'N' || input == 'n')
			MainMenu();
		else
		{
			Invalid();
			MainMenu();
		}
		break;

	default:
		Invalid();
		cin.clear();
		cin.ignore(80, '\n');
		MainMenu();
		break;
	}
}

//Play
void Play()
{
	while (leavegame != 1)
	{
		system("cls");

		if (Php == 0)
			leavegame = 1;

		HUD();
		World();
		Input();
	}
	GameOver();
	leavegame = 0;
}

//How to Play
void Howtoplay()
{
	system("cls");
	cout << "\n\t| |           -|-    __  |   ";
	cout << "\n\t|-| /\\ \\    /  | /\\  | \\ | /\\ \\  /";
	cout << "\n\t| | \\/  \\/\\/   | \\/  |_/ | \\/\\ \\/";
	cout << "\n                             |         /";
	cout << "\n=======================================================";
	cout << "\n\t\t    N    ";
	cout << "\n\t\t    |    ";
	cout << "\n\t\t W--+--E ";
	cout << "\n\t\t    |    ";
	cout << "\n\t\t    S  \n";
	cout << "\n\t Hit N, E, S, or W to move in that directon";

	cout << "\n\t Hit A to Interact with you surroundings.";
	cout << "\n\t Hit I to open your Inventory.";
	cout << "\n\t Hit M to open your map.";
	cout << "\n\t Hit Q to quit.\n\n\t-";
	system("pause");
}

//Displays HUD
void HUD()
{
	double PhpP = Php * 100 / PhpT;
	cout << setprecision(0) << fixed;

	cout << "|Name:" << setw(10) << left << name << "|Level:" << setw(2) << lvl;
	cout << "|Life:" << setw(3) << right << PhpP << "%|ATK:+" << setw(2) << left << Patk;
	cout << "|Armour:+" << setw(2) << Pdef << "|";
	cout << "|===============|========|=========|=======|==========|";
}

//World
void World()
{
	int randomenemy;
	int doom;
	string x;

	srand((unsigned)time(0));
	randomenemy = (rand() % 30);
	doom = (rand() % 10);

	cout << "\n Location: " << Px << " ," << Py;

	//dirt road
	if (Px <= 0 && Px >= -6 && Py == 1 || Px <= 7 && Px >= 2 && Py == 1 || Px == 10 && Py == 0)
		EWDR();
	else if (Px == 8 && Py == 1 || Px == 9 && Py == 0 || Px == -7 && Py == 1 || Px == -8 && Py == 2 || Px == -9 && Py == 3 || Px == -10 && Py == 4)
		NWSEDR();
	//dirt road 1 w/INN
	else if (Px == 1 && Py == 1)
	{
		if (activate == 1)
		{
			activate = 0;
			IKO();
		}
		else
		{
			cout << "\n\n\tYou enter a clearing.";
			cout << "\n\n\tA dirt road runs east to west with an";
			cout << "\n\n\tInn on the north side of the road.";
			cout << "\n\n\n\n\n\n\n\n\n\n\n";
		}
	}

	else if (Px == 2 && Py == 2)
	{
		Php = 0;
		cout << "\n\n\tYou are surrounded by trees.";
		cout << "\n\n\tHp to zero";
		cout << "\n\n\n\n\n\n\n\n\n\n\n\n";
	}

	//Lake Hiliya
	else if (Px >= 3 && Px <= 7 && Py == 7 || Px >= 3 && Px <= 9 && Py == 8 || Px >= 6 && Px <= 8 && Py == 10 || Px == 7 && Py == 11)
		LH();

	//Forest with chance of random enemy
	else
	{
		//Boar
		if (randomenemy == 1)
		{
			cout << "\n\n\tYou are surrounded by trees.";
			cout << "\n\n\tA wild boar appears!";
			cout << "\n\n\n\n\n\n\n\n\n\n\n\n";
		}

		//Doom
		else if (doom == 1)
		{
			cout << "\n\n\tYou are surrounded by trees.";
			cout << "\n\n\tA deeps raspy voice echos out...";
			cout << "\n\n\n\n\n\n\n\n\n\n\n\n";
			cout << "\n\n=======================================================";
			cout << "\n A  N  B\t\t\t\t Turn: " << turns;
			cout << "\n    |    ";
			cout << "\n W--X--E \t\t\t\t Gold: " << gold;
			cout << "\n    |    ";
			cout << "\n M  S  Q\t   You cant move. \n\n\t     ";
			system("pause");
			Doom();
			Php = 0;
			doom = 0;
			GameOver();
		}

		//Forest
		else
		{
			cout << "\n\n\tYou are surrounded by trees.";
			cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n";
		}
	}
}

//east west dirt road
void EWDR()
{
	cout << "\n\n\tYou are surrounded by trees.";
	cout << "\n\n\tA dirt road runs east to west.";
	cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n";
}

//Northwest Southeast dirt road
void NWSEDR()
{
	cout << "\n\n\tYou are surrounded by trees.";
	cout << "\n\n\tA dirt road runs form the";
	cout << "\n\tnorth west, to south east.";
	cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n";
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

	Php = 20; //Not working. not sure if i shoud be referencing Php.

	cout << Php;

	system("pause");
	system("cls");
	//------------------------------------------------------------
	HUD();

	cout << "\n\n\n";

	cout << Php;


	cout << "\t|=================|\n";
	cout << "\t|Gus the Innkeeper|\n";
	cout << "\t|=================|\n\n";

	cout << "\tSo you say your on an adveture eh?\n";
	cout << "\tSounds like your gonna need some\n";
	cout << "\tprotection. Here, take this! \n\n";
	cout << "\t(You obtained a Rusty Sword +1 ATK)\n";
	Patk++;
	cout << "\t(You obtained a leather armour +1 Armour)\n\n";
	Pdef++;
	cout << "\tSome bum traded it for a pint of beer,\n";
	cout << "\tand I have no use for it, so keep it.\n\n\n\n\n\n\n\n\n -";

	system("pause");
	system("cls");
	//------------------------------------------------------------
	Play();
}

//Lake Hiliya
void LH()
{
	cout << "\n\n\tYou are in Lake Hiliya.";
	cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n";
}

//Player Controls.
void Input()
{
	char input;

	cout << "\n\n=======================================================";
	cout << "\n A  N  I\t\t\t\t Turn: " << turns;
	cout << "\n    |    ";
	cout << "\n W--X--E \t\t\t\t Gold: " << gold;
	cout << "\n    |    ";
	cout << "\n M  S  Q\tWhat do you want to do? ";
	cin >> input;

	InputLogic(input);

	Play();
}

//Input Logic
void InputLogic(char input)
{
	switch (input)
	{
//Moving
	case 'N':
	case 'n':
		Py = Py + 1;
		turns++;
		break;

	case 'E':
	case 'e':
		Px = Px + 1;
		turns++;
		break;

	case 'S':
	case 's':
		Py = Py - 1;
		turns++;
		break;

	case 'W':
	case 'w':
		Px = Px - 1;
		turns++;
		break;

//Activate
	case 'A':
	case 'a':
		activate = 1;
		turns++;
		break;

//Check Map
	case 'M':
	case 'm':
		if (map == 1)
		{
			Map();
			system("color 07");
		}
		else
		{
			system("cls");
			cout << "\n\n\t You dont have a map.\n\n\t-";
			system("pause");
		}
		break;

//Open Inventory
	case 'I':
	case 'i':
		Inventory();
		break;

//Quit game
	case 'Q':
	case 'q':
		system("cls");
		cout << "\n\n\n\n\t Are you sure you want to quit? <Y/N> ";
		cin >> input;
		if (input == 'Y' || input == 'y')
			leavegame = 1;
		break;

//Invalid
	default:
		Invalid();
		break;

	}

}

//Combat Training setup
void CombatTraining()
{
	system("cls");
	cout << "\n\tChoose your Atk: ";
	cin >> Patk;
	cout << "\n\tChoose your Defense: ";
	cin >> Pdef;
	cout << "\n\tChoose your HP: ";
	cin >> Php;

	//if you have HP
	while (Php > 0)
	{
		system("cls");

		//Fight Enemy
		if (Ehp > 0)
		{
			cout << "\n\n\tYour HP :" << Php;
			cout << "\n\tEnemy HP :" << Ehp << endl;

			cout << "\n       Move|Description";
			cout << "\n       ====|===========";
			cout << "\n\t 1 | Atk x 1";
			cout << "\n\t 2 | Atk x 2";
			cout << "\n\t 3 | Atk x 3";
			cout << "\n\t 4 | Block";
			cout << "\n\n\tPick your move: ";

			cin >> Pchoice;
			Echoice = (rand() % 3 + 1);

			cout << "\n\tPlayer move choice = " << Pchoice;
			cout << "\n\tEnemy move choice = " << Echoice;

			Attack(Patk, Pdef, Php, Pchoice, Eatk, Edef, Ehp, Echoice);

			cout << "\n\n\t- ";
			system("pause");
		}

		//New enemy
		else
		{
			cout << "\n\tChoose Enemy Atk: ";
			cin >> Eatk;
			cout << "\n\tChoose Enemy Defense: ";
			cin >> Edef;
			cout << "\n\tChoose Enemy HP: ";
			cin >> Ehp;
		}
	}
}

//attack Formula
void Attack(int Patk, int Pdef, double &Php, int Pchoice, int Eatk, int Edef, double &Ehp, int Echoice)
{

	int PTatk, PTdef, ETatk;
	int Phit = 1, Ehit = 1;
	double ETdef;
	PTdef = Pdef;

	//attack formula
	switch (Pchoice)
	{
	case 1:
		//player hit enemy
		if (Echoice == 2 || Echoice == 3)
		{
			PTatk = Patk * 1;
			ETdef = HitType(Edef);
			if (PTatk < ETdef)
				Phit = 0;
			Ehp = Ehp - (PTatk - ETdef) * Phit;
		}
		//enemy hit player
		else if (Echoice == 4)
		{
			ETatk = Eatk * 1;
			if (ETatk < PTdef)
				Ehit = 0;
			Php = Php - (ETatk - PTdef) * Ehit;
		}
		break;

	case 2:
		//player and enemy hit each other
		if (Echoice == 2)
		{
			PTatk = Patk * 2;
			ETdef = HitType(Edef);
			if (PTatk < ETdef)
				Phit = 0;
			Ehp = Ehp - (PTatk - ETdef) * Phit;
			ETatk = Eatk * 2;
			if (ETatk < PTdef)
				Ehit = 0;
			Php = Php - (ETatk - PTdef) * Ehit;
		}
		//player hits enemy
		else if (Echoice == 3 || Echoice == 4)
		{
			PTatk = Patk * 2;
			ETdef = HitType(Edef);
			if (PTatk < ETdef)
				Phit = 0;
			Ehp = Ehp - (PTatk - ETdef) * Phit;
		}
		//enemy hits player
		else if (Echoice == 1)
		{
			ETatk = Eatk * 2;
			if (ETatk < PTdef)
				Ehit = 0;
			Php = Php - (ETatk - PTdef) * Ehit;
		}
		break;

	case 3:
		//player and enemy hit each other
		if (Echoice == 3)
		{
			PTatk = Patk * 3;
			ETdef = HitType(Edef);
			if (PTatk < ETdef)
				Phit = 0;
			Ehp = Ehp - (PTatk - ETdef) * Phit;
			ETatk = Eatk * 3;
			if (ETatk < PTdef)
				Ehit = 0;
			Php = Php - (ETatk - PTdef) * Ehit;
		}
		//player hit enemy
		else if (Echoice == 4)
		{
			PTatk = Patk * 3;
			ETdef = HitType(Edef);
			if (PTatk < ETdef)
				Phit = 0;
			Ehp = Ehp - (PTatk - ETdef) * Phit;
		}
		//enemy hit player
		else if (Echoice == 1)
		{
			ETatk = Eatk * 1;
			if (ETatk < PTdef)
				Ehit = 0;
			Php = Php - (ETatk - PTdef) * Ehit;
		}
		break;

	case 4:
		//Enemy Hit player
		if (Echoice == 3)
		{
			ETatk = Eatk * 3;
			if (ETatk < PTdef)
				Ehit = 0;
			Php = Php - (ETatk - PTdef) * Ehit;
		}
		break;
	}
}

//Hit Type
double HitType(int Edef)
{
	int hit;
	double ETdef;

	hit = (rand() % 19);

	if (hit == 0)
	{
		ETdef = Edef / 3;
		cout << "\n\n\tCritical hit.\n";
	}
	else if (hit >= 16 && hit <= 19)
	{
		ETdef = Edef * 2;
		cout << "\n\n\tGlanceing blow.\n";
	}
	else
	{
		ETdef = Edef;
		cout << "\n\n\tSolid strike\n";
	}
	return (ETdef);
}

//Map
void Map()
{
	char key;

	system("cls");
	system("Color 21");

	cout << "|=====================================================|";
	cout << "|#####################################################|";
	cout << "|#######~~~##########            #####################|";
	cout << "|################                       ##############|";
	cout << "|##~~~#########                   #          #########|";
	cout << "|###~~~~#######                  ###          ########|";
	cout << "|#############                #######         ########|";
	cout << "|############                 #####            #######|";
	cout << "|##~~~#######                                #########|";
	cout << "|####~~~#######TT                           ##########|";
	cout << "|#############TTT\\                         ###########|";
	cout << "|##~~~#######     \\                      #####~~######|";
	cout << "|#########         \\                    ##############|";
	cout << "|######             \\-------I------\\    #####~~~######|";
	cout << "|~~###                              \\-H###############|";
	cout << "|####                                    #############|";
	cout << "|####                                     ############|";
	cout << "|###                             _A          #########|";
	cout << "|##                          /\\ /  \\  /\\        ######|";
	cout << "|###                        /^^/^^^^\\/  \\        #####|";
	cout << "|####                      /  /     /^^^^\\       #####|";
	cout << "|############                                   ######|";
	cout << "|##~~~##############                           #######|";
	cout << "|##N###########################               ########|";
	cout << "|=====|###~~~#######################       ###########|";
	cout << "|  N  |##~~~##########################################|";
	cout << "| W+E |=========|=====================|===============|";
	cout << "|  S  | [K] Key |     Dragon Isle     | [Q] Close map |";
	cout << "|=====|=========|=====================|===============|";

	cin >> key;

	if (key == 'K' || key == 'k')
		Key();


}

//Key for map
void Key()
{
	char map;

	system("cls");
	system("color 07");

	cout << "|=====================================================|";
	cout << "|                        __                           |";
	cout << "|                   | / |   \\   /                     |";
	cout << "|                   |/  |_   \\ /                      |";
	cout << "|                   |\\  |     |                       |";
	cout << "|                   | \\ |__   |                       |";
	cout << "|                                                     |";
	cout << "|                                                     |";
	cout << "|         * T = Town                                  |";
	cout << "|         * H = Harbor                                |";
	cout << "|         * I = Gus\'s Inn                             |";
	cout << "|         * A = Dragons Peak                          |";
	cout << "|         * -,\\,/ = Road                              |";
	cout << "|                                                     |";
	cout << "|                                                     |";
	cout << "|                                                     |";
	cout << "|                                                     |";
	cout << "|                                                     |";
	cout << "|                                                     |";
	cout << "|                                                     |";
	cout << "|                                                     |";
	cout << "|                                                     |";
	cout << "|                                                     |";
	cout << "|                                                     |";
	cout << "|                                                     |";
	cout << "|                                                     |";
	cout << "|================|================|===================|";
	cout << "|   [M] = Map    |  Dragons Isle  | [Q] = Close map   |";
	cout << "|================|================|===================|";

	cin >> map;

	if (map == 'M' || map == 'm')
		Map();
}

//Displays Items in Inventory
void Inventory()
{
	string YoN;
	string size;
	int page = 1;
	int tpage;
	char p;

	system("cls");

	if (map == 1)
		YoN = "Yes";
	else
		YoN = "No ";

	if (backpack == 15)
	{
		size = " Small";
		tpage = 1;
	}
	else if (backpack == 30)
	{
		size = "Medium";
		tpage = 1;
	}
	else if (backpack == 60)
	{
		size = " Large";
		tpage = 2;
	}
	else
	{
		size = "  No  ";
		tpage = 0;
	}

	cout << "||===================================================||";
	cout << "||                    Inventory                      ||";
	cout << "||===================================================||";
	cout << "|| Hands | Right: " << Hands[0] << "\t | Left: " << Hands[1] << "   ||";
	cout << "||===================================================||";
	cout << "|| Armour equipped: " << Armour[0] << "\t | Map: " << YoN << "          ||";
	cout << "||===================================================||";
	cout << "||    " << size << " backpack      |       " << backpack << " slots           ||";
	cout << "||===================================================||";
	cout << "|| - \t\t\t   | - \t\t\t     ||";
	cout << "|| - \t\t\t   | - \t\t\t     ||";
	cout << "|| - \t\t\t   | - \t\t\t     ||";
	cout << "|| - \t\t\t   | - \t\t\t     ||";
	cout << "|| - \t\t\t   | - \t\t\t     ||";
	cout << "|| - \t\t\t   | - \t\t\t     ||";
	cout << "|| - \t\t\t   | - \t\t\t     ||";
	cout << "|| - \t\t\t   | - \t\t\t     ||";
	cout << "|| - \t\t\t   | - \t\t\t     ||";
	cout << "|| - \t\t\t   | - \t\t\t     ||";
	cout << "|| - \t\t\t   | - \t\t\t     ||";
	cout << "|| - \t\t\t   | - \t\t\t     ||";
	cout << "|| - \t\t\t   | - \t\t\t     ||";
	cout << "|| - \t\t\t   | - \t\t\t     ||";
	cout << "||===================================================||";
	cout << "||             Page <<" << page << ">> of Page <<" << tpage << ">>              ||";
	cout << "||===================================================||";
	cout << "||   [N] Next page    [P] Previous page    [Q] Quit  ||";
	cout << "||===================================================||";
	cout << " Left/Right Hand = LH/RH then Item Number in Inventory ";
	cin >> p;

	switch (p)
	{
	case 'N':
	case 'n':
		if (page < tpage)
			page = page + 1;
		Inventory();
		break;
	case 'P':
	case 'p':
		if (page > 1)
			page = page - 1;
		Inventory();
		break;
	default:
		Play();
	}
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
	MainMenu();
}

//hit enter to continue
void HitEnter()
{
	int enter;
	fflush(stdout);
	do enter = getchar(); while ((enter != '\n') && (enter != EOF));
}

//Invalid: Please make valid selection
void Invalid()
{
	system("cls");
	cout << "\n\n\n\n\n\n\tPlease make a valid selection\n\n\t";
	system("pause");
}

//credits
void Credits()
{
	system("cls");
	cout << "\n\n\n\n\t Made in C++.";
	cout << "\n\t Programed by: Jack Melvin.\n\n\t-";
	system("pause");
}

//DOOM!
void Doom()
{
	system("cls");
	cout << "\n\n\n\t\t Welcome to your"; //DOOM
	cout << "\n\t  ____	                   __      __";
	cout << "\n\t |    \\     ___     ___   |  \\    /  |";
	cout << "\n\t |  |\\ \\   / _ \\   / _ \\  |   \\  /   |";
	cout << "\n\t |  | \\ \\ / / \\ \\ / / \\ \\ | |\\ \\/ /| |";
	cout << "\n\t |  |_/ / \\ \\_/ / \\ \\_/ / | | \\__/ | |";
	cout << "\n\t |_____/   \\___/   \\___/  |_|      |_|";
	cout << "\n\n\t   You realise you are about to die,";
	cout << "\n\n\t as you see death pull out your soul.\n\n\t      ";

	system("pause");
}
