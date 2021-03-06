#include <iostream>
#include "BasicFeatures.h"
#include "Hero.h"
#include "Cell.h"

using namespace std;

//Constructor
Hero::Hero() : BasicFeatures(), Cell((char)178)
{
	this->MaxLife = 100;
	this->Life = 100;
	this->MaxMana = 100;
	this->Mana = 100;
	this->Experience = 0;
	this->Level = 0;
}

//Load hero from flow
Hero::Hero(std::ifstream& fin)
{
	loadBasicFeatures(fin);
	loadCell(fin);
	size_t hLife, hMaxLife, hExperience, hMana, hMaxMana, hLevel;
	fin >> hLife >> hMaxLife >> hMana >> hMaxMana >> hExperience >> hLevel;
	setMaxLife(hMaxLife);
	setLife(hLife);
	setMaxMana(hMaxMana);
	setMana(hMana);
	setExperience(hExperience);
	setLevel(hLevel);
	this->gear.loadGear(fin);
	this->ownBag.loadBag(fin);
}

//Destructor
Hero::~Hero()
{
}

//Constructor for copy one hero to other
Hero::Hero(const Hero& other) : BasicFeatures(other) , Cell(other)
{
	this->MaxLife = other.getMaxLife();
	this->Life = other.getLife();
	this->MaxMana = other.getMaxMana();
	this->Mana = other.getMana();
	this->Experience = other.getExperience();
	this->Level = other.getLevel();
	this->gear = other.getGear();
	this->ownBag = other.getOwnBag();
}

//Constructor for easy creating a hero
Hero::Hero(const char* Name, size_t Attack, size_t Defense, size_t MaxLife, size_t MaxMana, size_t Row, size_t Column) 
	: BasicFeatures(Name, Attack, Defense) , Cell(Row, Column, '@')
{
	this->Life = MaxLife;
	this->MaxLife = MaxLife;
	this->MaxMana = MaxMana;
	this->Mana = this->MaxMana;
	this->Experience = 0;
	this->Level = 0;
}


//Compares that two heroes are equal
bool Hero::operator == (const Hero& other)
{
	if((Cell::operator==(other)) && (BasicFeatures::operator==(other)) && (this->Life == other.getLife()) && (this->MaxLife == other.getMaxLife()) &&
	(this->Mana == other.getMana()) && (this->MaxMana == other.getMaxMana()) && (this->Experience == other.getExperience()) &&
	(this->Level == other.getLevel()) && (this->gear == other.getGear()) && (this->ownBag == other.getOwnBag()))
		return true;
	else
		return false;
}

//Compares that two heroes are not equal
bool Hero::operator != (const Hero& other)
{
	return !(*this == other);
}

//Equated two heroes
Hero& Hero::operator = (const Hero& other)
{
	if(*this != other)
	{
		BasicFeatures::operator=(other);
		Cell::operator=(other);
		this->MaxLife = other.getMaxLife();
		this->Life = other.getLife();
		this->MaxMana = other.getMaxMana();
		this->Mana = other.getMana();
		this->Experience = other.getExperience();
		this->Level = other.getLevel();
		this->gear = other.getGear();
		this->ownBag = other.getOwnBag();
	}
	return *this;
}


//Get Hero life
size_t Hero::getLife() const
{
	return this->Life;
}

//Get Hero maximum life
size_t Hero::getMaxLife() const
{
	return this->MaxLife;
}

//Get Hero mana
size_t Hero::getMana() const
{
	return this->Mana;
}

//Get Hero maximum mana
size_t Hero::getMaxMana() const
{
	return this->MaxMana;
}

//Get Hero experience
size_t Hero::getExperience() const
{
	return this->Experience;
}

//Get Hero level
size_t Hero::getLevel() const
{
	return this->Level;
}

//Get Hero gear
const Gear& Hero::getGear() const
{
	return this->gear;
}

//Geto Hero bag
const Bag& Hero::getOwnBag() const
{
	return this->ownBag;
}


//Set life to Hero
void Hero::setLife(size_t Life)
{
	if(Life >= 0 && Life <= MaxLife)
		this->Life =  Life;
	else 
		cout << "Life of hero cant be less than 1" << endl;
}

//Set maximum life to Hero
void Hero::setMaxLife(size_t MaxLife)
{
	if (MaxLife > 0)
	{
		this->MaxLife =  MaxLife;
	}
	else 
		cout << "Maximum life of hero cant be less than 1" << endl;
}

//Set Mana to Hero
void Hero::setMana(size_t Mana)
{
	if(Mana > 0 && Mana <= this->MaxMana)
		this->Mana = Mana;
	else 
		cout << "Mana of hero cant be less than 1" << endl;
}

//Set Mana to Hero
void Hero::setMaxMana(size_t MaxMana)
{
	if (MaxMana > 0)
	{
		this->MaxMana = MaxMana;
	}
	else 
		cout << "Maximum mana of hero cant be less than 1" << endl;
}

