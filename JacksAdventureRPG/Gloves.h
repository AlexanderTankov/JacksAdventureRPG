#pragma once
#include "Item.h"

class Gloves : public Item
{
public:
	Gloves() : Item() {}
	virtual ~Gloves() {}
	Gloves(const Gloves& other) : Item(other) {}
	Gloves(const Item* other)  : Item(*other) {}
	Gloves(const char* Name, size_t Attack, size_t Defense,size_t Mana) : Item(Name,Attack,Defense,Mana) {}

	virtual	Item*		Clone() const { return new Gloves(*this); }
	virtual Type		getTypeOfItem() const { return GLOVES; }
	virtual void		print() const { Item::printItem(); }

};