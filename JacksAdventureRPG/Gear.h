#pragma once
#include <iostream>
#include "Item.h"
#include "Head.h"
#include "Boots.h"
#include "Ring.h"
#include "Shield.h"
#include "Weapon.h"

class Gear
{
public:
	Gear();
	~Gear();
	Gear(const Gear& other);
	Gear(Head* , Boots* , Ring* , Shield* , Weapon* );

	bool			operator == (const Gear& other);
	bool			operator != (const Gear& other);
	Gear&			operator = (const Gear& other);

	Item*			getOwnItem(TypeOfItems) const;
	void			setItemInGear(Item* ItemForEquip);

	bool			GearIsValid() const;
	void			printGear() const;
	std::ofstream&	saveGear(std::ofstream& fout) const;
	void			loadGear(std::ifstream& fin);

private:
	Item*			ownHead;
	Item*			ownBoots;
	Item*			ownRing;
	Item*			ownShield;
	Item*			ownWeapon;
};