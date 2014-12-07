#pragma once
#include "Item.h"

class Head : public Item
{
public:
	Head() : Item() {}
	virtual ~Head() {}
	Head(const Head& other) : Item(other) {}
	Head(const Item* other)  : Item(*other) {}
	Head(const char* Name, size_t Attack, size_t Defense, size_t Mana) : Item(Name, Attack, Defense, Mana) {}

	virtual	Head*		Clone() const { return new Head(*this); }
	virtual TypeOfItems		getTypeOfItem() const { return HEAD; }
	virtual void		print() const { Item::printItem(); }

	virtual size_t		updateLife(size_t MaxLife) override{ return MaxLife + 30; }
};