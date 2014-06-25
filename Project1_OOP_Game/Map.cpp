#include <iostream>
#include <fstream>
#include "Map.h"

using namespace std;

//Constructor
Map::Map()
{
	this->ItemOnMap = new Head;
	PlayMap(1);
	char heroName[100];
	cout << "Enter name of your hero: " << endl;
	cin.getline(heroName,100, '\n');
	this->ownHero.setName(heroName);
	this->ownHero.setAttack(25);
	this->ownHero.setDefense(5);
	this->ownHero.setMaxLife(100);
	this->ownHero.setLife(100);
	this->ownHero.setMaxMana(50);
	this->ownHero.setMana(50);
}

//Constructor for copy one Map to other
Map::Map(const Map& other)
{
	this->Rows = other.getRows();
	this->Columns = other.getColumns();
	this->Level = other.getLevel();
	this->ppMap = new Cell** [other.getColumns()];
	for (size_t i = 0; i < other.getColumns(); i++)
	{
		this->ppMap[i] = new Cell* [other.getRows()];
		for (size_t j = 0; j < other.getRows(); j++)
			this->ppMap[i][j] = new Cell;
	}

	for (size_t i = 0; i < other.getColumns(); i++)
		for(size_t j = 0; j < other.getRows(); j++)
			this->ppMap[i][j] = other.ppMap[i][j];

	this->ownHero = other.getOwnHero();
	this->MonstersOnMap = other.getMonstersOnMap();
	this->ItemOnMap = other.getItemOnMap();
}

//Destructor
Map::~Map()
{
	for (size_t i = 0; i < this->Columns; i++)
	{
		for (size_t j = 0; j < this->Rows; j++)
		{
			delete this->ppMap[i][j];
			this->ppMap[i][j] = NULL;
		}
		delete [] this->ppMap[i];
		this->ppMap[i] = NULL;
	}

	delete [] this->ppMap;
	this->ppMap = NULL;

	delete this->ItemOnMap;
	this->ItemOnMap = NULL;
}



//Get map rows
size_t Map::getRows() const
{
	return this->Rows;
}

//Get map Columns
size_t Map::getColumns() const
{
	return this->Columns;
}

//Get map level
size_t Map::getLevel() const
{
	return this->Level;
}

//Get map
Cell*** Map::getPpmap() const
{
	return this->ppMap;
}

//Get map Hero
Hero Map::getOwnHero() const
{
	return this->ownHero;
}

//Get monsters on map
Monster Map::getMonstersOnMap() const
{
	return this->MonstersOnMap;
}

//Get items on map
Item* Map::getItemOnMap() const
{
	return this->ItemOnMap;
}



//Set rows to map
void Map::setRows(size_t Rows)
{
	if(Rows > 0)
		this->Rows = Rows;
	else
		cout << "Rows cant be less than 1!" << endl;
}

//Set columns to map
void Map::setColumns(size_t Columns)
{
	if(Columns > 0)
		this->Columns = Columns;
	else
		cout << "Columns cant be less than 1!" << endl;
}

//Set level to map
void Map::setLevel(size_t Level)
{
	if (Level > 0)
		this->Level = Level;
	else
		cout << "Level cant be less than 1!" << endl;
}

//Set hero to map
void Map::setHero(Hero ownHero)
{
	this->ownHero = ownHero;
}

//Set monster to map
void Map::setMonster(Monster newMonster)
{
	this->MonstersOnMap = newMonster;
}

//Set item to map
void Map::setItem(Item* newItem)
{
	this->ItemOnMap = newItem;
}


//Save map without hero
ostream& Map::saveMap(ofstream& fout) const
{
	fout << getRows() << endl;
	fout << getColumns() << endl;

	for (size_t i = 0; i < this->Columns; i++)
	{
		for (size_t j = 0; j < this->Rows; j++)
		{
			fout << ((char)((int)this->ppMap[i][j]->getSymbol() + 128));
		}
		if (i != this->Columns - 1)
			fout << endl;
	}

	this->MonstersOnMap.saveMonster(fout);
	this->ItemOnMap->saveItem(fout);
	return fout;
}

//Save map with hero
void Map::SaveWithHero()
{
	ofstream Save("Load.txt");
	if (!Save)
	{
		cout << "The file is not open";
		//da hvurlq excep
	}
	saveMap(Save);
	this->ownHero.saveHero(Save);
}

//Load map from flow
void Map::loadMap(ifstream& fin)
{
	fin >> this->Rows;
	fin >> this->Columns;
	create();

	char** temp = new char* [this->Rows];
	for (size_t p = 0; p < this->Columns; p++)
		temp[p] = new char [this->Rows];

	for (size_t p = 0; p < this->Columns; p++)
		for(size_t k=0; k< this->Rows; k++)
			fin >> temp[p][k];
	
	for (size_t i = 0; i < this->Columns; i++)
	{
		for (size_t j = 0; j < this->Rows; j++)
		{
			this->ppMap[i][j]->setRow(i);
			this->ppMap[i][j]->setColumn(j);
			this->ppMap[i][j]->setSymbol((char)((int)temp[i][j] + 128));
		}
	}

	this->MonstersOnMap.loadMonster(fin);
	this->ItemOnMap->loadItem(fin);
}

