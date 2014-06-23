#include <iostream>
#include <fstream>
#include "BasicFeatures.h"

using namespace std;

//Constructor
BasicFeatures::BasicFeatures()
{
	this->Name = new char [3];
	strcpy_s(this->Name, 3, "NU");
	this->Attack = 0;
	this->Defense = 0;
}

//Destructor
BasicFeatures::~BasicFeatures()
{
	clear();
}

//Constructor for copy one BasicFeatures to other
BasicFeatures::BasicFeatures(const BasicFeatures& other)
{
	copy(other);
}

//Constructor for easy creating a BasicFeatures
BasicFeatures::BasicFeatures(const char* Name, size_t Attack, size_t Defense)
{
	int nameLen = strlen(Name)+1;
	this->Name = new char [nameLen];
	strcpy_s(this->Name,nameLen,Name);
	this->Attack = Attack;
	this->Defense = Defense;
}


//Compares that two BasicFeatures are equal
bool BasicFeatures::operator == (const BasicFeatures& other)
{
	if(strcmp(this->Name, other.getName()) && this->Attack == other.getAttack() && this->Defense == other.getDefense())
		return true;
	else
		return false;
}

//Compares that two BasicFeatures are not equal(if only one is not true this BasicFeatures are not equal)
bool BasicFeatures::operator != (const BasicFeatures& other)
{
	return !(*this == other);
}

//Åquales two BasicFeatures
BasicFeatures& BasicFeatures::operator = (const BasicFeatures& other)
{
	if(*this != other)
	{
		clear();

		int nameLen = strlen(other.getName())+1;
		this->Name = new char [nameLen];
		strcpy_s(this->Name,nameLen,other.getName());
		this->Attack = other.getAttack();
		this->Defense = other.getDefense();
	}
	return *this;
}


//Get name
char* BasicFeatures::getName() const
{
	return this->Name;
}

//Get attack
size_t BasicFeatures::getAttack() const
{
	return this->Attack;
}

//Get defense
size_t BasicFeatures::getDefense() const
{
	return this->Defense;
}


//Set Name
void BasicFeatures::setName(const char* Name)
{
	if (Name != NULL)
	{	
		int nameLen = strlen(Name)+1;
		this->Name = new char [nameLen];
		if(this->Name)
			strcpy_s(this->Name,nameLen,Name);
	}
	else
		cout << "Dont have name to set! " << endl;
}

//Set Attack
void BasicFeatures::setAttack(size_t Attack)
{
	if (Attack > 0)
		this->Attack = Attack;
	else 
		cout << "Attack of this hero cant be less than 1" << endl;
}

//Set Defense
void BasicFeatures::setDefense(size_t Defense)
{
	if(Defense > 0)
		this->Defense = Defense;
	else 
		cout << "Defense of hero cant be less than 1" << endl;
}


//Clear memory
void BasicFeatures::clear()
{
	delete [] this->Name;
	this->Name = NULL;
}

//Copying data
void BasicFeatures::copy(const BasicFeatures& other)
{
	int nameLen = strlen(other.getName())+1;
	this->Name = new char [nameLen];
	strcpy_s(this->Name,nameLen,other.getName());
	this->Attack = other.getAttack();
	this->Defense = other.getDefense();
}



//Print in console
void BasicFeatures::printBasicFeatures() const
{
	cout << "Name: " << getName() << endl;
	cout << "Attack: " << getAttack() << endl;
	cout << "Defense: " << getDefense() << endl;
}

void BasicFeatures::loadBasicFeatures(ifstream& fin)
{
	char tempName[100];
	size_t	tempAttack, tempDefense;
	fin.getline(tempName, 100, '\n');
	fin >> tempAttack >> tempDefense;
	setName(tempName);
	setAttack(tempAttack);
	setDefense(tempDefense);
}

//Print in flow
ostream& BasicFeatures::saveBasicFeatures(ofstream& out) const
{
	out << getName() << endl;
	out << getAttack() << endl;
	out << getDefense() << endl;
	return out;
}