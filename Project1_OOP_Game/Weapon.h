#pragma once
#include "Item.h"

class Weapon : public Item
{
public:
	Weapon() : Item() {}
	virtual ~Weapon() {}
	Weapon(const Weapon& other) : Item(other) {}
	Weapon(const Item* other)  : Item(*other) {}
	Weapon(const char* Name, size_t Attack, size_t Defense, size_t Mana) : Item(Name, Attack, Defense, Mana) {}

	virtual	Item*		Clone() const { return new Weapon(*this); }
	virtual Type		getTypeOfItem() const { return WEAPON; }
	virtual void		print() const { Item::printItem(); }

};

//std::ostream& operator << (std::ostream& out, const Weapon& other) { other.printInFlow(out); return out; }