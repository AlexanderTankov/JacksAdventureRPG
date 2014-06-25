#pragma once
#include "BasicFeatures.h"

enum Type
{
	BELT,
	BOOTS,
	CHEST,
	GLOVES,
	HEAD,
	PANTS,
	RING,
	SHIELD,
	SHOULDERS,
	WEAPON
};

class Item : public BasicFeatures
{
public:
	Item();
	virtual ~Item();
	Item(const Item& other);
	Item(const char* Name, size_t Attack, size_t Defense,size_t Mana);

	Item& operator = (const Item& other);
	bool operator == (const Item& other);
	bool operator != (const Item& other);
	
	virtual	Item*		Clone() const = 0;
	virtual Type		getTypeOfItem() const = 0;
	virtual void		print() const = 0;

	size_t				getMana() const;
	void				setMana(size_t Mana);

	void				printItem() const;
	void				loadItem(std::ifstream& fin);
	std::ostream&		saveItem(std::ofstream& out) const;

private:
	size_t				Mana;
};