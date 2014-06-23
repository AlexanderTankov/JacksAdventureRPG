#pragma once
#include "Item.h"

class Boots : public Item
{
public:
	Boots() : Item() {}
	virtual ~Boots() {}
	Boots(const Boots& other) : Item(other) {}
	Boots(const Item* other) : Item(*other) {} 
	Boots(const char* Name, size_t Attack, size_t Defense, size_t Mana) : Item(Name, Attack, Defense, Mana) {}

	virtual	Item*		Clone() const { return new Boots(*this); }
	virtual Type		getTypeOfItem() const { return BOOTS; }
	virtual void		print() const { Item::printItem(); }

};

//std::ostream& operator << (std::ostream& out, const Boots& other) { other.printInFlow(out); return out; }