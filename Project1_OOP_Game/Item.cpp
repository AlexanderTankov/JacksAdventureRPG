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


//operator =
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

//operator ==
bool Item::operator== (const Item& other)
{
	if(!strcmp(getName(), other.getName()) && getAttack() == other.getAttack() && getDefense() == other.getDefense()
		&& getMana() == other.getMana())
		return true;
	else
		return false;
}

//operator !=
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

void Item::loadItem(ifstream& fin)
{
	loadBasicFeatures(fin);
	size_t iMana;
	fin >> iMana;
	setMana(iMana);
}

//Print item in flow
ostream& Item::saveItem(ofstream& out) const
{
	saveBasicFeatures(out);
	out << getMana() << endl;
	return out;
}

////operator <<
//ostream& operator << (ofstream& out, const Item& other)
//{
//	other.saveItem(out);
//	return out;
//}

