#include <iostream>
#include <fstream>
#include "BasicFeatures.h"
#include "Item.h"

using namespace std;

//Constructor
Item::Item() : BasicFeatures()
{
	this->Mana = 0;
}

//Destructor
Item::~Item()
{
}

//Constructor for copy one item to other
Item::Item(const Item& other) : BasicFeatures(other)
{
	this->Mana = other.getMana();
}

//Constructor for easy creating a item
Item::Item(const char* Name, size_t Attack, size_t Defense, size_t Mana)
	: BasicFeatures (Name, Attack, Defense)
{
	this->Mana = Mana;
}


//Compares that two items are equal
Item& Item::operator= (const Item& other)
{
	if(*this != other)
	{
		BasicFeatures::clear();

		BasicFeatures::copy(other);
		this->Mana = other.getMana();
	}
	return *this;
}

//Compares that two items are not equal
bool Item::operator== (const Item& other)
{
	if(!strcmp(getName(), other.getName()) && getAttack() == other.getAttack() && getDefense() == other.getDefense()
		&& getMana() == other.getMana())
		return true;
	else
		return false;
}

//Equated two items
bool Item::operator!= (const Item& other)
{
	return !(*this == other);
}


//Get Item bonus
size_t Item::getMana() const
{
	return this->Mana;
}


//Set Bonus to Item
void Item::setMana(size_t Mana)
{
	if(Mana > 0)
		this->Mana = Mana;
	else
		cout << "Mana cant be less than 1" << endl;
}


//Print item
void Item::printItem() const
{
	cout << getName() << '/' << getAttack() << '/' << getDefense() << '/' << getMana() << " (Name/Attack/Defense/Mana) " << endl;;
}

//Load item from flow
void Item::loadItem(ifstream& fin)
{
	loadBasicFeatures(fin);
	size_t iMana;
	fin >> iMana;
	setMana(iMana);
}

//Save item in flow
ostream& Item::saveItem(ofstream& out) const
{
	saveBasicFeatures(out);
	out << getMana();
	return out;
}


