#include <iostream>
#include "BasicFeatures.h"
#include "Item.h"

using namespace std;

//operator <<
ostream& operator << (ostream& out, const Item& other)
{
	out << "Name: " << other.getName() << endl;
	out << "Attack: " << other.getAttack() << endl;
	out << "Defense: " << other.getDefense() << endl;
	out << "Mana: " << other.getMana() << endl;
	out << "Type of item: " << other.getTypeOfItem() << endl;
	return out;
}