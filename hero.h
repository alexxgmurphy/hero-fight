#include <string>
#include <iostream>
#include <fstream>

using namespace std;

class Powers;

class Hero
{
	int maxHealth;
	int curHealth;
	string name;
	vector<string> powers;
	vector<Powers*> powPoint;

public:
	Hero(string a)
	{
		string powerString = "";
		vector<string> tempVec;
		vector<string> info = strSplit(a, '|');
		name = info[0];
		curHealth = stoi(info[2]);
		maxHealth = stoi(info[2]);
		powers = strSplit(info[1], ',');
	}
	void setPowers();
	string getname();
	int getHealth();
	void printHealth();
	void printPowers();
	Powers* useRandomPower();
	void takeDamage();
	void resetHealth();
};
