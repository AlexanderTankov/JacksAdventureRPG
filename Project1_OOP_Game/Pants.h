#pragma once
#include "Item.h"

class Pants : public Item
{
public:
	Pants() : Item() {}
	virtual ~Pants() {}
	Pants(const Pants& other) : Item(other) {}
	Pants(const Item* other)  : Item(*other) {}
	Pants(const char* Name, size_t Attack, size_t Defense, size_t Mana) : Item(Name, Attack, Defense, Mana) {}

	virtual	Item*		Clone() const { return new Pants(*this); }
	virtual Type		getTypeOfItem() const { return PANTS; }
	virtual void		print() const { Item::printItem(); }

};

//std::ostream& operator << (std::ostream& out, const Pants& other) { other.printInFlow(out); return out; }