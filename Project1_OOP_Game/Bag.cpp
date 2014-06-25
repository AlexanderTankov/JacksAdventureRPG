#include <iostream>
#include "Bag.h"
#include "Belt.h"
#include "Boots.h"
#include "Chest.h"
#include "Gloves.h"
#include "Head.h"
#include "Pants.h"
#include "Ring.h"
#include "Shield.h"
#include "Shoulders.h"
#include "Weapon.h"

using namespace std;

//Constructor
Bag::Bag()
{
	this->capacity = 6;
	this->filledCells = 0;
	this->contentOfBag = new Item*[this->capacity];
	for (size_t i = 0; i < this->capacity; i++)
		this->contentOfBag[i] = new Head;
}

//Destructor
Bag::~Bag()
{
	clear();
}

//Constructor for copy one bag to other
Bag::Bag(const Bag& other)
{
	copyBag(other);
}


//Compares that two bags are equal(compare items in deck)
bool Bag::operator == (const Bag& other)
{
	if((this->capacity == other.getCapacity()) && (this->filledCells == other.getFilledCells()) && 
		(this->contentOfBag == other.getContentOfBag()))
		return true;
	else
		return false;
}

//Compares that two bags are not equal
bool Bag::operator != (const Bag& other)
{
	return !(*this == other);
}

//Equated all items in bag
Bag& Bag::operator = (const Bag& other)
{
	if(*this != other)
	{
		clear();
		copyBag(other);
	}
	return *this;
}

//This operator eturn item with this index in bag
Item* Bag::operator [] (const size_t idx)
{
	return this->contentOfBag[idx];
}



//Get capacity of bag
size_t Bag::getCapacity() const
{
	return this->capacity;
}

//Get filled cells
size_t Bag::getFilledCells() const
{
	return this->filledCells;
}

//Get content of bag
Item** Bag::getContentOfBag() const
{
	return this->contentOfBag;
}


//Set number of filled cells
void Bag::setFilledCells(const size_t newNumOfFilledCells)
{
	if(newNumOfFilledCells > 0)
		this->filledCells = newNumOfFilledCells;
	else
		cout << "Filled Cells in bag cant be less than 1!" << endl;
}

//Add item in bag
void Bag::addItemInBag(const Item* newItem)
{
	if (getFilledCells() == getCapacity())
		resizeBag(getCapacity() * 2);

	this->contentOfBag[getFilledCells()] = newItem->Clone();
	this->filledCells++;

}


//Resize bag with new capacity
void Bag::resizeBag(size_t newCapacity)
{
	if(newCapacity < this->filledCells)
		cout << " You delete all cards after this number" << endl;

	if(newCapacity == 0)
		clear();
	else
	{
		Item** pItems = new Item*[newCapacity];
		if(pItems)
		{
			for (size_t i = 0; i < this->filledCells ; i++)
				pItems[i] = this->contentOfBag[i];
			delete [] this->contentOfBag;
			this->contentOfBag = new Item*[newCapacity];
			this->contentOfBag = pItems;
			this->capacity = newCapacity;
		}
	}
}

//Copying data from bag
void Bag::copyBag(const Bag& other)
{
	this->capacity = other.getCapacity();
	this->filledCells = other.getFilledCells();
	this->contentOfBag = new Item*[this->capacity];
	for (size_t i = 0; i < this->filledCells; i++)
		this->contentOfBag[i] = other.getContentOfBag()[i];
}

//Clear memory
void Bag::clear()
{
	delete [] this->contentOfBag;
	this->contentOfBag = NULL;
}

//If capacity is more than 1 then bag is valid
bool Bag::isValid() const
{
	if(getFilledCells() > 0)
		return true;
	else
		return false;
}

//Print bag
void Bag::printBag() const
{
	cout << "Bag:" << endl;
	for (size_t i = 0; i < this->filledCells; i++)
	{
		this->contentOfBag[i]->printItem();
		cout << endl;
	}
}

//Save bag in flow
ofstream& Bag::saveBag(ofstream& fout) const
{
	if (isValid())
	{
		for (size_t i = 0; i < getFilledCells(); i++)
			this->contentOfBag[i]->saveItem(fout);
	}
	return fout;
}

//Load bag from flow
void loadBag(ifstream& fin)
{
	//ako ima neshto da loadva da go loadne
}
