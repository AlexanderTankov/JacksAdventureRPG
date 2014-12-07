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

	virtual	Shield*		Clone() const { return new Shield(*this); }
	virtual TypeOfItems		getTypeOfItem() const { return SHIELD; }
	virtual void		print() const { Item::printItem(); }

	virtual size_t		updateDefense(size_t Defense) override{ return Defense + 10; }
};