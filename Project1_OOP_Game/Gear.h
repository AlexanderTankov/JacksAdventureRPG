#pragma once
#include <iostream>
#include "Item.h"
#include "Head.h"
#include "Shoulders.h"
#include "Chest.h"
#include "Gloves.h"
#include "Boots.h"
#include "Belt.h"
#include "Pants.h"
#include "Ring.h"
#include "Shield.h"
#include "Weapon.h"

class Gear
{
public:
	Gear();
	~Gear();
	Gear(const Gear& other);
	Gear(Head newHead, Shoulders newShoulders, Chest newChest, Gloves newGloves, Boots newBoots,
		 Belt newBelt, Pants newPants, Ring newRing, Shield newShield, Weapon newWeapon);
	
	bool		operator == (const Gear& other);
	bool		operator != (const Gear& other);
	Gear&		operator = (const Gear& other);

	Head getOwnHead() const;
	Shoulders getOwnShoulders() const;
	Chest getOwnChest() const;
	Gloves getOwnGloves() const;
	Boots getOwnBoots() const;
	Belt getOwnBelt() const;
	Pants getOwnPants() const;
	Ring getOwnRing() const;
	Shield getOwnShield() const;
	Weapon getOwnWeapon() const;
	
	void setOwnHead(Head newHead);
	void setOwnShoulders(Shoulders newShoulders);
	void setOwnChest(Chest newChest);
	void setOwnGloves(Gloves newGloves);
	void setOwnBoots(Boots newBoots);
	void setOwnBelt(Belt newBelt);
	void setOwnPants(Pants newPants);
	void setOwnRing(Ring newRing);
	void setOwnShield(Shield newShield);
	void setOwnWeapon(Weapon newWeapon);

	//bool isValid() const;
	void printGear() const;
	std::ofstream& saveGear(std::ofstream& fout) const;
	void		  loadGear(std::ifstream& fin);

private:
	Head ownHead;
	Shoulders ownShoulders;
	Chest ownChest;
	Gloves ownGloves;
	Boots ownBoots;
	Belt ownBelt;
	Pants ownPants;
	Ring ownRing;
	Shield ownShield;
	Weapon ownWeapon;
};

//std::ostream& operator << (std::ostream& out, const Gear& other);