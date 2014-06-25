#pragma once
#include "Item.h"

class Ring : public Item
{
public:
	Ring() : Item() {}
	virtual ~Ring() {}
	Ring(const Ring& other) : Item(other) {}
	Ring(const Item* other)  : Item(*other) {}
	Ring(const char* Name, size_t Attack, size_t Defense, size_t Mana) : Item(Name, Attack, Defense, Mana) {}

	virtual	Item*		Clone() const { return new Ring(*this); }
	virtual Type		getTypeOfItem() const { return RING; }
	virtual void		print() const { Item::printItem(); }

};