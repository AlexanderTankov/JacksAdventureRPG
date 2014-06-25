#pragma once
#include "Item.h"

class Shield : public Item
{
public:
	Shield() : Item() {}
	virtual ~Shield() {}
	Shield(const Shield& other) : Item(other) {}
	Shield(const Item* other)  : Item(*other) {}
	Shield(const char* Name, size_t Attack, size_t Defense, size_t Mana) : Item(Name, Attack, Defense, Mana) {}

	virtual	Item*		Clone() const { return new Shield(*this); }
	virtual Type		getTypeOfItem() const { return SHIELD; }
	virtual void		print() const { Item::printItem(); }

};