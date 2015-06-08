#include <string>
#include <iostream>
#include <fstream>
#include "StrLib.h"
#include "hero.h"
#include "powers.h"

Powers* powerFactory(string power);

void Hero::setPowers()
{
	for (int i = 0; i < powers.size(); i++)
	{
		powPoint.push_back(powerFactory(powers[i]));
	}
}

string Hero::getname()
{
	return name;
}

int Hero::getHealth()
{
	return curHealth;
}
void Hero::printHealth() 
	{
		cout << "\t" << name << " currently has " << curHealth << " health" << endl;
	}
void Hero::printPowers()
{
	cout << "\t" << name << " has the following powers: " << endl;
	for (int i = 0; i < powPoint.size(); i++)
	{
		cout << "\t-" << powPoint[i]->getDescription() << endl;
	}
}

Powers* Hero::useRandomPower()
{
	int pow = rand() % powers.size();
	return powPoint[pow];
}
void Hero::takeDamage()
{
	curHealth--;
}
void Hero::resetHealth()
{
	curHealth = maxHealth;
}
