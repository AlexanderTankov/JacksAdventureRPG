#pragma once
#include "Item.h"

class Shoulders : public Item
{
public:
	Shoulders() : Item() {}
	virtual ~Shoulders() {}
	Shoulders(const Shoulders& other) : Item(other) {}
	Shoulders(const Item* other)  : Item(*other) {}
	Shoulders(const char* Name, size_t Attack, size_t Defense, size_t Mana) : Item(Name, Attack, Defense, Mana) {}

	virtual	Item*		Clone() const { return new Shoulders(*this); }
	virtual Type		getTypeOfItem() const { return SHOULDERS; }
	virtual void		print() const { Item::printItem(); }

};

//std::ostream& operator << (std::ostream& out, const Shoulders& other) { other.printInFlow(out); return out; }