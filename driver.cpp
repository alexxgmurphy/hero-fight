#include <string>
#include <iostream>
#include <fstream>
#include "StrLib.h"
#include "hero.h"
#include "powers.h"

string filename;
vector<Hero*> heroes;

//Read in info from text file, add them to vector
void loadHeroes(string filename, vector<Hero*> &heroes)
{
	heroes.clear();
	string line = "";
	std::ifstream fileInput(filename);
	while (getline(fileInput, line))
	{
		heroes.push_back(new Hero(line));
	}
}

//prints out hero names, powers, and health
void printRoster(vector<Hero*> heroes)
{
	for (int i = 0; i < heroes.size(); i++)
	{
		cout << heroes[i]->getname() << endl;
		heroes[i]->printHealth();
		heroes[i]->printPowers();
		cout << "________________________________________________________" << endl;
	}
}

//selects hero based on user input
Hero* selectHero(string userInput)
{
	if (stoi(userInput))
	{
		int choice = stoi(userInput);
		if (choice >= 0 && choice < heroes.size())
		{
			return heroes[choice];
		}
		else
		{
			cout << "Please enter a number between 1 and " << heroes.size() + 1 << " to indicate your chosen hero" << endl;
		}
	}
	else
	{
		cout << "Please enter a valid integer between 1 and " << heroes.size() - 1 << endl;
	}
	return 0;
}

//Uses randomization to have heroes fight each other based on predetermined hierarchy of powers and health
void heroCombat()
{
	cout << "The following heroes are available to battle: " << endl;
	for (int i = 1; i < heroes.size() + 1; i++)
	{
		cout << "\t" << i << ". " << heroes[i - 1]->getname() << endl;
	}
	cout << "Enter a number to choose your first hero!" << endl;
	string userInput;
	cin >> userInput;
	Hero* hero1 = selectHero(userInput);
	cout << "You chose " << hero1->getname() << endl;
	cout << "Enter a number to choose your second hero!" << endl;
	string in2;
	cin >> in2;
	Hero* hero2 = selectHero(in2);
	cout << "You chose " << hero2->getname() << endl;
	cout << hero1->getname() << " is preparing to fight " << hero2->getname() << "\n\n" << endl;
	while (hero1->getHealth() > 0 && hero2->getHealth() > 0)
	{
		Powers* power1 = heroes[stoi(userInput) - 1]->useRandomPower();
		Powers* power2 = heroes[stoi(in2) - 1]->useRandomPower();
		cout << hero1->getname() << " uses their ";
		power1->use();
		cout << " against " << hero2->getname() << "'s ";
		power2->use();
		cout << "\n" << endl;
		int result = power1->fight(power2);
		if (result == 1)
		{
			hero2->takeDamage();
		}
		else if (result == -1)
		{
			hero1->takeDamage();
		}
		else if (result == 0)
		{
			hero1->takeDamage();
			hero2->takeDamage();
		}
		cout << "\n" << endl;
		hero1->printHealth();
		hero2->printHealth();
		cout << "__________________________________" << endl;
	}
	if (hero1->getHealth() == 0)
	{
		cout << hero2->getname() << " has defeated " << hero1->getname() << " in battle!\n\n" << endl;
	}
	else if (hero2->getHealth() == 0)
	{
		cout << hero1->getname() << " has defeated " << hero2->getname() << " in battle!\n\n" << endl;
	}
	hero1->resetHealth();
	hero2->resetHealth();
}

int main()
{
	cout << "Welcome to... THE THUNDERDOME!\n" << endl;
	bool cont = true;
	do
	{
		//create menu
		cout << "Choose one of the following: " << endl;
		cout << "\t1. Load heroes\n\t2. Print roster\n\t3. Fight!\n\t4. Quit" << endl;
		int choice;
		cin >> choice;
		if (choice == 1)
		{
			cout << "\n\nEnter the name of the file containing your heroes' information: ";
			cin >> filename;
			loadHeroes(filename, heroes);
			for (int i = 0; i < heroes.size(); i++)
			{
				heroes[i]->setPowers();
			}
			cout << "\n\n" << heroes.size() << " heroes loaded!\n\n" << endl;
		}
		else if (choice == 2)
		{
			printRoster(heroes);
		}
		else if (choice == 3)
		{
			cout << "Let's get ready to rumble!!!" << endl;
			heroCombat();
		}
		else if (choice == 4)
		{
			for (int i = 0; i < heroes.size(); i++)
			{
				delete heroes[i];
			}
			break;
		}
	} while (cont = true);
	return 0;
}
