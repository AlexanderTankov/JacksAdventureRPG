#pragma once
#include "BasicFeatures.h"

enum TypeOfItems
{
	BOOTS = 0,
	HEAD,
	RING,
	SHIELD,
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
	virtual TypeOfItems	getTypeOfItem() const = 0;
	virtual void		print() const = 0;

	size_t				getMana() const;
	void				setMana(size_t Mana);

	virtual size_t		updateMana(size_t MaxMana) { return MaxMana; }
	virtual size_t		updateLife(size_t MaxLife) { return MaxLife; }
	virtual size_t		updateAttack(size_t Attack) { return Attack; }
	virtual size_t		updateDefense(size_t Defense) { return Defense; }
	virtual size_t		updateExperience(size_t Experience) { return Experience; }


	void				printItem() const;
	void				loadItem(std::ifstream& fin);
	std::ostream&		saveItem(std::ofstream& out) const;
	Item&				returnNUllItem();
	bool				ItemIsValid() const;

private:
	size_t				Mana;
};