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

	virtual	Weapon*			Clone() const { return new Weapon(*this); }
	virtual TypeOfItems		getTypeOfItem() const { return WEAPON; }
	virtual void			print() const { Item::printItem(); }

	virtual size_t		updateAttack(size_t Attack) override{ return Attack + 10; }
};