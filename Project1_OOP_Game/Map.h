#pragma once
#include "Cell.h"
#include "Hero.h"

using namespace std;

class Map
{
public:
	Map();
	//Map(size_t LevelOfMap);
	~Map();
	Map(const Map& other);
	//Map(size_t rows, size_t columns, size_t level, const Cell*** ppmap, Hero ownHero);

	size_t		getRows() const;
	size_t		getColumns() const;
	size_t		getLevel() const;
	Cell***		getPpmap() const;
	Hero		getOwnHero() const;
	Monster		getMonstersOnMap() const;
	Item*		getItemOnMap() const;

	void		setRows(size_t Rows);
	void		setColumns(size_t Columns);
	void		setLevel(size_t Level);
	void		setHero(Hero ownHero);
	void		setMonster(Monster newMonster);
	void		setItem(Item* newItem); // zashto mi dava greshka kato ima const DA RAZBERA
		
	std::ostream& saveMap(std::ofstream& fout) const;
	void		  loadMap(ifstream& fin);

	void		create();
	void		moveHeroUp();
	void		moveHeroDown();
	void		moveHeroLeft();
	void		moveHeroRight();// << "Do you want to set this item in your gear(Y\N)?";
	void		findHeroInMap();
	void		findMonsterInMap();
	void		findFirstPosition();

	void		printMap() const;
	void		PlayMap(size_t LevelOfMap);

private:
	size_t		Rows;
	size_t		Columns;
	Cell***		ppMap;
	size_t		Level;
	Hero		ownHero;	
	Monster		MonstersOnMap;
	Item*		ItemOnMap;
};