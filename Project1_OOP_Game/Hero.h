#pragma once
#include "Cell.h"
#include "BasicFeatures.h"
#include "Gear.h"
#include "Item.h"
#include "Monster.h"
#include "Bag.h"

class Hero : public BasicFeatures, public Cell
{
public:
	Hero();
	~Hero();
	Hero(const Hero& other);
	Hero(std::ifstream& fin);
	Hero(const char* Name, size_t Attack, size_t Defense, size_t MaxLife, size_t MaxMana, size_t Row, size_t Column);

	bool			operator == (const Hero& other);
	bool			operator != (const Hero& other);
	Hero&			operator = (const Hero& other);

	size_t			getLife() const;
	size_t			getMaxLife() const; 
	size_t			getMana() const;
	size_t			getMaxMana() const; 
	size_t			getExperience() const;
	size_t			getLevel() const;
	const Gear&		getGear() const;
	Gear&			getGearRef() { return this->gear; }
	const Bag&		getOwnBag() const;
	Bag&			getOwnBagRef() { return this->ownBag; }
	
	void			setLife(size_t Life);
	void			setMaxLife(size_t MaxLife); 
	void			setMana(size_t Mana);
	void			setMaxMana(size_t MaxMana);
	void			setExperience(size_t Experience);
	void			setLevel(size_t Level);
	void			setGear(const Gear& gear); 
	void			setOwnBag(const Bag& newOwnBag);

	void			addItemInBag(const Item* newItem);
	void			setItemToGearFromBag(Item* ItemForGear);

	size_t			reduceAttack(size_t Defense) const;
	void			removeHealth(size_t Attack);
	void			attackMonster(Monster& Monster);
	bool			isAlive() const;
	void			printHero() const;

	std::ostream&	saveHero(std::ofstream& fout) const;

private:
	size_t			Life;
	size_t			MaxLife; 
	size_t			Mana;
	size_t			MaxMana;
	size_t			Experience;
	size_t			Level;
	Gear			gear;
	Bag				ownBag;
};