//Set Experience to Hero
void Hero::setExperience(size_t Experience)
{
	if(Experience < 100 && Experience >= 0)
		this->Experience = Experience;
	else
		cout << "Every 100 XP = 1 level and because of that this Hero cant have more than 100 XP and less than 0" << endl;
}

//Set Level to Hero
void Hero::setLevel(size_t Level)
{
	if(Level >= 0)
		this->Level = Level;
	else 
		cout << "Level cant be less than 0" << endl;
}

//Set Gear to Hero
void Hero::setGear(const Gear& gear)
{
	if (gear.GearIsValid())
		this->gear = gear;
	else
		cout << "This gear is not valid!" << endl;
}

//Set Bag to Hero
void Hero::setOwnBag(const Bag& newOwnBag)
{
	if(newOwnBag.isValid())
		this->ownBag = newOwnBag;
	else
		cout << "Dont have bag to set!" << endl;
}


//Adding item in bag
void Hero::addItemInBag(const Item* newItem)
{
	this->ownBag.addItemInBag(newItem);
}



//Add Item to gear from bag
void Hero::setItemToGearFromBag(Item* ItemForGear)
{
	this->gear.setItemInGear(ItemForGear);
	setAttack(getAttack() + ItemForGear->getAttack());
	setDefense(getDefense() + ItemForGear->getDefense());
	setMaxMana(getMaxMana() + ItemForGear->getMana());
}



//Defense reduce attack for battle (1 def ~ 2% att)
size_t Hero::reduceAttack(size_t Defense) const
{
	size_t Attack = getAttack();
	Attack -= ((Defense*2.0)/100.0)*(double)getAttack();
	return Attack;
}

//Remove Health from hero (use in battle and every 10 attack = -1 hp)
void Hero::removeHealth(size_t Attack)
{
	if(getLife() > Attack)
		setLife(getLife() - Attack);
	else
		setLife(0);
}

//When hero attack Monster
void Hero::attackMonster(Monster& monster)
{
	size_t timeHeroAttack = reduceAttack(monster.getDefense());
	size_t timeMonsAttack = monster.reduceAttack(getDefense());

	if(timeHeroAttack > monster.getAttack())
	{
		monster.removeHealth(timeHeroAttack);
		removeHealth(getAttack()/10);
		monster.printMonster();
		cout << endl << "vs" << endl << endl;
		printHero();
		cout << endl;
		cout << "Hero hit monster and get " << getAttack()/10 << " health from monster life!" << endl;
		cout << "Hero life: " << getLife() << "	Monster life:" << monster.getLife() << endl; 
	}
	else if(timeHeroAttack == monster.getAttack())
	{
		removeHealth(timeHeroAttack);
		monster.removeHealth(monster.getAttack());
		monster.printMonster();
		cout << endl << "vs" << endl << endl;
		printHero();
		cout << endl;
		cout << "Monster attack and hero time attack is equal and get from hero " <<  timeHeroAttack << " hp and from monster " 
			<< monster.getAttack() << "hp!" << endl;
		cout << "Hero life: " << getLife() << "	Monster life:" << monster.getLife() << endl;
	}
	else
	{
		removeHealth(timeMonsAttack);
		monster.removeHealth(getAttack() / 10);
		monster.printMonster();
		cout << endl << "vs" << endl << endl;
		printHero();
		cout << endl;
		cout << "Monster hit hero and get " << timeMonsAttack << " health from hero life!" << endl;
		cout << "Hero life: " << getLife() << "	Monster life:" << monster.getLife() << endl;
	}

	if(monster.getLife() == 0)
		{
			this->Experience += monster.getExperience();
			if(this->Experience >= 100)
			{
				this->Level++;
				setDefense(getDefense() + 1);
				setAttack(getAttack() + 30);
				this->MaxLife += 20;
				setLife(this->MaxLife);
				this->MaxMana += 10;
				this->Mana = this->MaxMana;
				this->Experience -= 100;
				cout << "Level up! Defence + 1, Attack + 30 , Maximum life + 20, Maximum mana + 10" << endl;
			}
		}
}

//Check that hero is alive
bool Hero::isAlive() const
{
	if(getLife() == 0)
		return false;
	else
		return true;
}

//Print Hero
void Hero::printHero() const
{
	BasicFeatures::printBasicFeatures();
	cout << "Life: " << getLife() << "/" << getMaxLife() << endl;
	cout << "Mana: " << getMana() << "/" << getMaxMana() << endl;
	cout << "Level(Experiance): " << getLevel() << "(" << getExperience() << ")" << endl;
}

//Save hero in flow
ostream& Hero::saveHero(ofstream& fout) const
{
	saveBasicFeatures(fout);
	saveCell(fout);
	fout << getLife() << endl << getMaxLife() << endl << getMana() << endl
		<< getMaxMana() << endl << getExperience() << endl << getLevel();
	this->gear.saveGear(fout);
	this->ownBag.saveBag(fout);
	return fout;
}