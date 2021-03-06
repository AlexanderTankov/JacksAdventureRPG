#pragma once
#include "Cell.h"
#include "Hero.h"

using namespace std;

class Map
{
public:
	Map();
	~Map();

	size_t			getRows() const;
	size_t			getColumns() const;
	size_t			getLevel() const;
	Cell***			getPpmap() const;
	Hero*			getOwnHero() const;
	Monster			getMonstersOnMap() const;
	Item*			getItemOnMap() const;

	void			setRows(size_t Rows);
	void			setColumns(size_t Columns);
	void			setLevel(size_t Level);
	void			setHero(Hero* ownHero);
	void			setMonster(Monster newMonster);
	void			setItem(const Item& newItem);
		
	std::ofstream&	saveMap(std::ofstream& fout) const;
	void			SaveWithHero();
	void			loadMap(ifstream& fin);
	void			PlayMap(size_t LevelOfMap);

	void			create();
	void			moveHero(int x, int y);
	void			moveHeroUp();
	void			moveHeroDown();
	void			moveHeroLeft();
	void			moveHeroRight();
	void			findHeroInMap();
	void			findMonsterInMap();
	void			findFirstPosition();

	void			printMap() const;
private:
	size_t			Rows;
	size_t			Columns;
	Cell***			ppMap;
	size_t			Level;
	Hero*			ownHero;	
	Monster			MonstersOnMap;
	Item*			ItemOnMap;
};