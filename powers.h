#include <string>
#include <iostream>
#include <fstream>
#include "StrLib.h"

using namespace std;

//integers
const int C_FLIGHT = 1;
const int C_GADGETS = 2;
const int C_INTELLIGENCE = 3;
const int C_LASER = 4;
const int C_NATIONALISM = 5;
const int C_STRENGTH = 6;

//abstract power class
class Powers
{
protected:
	string mDescription = "";
public:
	string getDescription();
	virtual int getID() = 0;
	virtual void use() = 0;
	virtual int fight(Powers*) = 0;
};

class Flight : public Powers
{
public:
	Flight()
	{
		mDescription = "flight";
	}
	int getID();
	void use();
	int fight(Powers* opponent);
};

class Gadgets : public Powers
{
public:
	Gadgets()
	{
		mDescription = "gadgets";
	}
	int getID();
	void use();
	int fight(Powers* opponent);
};

class Intelligence : public Powers
{
public:
	Intelligence()
	{
		mDescription = "intelligence";
	}
	int getID();
	void use();
	int fight(Powers* opponent);
};

class Laser : public Powers
{
public:
	Laser()
	{
		mDescription = "laser";
	}
	int getID();
	void use();
	int fight(Powers* opponent);
};

class Nationalism : public Powers
{
public:
	Nationalism()
	{
		mDescription = "nationalism";
	}
	int getID();
	void use();
	int fight(Powers* opponent);
};

class Strength : public Powers
{
public:
	Strength()
	{
		mDescription = "strength";
	}
	int getID();
	void use();
	int fight(Powers* opponent);
};
