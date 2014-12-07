#include <iostream>
#include <fstream>
#include "Item.h"
#include "Gear.h"


using namespace std;

//Constructor
Gear::Gear() :
ownHead(new Head()),
ownBoots(new Boots()),
ownRing(new Ring()),
ownShield(new Shield()),
ownWeapon(new Weapon())
{}

//Destructor
Gear::~Gear()
{
	delete ownHead;
	delete ownBoots;
	delete ownRing;
	delete ownShield;
	delete ownWeapon;
}

//Constructor for copy one gear to other
Gear::Gear(const Gear& other)
{
	(*this) = other;
}

//Constructor for easy creating a gear
Gear::Gear(Head* newHead, Boots* newBoots, Ring* newRing, Shield* newShield, Weapon* newWeapon):
		   ownHead(newHead),
		   ownBoots(newBoots),
		   ownRing(newRing),
		   ownShield(newShield),
		   ownWeapon(newWeapon)
{}


//Compares that two gears are equal
bool Gear::operator == (const Gear& other)
{
	return ((this->ownHead == other.getOwnItem(HEAD)) &&
		(this->ownBoots == other.getOwnItem(BOOTS)) &&
		(this->ownRing == other.getOwnItem(RING)) &&
		(this->ownShield == other.getOwnItem(SHIELD)) &&
		(this->ownWeapon == other.getOwnItem(WEAPON)));
}

//Compares that two gears are not equal
bool Gear::operator != (const Gear& other)
{
	return !(*this == other);
}

//Equated two gears
Gear& Gear::operator = (const Gear& other)
{
	if(*this != other)
	{
		this->ownHead = other.getOwnItem(HEAD)->Clone();
		this->ownBoots = other.getOwnItem(BOOTS)->Clone();
		this->ownRing = other.getOwnItem(RING)->Clone();
		this->ownShield = other.getOwnItem(SHIELD)->Clone();
		this->ownWeapon = other.getOwnItem(WEAPON)->Clone();
	}
	return *this;
}


Item* Gear::getOwnItem(TypeOfItems required) const
{
	switch (required)
	{
	case BOOTS:
		return this->ownBoots;
	case HEAD:
		return this->ownHead;
	case RING:
		return this->ownRing;
	case SHIELD:
		return this->ownShield;
	case WEAPON:
		return this->ownWeapon;
	default:
		cout << "I dont have such a item!" << endl;
		break;
	}
}


//Set Head to gear
void Gear::setItemInGear(Item* newItem)
{
	switch (newItem->getTypeOfItem())
	{
	case BOOTS:
		this->ownBoots = newItem;
		break;
	case HEAD:
		this->ownHead = newItem;
		break;
	case RING:
		this->ownRing = newItem;
		break;
	case SHIELD:
		this->ownShield = newItem;
		break;
	case WEAPON:
		this->ownWeapon = newItem;
		break;
	default:
		cout << "This is some strange of item that i suggest you place in a special place!" << endl;
		break;
	}
}


//Know that gear is valid
bool Gear::GearIsValid() const
{
	return ((this->ownHead != NULL && this->ownHead->ItemIsValid()) &&
		(this->ownBoots != NULL && this->ownBoots->ItemIsValid()) &&
		(this->ownRing != NULL && this->ownRing->ItemIsValid()) &&
		(this->ownShield != NULL && this->ownShield->ItemIsValid()) &&
		(this->ownWeapon != NULL && this->ownWeapon->ItemIsValid()));
}

//Print gear
void Gear::printGear() const
{
	cout << "Gear:" << endl;
	getOwnItem(HEAD)->printItem();
	getOwnItem(BOOTS)->printItem();
	getOwnItem(RING)->printItem();
	getOwnItem(SHIELD)->printItem();
	getOwnItem(WEAPON)->printItem();
}

//Save gear in flow
ofstream& Gear::saveGear(ofstream& fout) const
{
	this->ownHead->saveItem(fout);
	this->ownBoots->saveItem(fout);
	this->ownRing->saveItem(fout);
	this->ownShield->saveItem(fout);
	this->ownWeapon->saveItem(fout);
	fout << endl;

	return fout;
}

//Load gear from flow
void Gear::loadGear(ifstream& fin)
{
	this->ownHead->loadItem(fin);
	this->ownBoots->loadItem(fin);
	this->ownRing->loadItem(fin);
	this->ownShield->loadItem(fin);
	this->ownWeapon->loadItem(fin);
}