//Load and prepare any map to be ready to play 
void Map::PlayMap(size_t LevelOfMap)
{
	this->Level = LevelOfMap;
	char MomentMap[10] = "Map00.txt";
	if (LevelOfMap < 10)
	{
		(char)MomentMap[4] = (char)(LevelOfMap + 48);
	}
	else
	{
		(char)MomentMap[4] = (char)((LevelOfMap % 10) + 48);
		(char)MomentMap[3] = (char)((LevelOfMap / 10 % 10) + 48);
	}
	ifstream din(MomentMap, ios::out);
	if (!din)
	{
		cout << "The file is not open";
		return;
	}
	setHero(getOwnHero());
	setItem(getItemOnMap());
	loadMap(din);
	findHeroInMap();
	findMonsterInMap();
}


//Memory allocation
void Map::create()
{
	this->ppMap = new Cell** [this->Columns];
	for (size_t i = 0; i < this->Columns; i++)
	{
		this->ppMap[i] = new Cell* [this->Rows];
		for (size_t j = 0; j < this->Rows; j++)
			this->ppMap[i][j] = new Cell;
	}

}

//Moving hero
void Map::moveHero(int x, int y)
{
	int curX = this->ownHero.getRow();
	int curY = this->ownHero.getColumn();
	int newX = curX + x;
	int newY = curY + y;
	switch ((char)((int)(this->ppMap[newX][newY]->getSymbol()) - 128))
	{
	case '0':
		cout << " Cant move hero there!" << endl;
		break;
	case '2':
		Cell* temp;
		temp = this->ppMap[curX][curY];
		this->ppMap[curX][curY] = this->ppMap[newX][newY];
		this->ppMap[newX][newY] = temp;

		this->ownHero.setRow(newX);
		this->ownHero.setColumn(newY);
		system("cls");
		printMap();
		break;
	case 'j':
		system("cls");
		printMap();
		this->ownHero.attackMonster(MonstersOnMap);
		if (this->MonstersOnMap.getLife() == 0)
		{
			this->ppMap[curX][curY]->setSymbol(char(int('2') + 128));
			this->ppMap[newX][newY]->setSymbol((char)173);

			this->ownHero.setRow(newX);
			this->ownHero.setColumn(newY);
			system("cls");
			printMap();
			cout << "You get " << MonstersOnMap.getExperience() << "xp." << endl;
		}
		break;
	case 'm':
		SaveWithHero();
		system("cls");
		printMap();
		cout << "Your game was saved! :)" << endl;
		break;
	case 'p':
		this->ownHero.addItemInBag(getItemOnMap());
		this->ppMap[curX][curY]->setSymbol(char(int('2') + 128));
		this->ppMap[newX][newY]->setSymbol((char)173);

		this->ownHero.setRow(newX);
		this->ownHero.setColumn(newY);
		system("cls");
		printMap();
		cout << "You get new item!" << getItemOnMap() << endl;
		break;
	case ']':
		this->Level++;
		PlayMap(getLevel());
		system("cls");
		printMap();
		break;
	default:
		break;
	}
}

//Moving hero up
void Map::moveHeroUp()
{
	moveHero(-1, 0);
}

//Moving hero down
void Map::moveHeroDown()
{
	moveHero(1, 0);
}

//Moving hero left
void Map::moveHeroLeft()
{
	moveHero(0, -1);
}

//Moving hero right
void Map::moveHeroRight()
{
	moveHero(0, 1);
}


//Find hero in map and save hero position
void Map::findHeroInMap()
{
	for (size_t i = 0; i < this->Columns; i++)
	{
		for(size_t j = 0; j < this->Rows; j++)
		{
			if (this->ppMap[i][j]->getSymbol() == (char)173)
			{
				this->ownHero.setRow(i);
				this->ownHero.setColumn(j);
				return;
			}
		}
	}
}

//Find monster in map and save monster position
void Map::findMonsterInMap()
{
	for (size_t i = 0; i < this->Columns; i++)
	{
		for(size_t j = 0; j < this->Rows; j++)
		{
			if(this->ppMap[i][j]->getSymbol() == 'j')
			{
				this->MonstersOnMap.setRow(i);
				this->MonstersOnMap.setColumn(j);
				return;
			}
		}
	}
}


//Set hero to 1st free cell on map
void Map::findFirstPosition()
{
	for (size_t i = 0; i < this->Columns; i++)
	{
		for(size_t j = 0; j < this->Rows; j++)
		{
			if(this->ppMap[i][j]->getSymbol() == (char)((int)'2' + 128))
			{
				this->ownHero.setRow(i);
				this->ownHero.setColumn(j);
				this->ppMap[i][j]->setSymbol((char)148);
				return;
			}
		}
	}
}


//Print map
void Map::printMap() const
{
	//cout << "==================== New Map ===========================" << endl;
	for (size_t i = 0; i < this->Columns; i++)
	{
		for(size_t j = 0; j < this->Rows; j++)
			this->ppMap[i][j]->printCell();
		cout << endl;
	}
	this->ownHero.printHero();
}
