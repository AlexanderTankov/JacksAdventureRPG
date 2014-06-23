#include <iostream>
#include "BasicFeatures.h"
#include "Monster.h"
#include "Cell.h"

using namespace std;

//Constructor
Monster::Monster() : BasicFeatures() , Cell('%')
{
	this->Life = 100;
	this->MaxLife = 100;
	this->Experience = 0;
}

//Destructor
Monster::~Monster()
{
}

//Constructor for copy one monster to other
Monster::Monster(const Monster& other) : BasicFeatures(other) , Cell(other)
{
	this->Life = other.getLife();
	this->MaxLife = other.getMaxLife();
	this->Experience = other.getExperience();
}

//Constructor for easy creating a monster
Monster::Monster(const char* Name, size_t Attack, size_t Defense, size_t MaxLife, size_t Experience, size_t Row, size_t Column) 
	: BasicFeatures(Name, Attack, Defense) , Cell(Row, Column, '%')
{
	this->Life = MaxLife;
	this->MaxLife = MaxLife;
	this->Experience = Experience;
}


//Get Monster life
size_t Monster::getLife() const
{
	return this->Life;
}

//Get Monster maximum life
size_t Monster::getMaxLife() const
{
	return this->MaxLife;
}

//Get Monster experience
size_t Monster::getExperience() const
{
	return this->Experience;
}


//Set Life to Monster
void Monster::setLife(size_t Life)
{
	if(Life >= 0)
		this->Life =  Life;
	else 
		cout << "Life of hero cant be less than 0" << endl;
}

//Set maximum life to Monster
void Monster::setMaxLife(size_t MaxLife)
{
	if(MaxLife > 0 && MaxLife >= this->Life)
		this->MaxLife = MaxLife;
	else
		cout << "Maximum life of monster cant be less than 1 and cant be less than moment life" << endl;
}

//Set Experience to Monster
void Monster::setExperience(size_t Experience)
{
	
	if(Experience < 100 && Experience > 0)
		this->Experience = Experience;
	else
		cout << "Every 100 XP = 1 level and because of that this Monster cant have more than 100 XP and less than 1" << endl;
}


ostream& Monster::saveMonster(ofstream& fout) const
{
	saveBasicFeatures(fout);
	fout << getLife() << endl;
	fout << getMaxLife() << endl;
	fout << getExperience() << endl;
	return fout;
}

void Monster::loadMonster(ifstream& fin)
{
	loadBasicFeatures(fin);
	size_t mLife, mMaxLife, mExperience;
	fin >> mLife >> mMaxLife >> mExperience;
	setLife(mLife);
	setMaxLife(mMaxLife);
	setExperience(mExperience);
}


//Remove health from monster ( Health -= Attack)
void Monster::removeHealth(size_t Attack)
{
	if(getLife() > Attack)
		setLife(getLife() - Attack);
	else
		setLife(0);
}

//Defense reduce attack (1 def = 2% att)
size_t Monster::reduceAttack(size_t Defense)
{
	size_t Attack = getAttack();
	Attack -= ((Defense*2)/100)*getAttack();
	return Attack;
}

//Print Monster
void Monster::printMonster() const
{
	cout << "==================== New Monster ===========================" << endl;
	BasicFeatures::printBasicFeatures();
	cout << "Life: " << getLife() << "/" << getMaxLife() << endl;
	cout << "Experiance: " << getExperience() << endl; 

}
