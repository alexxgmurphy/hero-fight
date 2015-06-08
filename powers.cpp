#include <string>
#include <iostream>
#include <fstream>
#include "StrLib.h"
#include "powers.h"
#include "hero.h"

Powers* powerFactory(string power)
{
	if (power == "flight")
	{
		Flight* flight = new Flight;
		return flight;
	}
	else if (power == "gadget")
	{
		Gadgets* gadget = new Gadgets;
		return gadget;
	}
	else if (power == "intel")
	{
		Intelligence* intel = new Intelligence;
		return intel;
	}
	else if (power == "laser")
	{
		Laser* laser = new Laser;
		return laser;
	}
	else if (power == "national")
	{
		Nationalism* nat = new Nationalism;
		return nat;
	}
	else if (power == "strength")
	{
		Strength* stren = new Strength;
		return stren;
	}
}


string Powers::getDescription()
{
	return mDescription;
}


int Flight::getID()
{
	return C_FLIGHT;
}
void Flight::use()
{
	cout << "powers of flight";
}
int Flight::fight(Powers* opponent)
{
	if (opponent->getID() == 3 || opponent->getID() == 5 || opponent->getID() == 6)
	{
		cout << "Flight beats " << opponent->getDescription() << "!" << endl;
		return 1;
	}
	else if (opponent->getID() == 1)
	{
		cout << "Flight is matched by " << opponent->getDescription() << "!" << endl;
		return 0;
	}
	else if (opponent->getID() == 2 || opponent->getID() == 4)
	{
		cout << "Flight is defeated by " << opponent->getDescription() << "!" << endl;
		return -1;
	}
}

int Gadgets::getID()
{
	return C_GADGETS;
}
void Gadgets::use()
{
	cout << "wealth of gadgets";
}
int Gadgets::fight(Powers* opponent)
{
	if (opponent->getID() == 1 || opponent->getID() == 4 || opponent->getID() == 5)
	{
		cout << "The gadgets defeat " << opponent->getDescription() << "!" << endl;
		return 1;
	}
	else if (opponent->getID() == 2)
	{
		cout << "The gadgets are matched by " << opponent->getDescription() << "!" << endl;
		return 0;
	}
	else if (opponent->getID() == 3	|| opponent->getID() == 6)
	{
		cout << "The gadgets are defeated by " << opponent->getDescription() << "!" << endl;
		return -1;
	}
}

int Intelligence::getID()
{
	return C_INTELLIGENCE;
}
void Intelligence::use()
{
	cout << "fearsome intelligence";
}
int Intelligence::fight(Powers* opponent)
{
	if (opponent->getID() == 2 || opponent->getID() == 5 || opponent->getID() == 6)
	{
		cout << "Intelligence beats " << opponent->getDescription() << "!" << endl;
		return 1;
	}
	else if (opponent->getID() == 3)
	{
		cout << "Intelligence is matched by " << opponent->getDescription() << "!" << endl;
		return 0;
	}
	else if (opponent->getID() == 1 || opponent->getID() == 4)
	{
		cout << "Intelligence is defeated by " << opponent->getDescription() << "!" << endl;
		return -1;
	}
}

int Laser::getID()
{
	return C_LASER;
}
void Laser::use()
{
	cout << "PEW PEW PEW";
}
int Laser::fight(Powers* opponent)
{
	if (opponent->getID() == 1 || opponent->getID() == 3 || opponent->getID() == 5)
	{
		cout << "Lasers defeat " << opponent->getDescription() << "!" << endl;
		return 1;
	}
	else if (opponent->getID() == 4)
	{
		cout << "Lasers are matched by " << opponent->getDescription() << "!" << endl;
		return 0;
	}
	else if (opponent->getID() == 2 || opponent->getID() == 6)
	{
		cout << "Lasers are defeated by " << opponent->getDescription() << "!" << endl;
		return -1;
	}
}

int Nationalism::getID()
{
	return C_NATIONALISM;
}
void Nationalism::use()
{
	cout << "undying patriotism";
}
int Nationalism::fight(Powers* opponent)
{
	if (opponent->getID() == 5)
	{
		cout << "Nationalism is matched by " << opponent->getDescription() << "!" << endl;
		return 0;
	}
	else if (opponent->getID() == 1 || opponent->getID() == 2 || opponent->getID() == 3 || opponent->getID() == 4 || opponent->getID() == 6)
	{
		cout << "Nationalism is defeated by " << opponent->getDescription() << "!" << endl;
		return -1;
	}
}

int Strength::getID()
{
	return C_STRENGTH;
}
void Strength::use()
{
	cout << "incredible strength";
}
int Strength::fight(Powers* opponent)
{
	if (opponent->getID() == 2 || opponent->getID() == 4 || opponent->getID() == 5)
	{
		cout << "Strength defeats " << opponent->getDescription() << "!" << endl;
		return 1;
	}
	else if (opponent->getID() == 6)
	{
		cout << "Strength is matched by " << opponent->getDescription() << "!" << endl;
		return 0;
	}
	else if (opponent->getID() == 1 || opponent->getID() == 3)
	{
		cout << "Strength is defeated by " << opponent->getDescription() << "!" << endl;
		return -1;
	}
	return 0;
}
