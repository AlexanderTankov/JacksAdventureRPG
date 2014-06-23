#include <iostream>
#include "Item.h"
#include "Gear.h"


using namespace std;

//Constructor
Gear::Gear()
{
}

//Destructor
Gear::~Gear()
{
}

//Constructor for copy one gear to other
Gear::Gear(const Gear& other)
{
	this->ownHead = other.getOwnHead();
	this->ownShoulders = other.getOwnShoulders();
	this->ownChest = other.getOwnChest();
	this->ownGloves = other.getOwnGloves();
	this->ownBoots = other.getOwnBoots();
	this->ownBelt = other.getOwnBelt();
	this->ownPants = other.getOwnPants();
	this->ownRing = other.getOwnRing();
	this->ownShield = other.getOwnShield();
	this->ownWeapon = other.getOwnWeapon();
}

//Constructor for easy creating a gear
Gear::Gear(Head newHead, Shoulders newShoulders, Chest newChest, Gloves newGloves, Boots newBoots,
		   Belt newBelt, Pants newPants, Ring newRing, Shield newShield, Weapon newWeapon)
{
		this->ownHead = newHead;
		this->ownShoulders = newShoulders;
		this->ownChest = newChest;
		this->ownGloves = newGloves;
		this->ownBoots = newBoots;
		this->ownBelt = newBelt;
		this->ownPants = newPants;
		this->ownRing = newRing;
		this->ownShield = newShield;
		this->ownWeapon = newWeapon;
}


bool Gear::operator == (const Gear& other)
{
	if((this->ownHead == other.getOwnHead()) && (this->ownShoulders == other.getOwnShoulders()) && (this->ownChest == other.getOwnChest()) &&
		(this->ownGloves == other.getOwnGloves()) && (this->ownBoots == other.getOwnBoots()) && (this->ownBelt == other.getOwnBelt()) && 
		(this->ownPants == other.getOwnPants()) && (this->ownRing == other.getOwnRing()) && (this->ownShield == other.getOwnShield()) && 
		(this->ownWeapon == other.getOwnWeapon()))
		return true;
	else
		return false;
}

bool Gear::operator != (const Gear& other)
{
	return !(*this == other);
}

Gear& Gear::operator = (const Gear& other)
{
	if(*this != other)
	{
		this->ownHead = other.getOwnHead();
		this->ownShoulders = other.getOwnShoulders();
		this->ownChest = other.getOwnChest();
		this->ownGloves = other.getOwnGloves();
		this->ownBoots = other.getOwnBoots();
		this->ownBelt = other.getOwnBelt();
		this->ownPants = other.getOwnPants();
		this->ownRing = other.getOwnRing();
		this->ownShield = other.getOwnShield();
		this->ownWeapon = other.getOwnWeapon();
	}
	return *this;
}


//Get Head
Head Gear::getOwnHead() const
{
	return this->ownHead;
}

//Get Shoulders
Shoulders Gear::getOwnShoulders() const
{
	return this->ownShoulders;
}

//Get Chest
Chest Gear::getOwnChest() const
{
	return this->ownChest;
}

//Get Gloves
Gloves Gear::getOwnGloves() const
{
	return this->ownGloves;
}

//Get Boots
Boots Gear::getOwnBoots() const
{
	return this->ownBoots;
}

//Get Belt
Belt Gear::getOwnBelt() const
{
	return this->ownBelt;
}

//Get Pants
Pants Gear::getOwnPants() const
{
	return this->ownPants;
}

//Get Ring
Ring Gear::getOwnRing() const
{
	return this->ownRing;
}

//Get Shield
Shield Gear::getOwnShield() const
{
	return this->ownShield;
}

//Get Weapon
Weapon Gear::getOwnWeapon() const
{
	return this->ownWeapon;
}


//Set Head to gear
void Gear::setOwnHead(Head newHead)
{
	this->ownHead = newHead;
}

//Set Head to gear
void Gear::setOwnShoulders(Shoulders newShoulders)
{
	this->ownShoulders = newShoulders;
}

//Set Shoulders to gear
void Gear::setOwnChest(Chest newChest)
{
	this->ownChest = newChest;
}

//Set Gloves to gear
void Gear::setOwnGloves(Gloves newGloves)
{
	this->ownGloves = newGloves;
}

//Set Boots to gear
void Gear::setOwnBoots(Boots newBoots)
{
		this->ownBoots = newBoots;
}

//Set Belt to gear
void Gear::setOwnBelt(Belt newBelt)
{
		this->ownBelt = newBelt;
}

//Set Pants to gear
void Gear::setOwnPants(Pants newPants)
{
		this->ownPants = newPants;
}

//Set Ring to gear
void Gear::setOwnRing(Ring newRing)
{
		this->ownRing = newRing;
}

//Set Shield to gear
void Gear::setOwnShield(Shield newShield)
{
		this->ownShield = newShield;
}	

//Set Weapon to gear
void Gear::setOwnWeapon(Weapon newWeapon)
{
		this->ownWeapon = newWeapon;
}


////Know that gear is valid
//bool Gear::isValid() const
//{
//	//ako ima vsichko
//}

//Print gear
void Gear::printGear() const
{
	cout << "Gear:" << endl;
	getOwnHead().printItem();
	getOwnShoulders().printItem();
	getOwnBelt().printItem();
	getOwnPants().printItem();
	getOwnChest().printItem();
	getOwnRing().printItem();
	getOwnGloves().printItem();
	getOwnShield().printItem();
	getOwnBoots().printItem();
	getOwnWeapon().printItem();
}

ofstream& Gear::saveGear(ofstream& fout) const
{
	this->ownHead.saveItem(fout);
	this->ownShoulders.saveItem(fout);
	this->ownChest.saveItem(fout);
	this->ownGloves.saveItem(fout);
	this->ownBoots.saveItem(fout);
	this->ownBelt.saveItem(fout);
	this->ownPants.saveItem(fout);
	this->ownRing.saveItem(fout);
	this->ownShield.saveItem(fout);
	this->ownWeapon.saveItem(fout);
	return fout;
}

void Gear::loadGear(ifstream& fin)
{
	this->ownHead.loadItem(fin);
	this->ownShoulders.loadItem(fin);
	this->ownChest.loadItem(fin);
	this->ownGloves.loadItem(fin);
	this->ownBoots.loadItem(fin);
	this->ownBelt.loadItem(fin);
	this->ownPants.loadItem(fin);
	this->ownRing.loadItem(fin);
	this->ownShield.loadItem(fin);
	this->ownWeapon.loadItem(fin);
}

////operator <<
//ostream& operator << (ostream& out, const Gear& other)
//{
//	out << "Gear:" << endl;
//	out << other.getOwnHead() << endl << other.getOwnShoulders() << endl;
//	out << other.getOwnBelt() << endl << other.getOwnPants() << endl;
//	out << other.getOwnChest() << endl << other.getOwnRing() << endl;
//	out << other.getOwnGloves() << endl << other.getOwnShield() << endl;
//	out << other.getOwnBoots() << endl << other.getOwnWeapon() << endl;
//	return out;
//}

