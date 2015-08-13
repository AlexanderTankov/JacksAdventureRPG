#pragma once
#include "Item.h"

class Belt : public Item
{
public:
	Belt() : Item() {}
	virtual ~Belt() {}
	Belt(const Belt& other) : Item(other) {}
	Belt(const Item* other) : Item(*other) {}
	Belt(const char* Name, size_t Attack, size_t Defense, size_t Mana) : Item(Name, Attack, Defense, Mana) {}

	virtual	Item*		Clone() const { return new Belt(*this); }
	virtual Type		getTypeOfItem() const { return BELT; }
	virtual void		print() const { Item::printItem(); }

};
