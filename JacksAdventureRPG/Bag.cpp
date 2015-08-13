#include <iostream>
#include <fstream>
#include "Bag.h"
#include "Boots.h"
#include "Head.h"
#include "Ring.h"
#include "Shield.h"
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
	if(newNumOfFilledCells >= 0)
		this->filledCells = newNumOfFilledCells;
	else
		cout << "Filled Cells in bag cant be less than 0!" << endl;
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
		Item** pItems;
		try
		{
			pItems = new Item*[newCapacity];
		}
		catch (bad_alloc)
		{
			cout << "Not enough memory!" << endl;
		}

		for (size_t i = 0; i < this->filledCells ; i++)
			pItems[i] = this->contentOfBag[i];
		delete [] this->contentOfBag;
		try
		{
			this->contentOfBag = new Item*[newCapacity];
		}
		catch (bad_alloc)
		{
			cout << "Not enough memory!" << endl;
		}
		this->contentOfBag = pItems;
		delete[] pItems;
		pItems = NULL;
		this->capacity = newCapacity;
	}
}

//Copying data from bag
void Bag::copyBag(const Bag& other)
{
	this->capacity = other.getCapacity();
	this->filledCells = other.getFilledCells();
	try
	{
		this->contentOfBag = new Item*[this->capacity];
	}
	catch (bad_alloc)
	{
		cout << "No enough memory!" << endl;
	}
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
	}
}

//Save bag in flow
ofstream& Bag::saveBag(ofstream& fout) const
{
	fout << getFilledCells() << endl;
	if (isValid())
	{
		for (size_t i = 0; i < getFilledCells(); i++)
		{
			fout << int(this->contentOfBag[i]->getTypeOfItem());
			this->contentOfBag[i]->saveItem(fout);
			fout << endl;
		}
	}
	return fout;
}

//Load bag from flow
void Bag::loadBag(ifstream& fin)
{
	size_t filledCellsCount;
	int typeOfItem = -1;
	Item* temp = NULL;

	fin >> filledCellsCount;
	for (size_t i = 0; i < filledCellsCount; i++)
	{
		fin >> typeOfItem;
		switch (TypeOfItems(typeOfItem))
		{

		case BOOTS:
			temp = new Boots();
			break;
		case HEAD:
			temp = new Head();
			break;
		case RING:
			temp = new Ring();
			break;
		case SHIELD:
			temp = new Shield();
			break;
		case WEAPON:
			temp = new Weapon();
			break;
		default:
			cout << "This is some strange of item that i suggest you place in a special place!" << endl;
			break;
		}
		temp->loadItem(fin);
		addItemInBag(temp);
		typeOfItem = -1;
		temp = NULL;
	}
}

Item* Bag::pullOutItem(size_t pos)
{
	Item* temp;
	temp = this->contentOfBag[pos]->Clone();
	for (size_t i = pos; i < getFilledCells() - 1; i++)
		this->contentOfBag[pos] = this->contentOfBag[pos + 1];
	this->contentOfBag[getFilledCells() - 1] = NULL;
	setFilledCells(getFilledCells() - 1);
	return temp;
}