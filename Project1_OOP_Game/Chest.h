#pragma once
#include "Item.h"

class Chest : public Item
{
public:
	Chest() : Item() {}
	virtual ~Chest() {}
	Chest(const Chest& other) : Item(other) {}
	Chest(const Item* other)  : Item(*other) {}
	Chest(const char* Name, size_t Attack, size_t Defense,size_t Mana) : Item(Name,Attack,Defense,Mana) {}

	virtual	Item*		Clone() const { return new Chest(*this); }
	virtual Type		getTypeOfItem() const { return CHEST; }
	virtual void		print() const { Item::printItem(); }

};