#include <iostream>
#include <fstream>
#include "Map.h"

using namespace std;

//Constructor
//Map::Map()
//{
//	this->Rows = 1;
//	this->Columns = 1;
//	this->Level = 1;
//	create();
//	this->ItemOnMap = new Head;
//}

Map::Map()//size_t LevelOfMap)
{
	this->ItemOnMap = new Head;
	PlayMap(1);//LevelOfMap);
	char heroName[100];
	cout << "Enter name of your hero: " << endl;
	cin >> heroName;
	this->ownHero.setName(heroName);
	this->ownHero.setAttack(25);
	this->ownHero.setDefense(5);
	this->ownHero.setMaxLife(100);
	this->ownHero.setMaxMana(50);
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

////Constructor for easy creating a Map
//Map::Map(size_t rows, size_t columns, size_t level,  const Cell*** ppmap, Hero ownHero)
//{
//	if(rows > 0 && columns > 0)
//	{
//		this->Rows = rows;
//		this->Columns = columns;
//		this->Level = level;
//		this->ppMap = new Cell** [columns];
//		for (size_t i = 0; i < columns; i++)
//		{
//			this->ppMap[i] = new Cell* [rows];
//			for (size_t j = 0; j < rows; j++)
//				this->ppMap[i][j] = new Cell;
//		}
//
//		for (size_t i = 0; i < columns; i++)
//			for(size_t j = 0; j < rows; j++)
//				this->ppMap[i][j] = getPpmap()[i][j];
//
//		this->ownHero = ownHero;
//	}
//	else
//		cout << "Rows and columns cant be less than 1!" << endl;
//}

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


ostream& Map::saveMap(ofstream& fout) const
{
	fout << getRows() << endl;
	fout << getColumns() << endl;

	for (size_t i = 0; i < this->Columns; i++)
	{
		for (size_t j = 0; j < this->Rows; j++)
		{
				fout << this->ppMap[i][j]->getSymbol();
		}
		fout << endl;
	}

	MonstersOnMap.saveMonster(fout);
	ItemOnMap->saveItem(fout);
	return fout;
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
			this->ppMap[i][j]->setSymbol(temp[i][j]);
		}
	}

	this->MonstersOnMap.loadMonster(fin);
	this->ItemOnMap->loadItem(fin);
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

//Moving hero up
void Map::moveHeroUp()
{
	switch (this->ppMap[this->ownHero.getRow() - 1][this->ownHero.getColumn()]->getSymbol())
	{
	case '#':
		cout << " Cant move hero there!" << endl;
		break;
	case '/':
		Cell* temp;
		temp = this->ppMap[this->ownHero.getRow()][this->ownHero.getColumn()]; 
		this->ppMap[this->ownHero.getRow()][this->ownHero.getColumn()] = this->ppMap[this->ownHero.getRow() - 1][this->ownHero.getColumn()];
		this->ppMap[this->ownHero.getRow() - 1][this->ownHero.getColumn()] = temp;

		this->ownHero.setRow(this->ownHero.getRow() - 1);
		system("cls");
		printMap();
		break;
	case '%':
		system("cls");
		printMap();
		this->ownHero.attackMonster(MonstersOnMap);
		if (this->MonstersOnMap.getLife() == 0)
		{
			this->ppMap[this->ownHero.getRow()][this->ownHero.getColumn()]->setSymbol('/');
			this->ppMap[this->ownHero.getRow() - 1][this->ownHero.getColumn()]->setSymbol('@');

			this->ownHero.setRow(this->ownHero.getRow() - 1);
			system("cls");
			printMap();
			cout << "You get " << MonstersOnMap.getExperience() << "xp." << endl;
		}
		break;
	case '&':
		system("cls");
		printMap();
		cout << "Your game was saved! :)" << endl;
		break;
	case '$':
		this->ownHero.addItemInBag(getItemOnMap());
		this->ppMap[this->ownHero.getRow()][this->ownHero.getColumn()]->setSymbol('/');
		this->ppMap[this->ownHero.getRow() - 1][this->ownHero.getColumn()]->setSymbol('@');
		
		this->ownHero.setRow(this->ownHero.getRow() - 1);
		system("cls");
		printMap();
		cout << "You get new item!" << getItemOnMap() << endl;
		break;
	case '!':
		this->Level++;
		PlayMap(getLevel());
		system("cls");
		printMap();
		break;
	default:
		break;
	}
}

//Moving hero down
void Map::moveHeroDown()
{
	switch (this->ppMap[this->ownHero.getRow() + 1][this->ownHero.getColumn()]->getSymbol())
	{
	case '#':
		cout << " Cant move hero there!" << endl;
		break;
	case '/':
		Cell* temp;
		temp = this->ppMap[this->ownHero.getRow()][this->ownHero.getColumn()]; 
		this->ppMap[this->ownHero.getRow()][this->ownHero.getColumn()] = this->ppMap[this->ownHero.getRow() + 1][this->ownHero.getColumn()];
		this->ppMap[this->ownHero.getRow() + 1][this->ownHero.getColumn()] = temp;

		this->ownHero.setRow(this->ownHero.getRow() + 1);
		system("cls");
		printMap();
		break;
	case '%':
		system("cls");
		printMap();
		this->ownHero.attackMonster(MonstersOnMap);
		if (this->MonstersOnMap.getLife() == 0)
		{
			this->ppMap[this->ownHero.getRow()][this->ownHero.getColumn()]->setSymbol('/');
			this->ppMap[this->ownHero.getRow() + 1][this->ownHero.getColumn()]->setSymbol('@');

			this->ownHero.setRow(this->ownHero.getRow() + 1);
			system("cls");
			printMap();
			cout << "You get " << MonstersOnMap.getExperience() << "xp." << endl;
		}
		break;
	case '&':
		//save game
		system("cls");
		printMap();
		cout << "Your game was saved! :)" << endl;
		break;
	case '$':
		this->ownHero.addItemInBag(getItemOnMap());
		this->ppMap[this->ownHero.getRow()][this->ownHero.getColumn()]->setSymbol('/');
		this->ppMap[this->ownHero.getRow() + 1][this->ownHero.getColumn()]->setSymbol('@');
		
		this->ownHero.setRow(this->ownHero.getRow() + 1);
		system("cls");
		printMap();
		cout << "You get new item!" << getItemOnMap() << endl;
		break;
	case '!':
		this->Level++;
		PlayMap(getLevel());
		system("cls");
		printMap();
		break;
	default:
		break;
	}
}

//Moving hero left
void Map::moveHeroLeft()
{
	switch (this->ppMap[this->ownHero.getRow()][this->ownHero.getColumn() - 1]->getSymbol())
	{
	case '#':
		cout << " Cant move hero there!" << endl;
		break;
	case '/':
		Cell* temp;
		temp = this->ppMap[this->ownHero.getRow()][this->ownHero.getColumn()]; 
		this->ppMap[this->ownHero.getRow()][this->ownHero.getColumn()] = this->ppMap[this->ownHero.getRow()][this->ownHero.getColumn() - 1];
		this->ppMap[this->ownHero.getRow()][this->ownHero.getColumn() - 1] = temp;

		this->ownHero.setColumn(this->ownHero.getColumn() - 1);
		system("cls");
		printMap();
		break;
	case '%':
		system("cls");
		printMap();
		this->ownHero.attackMonster(MonstersOnMap);
		if (this->MonstersOnMap.getLife() == 0)
		{
			this->ppMap[this->ownHero.getRow()][this->ownHero.getColumn()]->setSymbol('/');
			this->ppMap[this->ownHero.getRow()][this->ownHero.getColumn() - 1]->setSymbol('@');

			this->ownHero.setColumn(this->ownHero.getColumn() - 1);
			system("cls");
			printMap();
			cout << "You get " << MonstersOnMap.getExperience() << "xp." << endl;
		}
		break;
	case '&':
		//save game
		system("cls");
		printMap();
		cout << "Your game was saved! :)" << endl;
		break;
	case '$':
		this->ownHero.addItemInBag(getItemOnMap());
		this->ppMap[this->ownHero.getRow()][this->ownHero.getColumn()]->setSymbol('/');
		this->ppMap[this->ownHero.getRow()][this->ownHero.getColumn() - 1]->setSymbol('@');
		
		this->ownHero.setColumn(this->ownHero.getColumn() - 1);
		system("cls");
		printMap();
		cout << "You get new item!" << getItemOnMap() << endl;
		break;
	case '!':
		this->Level++;
		PlayMap(getLevel());
		system("cls");
		printMap();
		break;
	default:
		break;
	}
}

//Moving hero right
void Map::moveHeroRight()
{
	switch (this->ppMap[this->ownHero.getRow()][this->ownHero.getColumn() + 1]->getSymbol())
	{
	case '#':
		cout << " Cant move hero there!" << endl;
		break;
	case '/':
		Cell* temp;
		temp = this->ppMap[this->ownHero.getRow()][this->ownHero.getColumn()]; 
		this->ppMap[this->ownHero.getRow()][this->ownHero.getColumn()] = this->ppMap[this->ownHero.getRow()][this->ownHero.getColumn() + 1];
		this->ppMap[this->ownHero.getRow()][this->ownHero.getColumn() + 1] = temp;

		this->ownHero.setColumn(this->ownHero.getColumn()+ 1);
		system("cls");
		printMap();
		break;
	case '%':
		system("cls");
		printMap();
		this->ownHero.attackMonster(MonstersOnMap);
		if (this->MonstersOnMap.getLife() == 0)
		{
			this->ppMap[this->ownHero.getRow()][this->ownHero.getColumn()]->setSymbol('/');
			this->ppMap[this->ownHero.getRow()][this->ownHero.getColumn() + 1]->setSymbol('@');

			this->ownHero.setColumn(this->ownHero.getColumn() + 1);
			system("cls");
			printMap();
			cout << "You get " << MonstersOnMap.getExperience() << "xp." << endl;
		}
		break;
	case '&':
		//save game
		system("cls");
		printMap();
		cout << "Your game was saved! :)" << endl;
		break;
	case '$':
		this->ownHero.addItemInBag(getItemOnMap());
		this->ppMap[this->ownHero.getRow()][this->ownHero.getColumn()]->setSymbol('/');
		this->ppMap[this->ownHero.getRow()][this->ownHero.getColumn() + 1]->setSymbol('@');
		
		this->ownHero.setColumn(this->ownHero.getColumn()+ 1);
		system("cls");
		printMap();
		cout << "You get new item! " << endl;
		break;
	case '!':
		this->Level++;
		PlayMap(getLevel());
		system("cls");
		printMap();
		break;
	default:
		break;
	}
}


//Find hero in map and save hero position
void Map::findHeroInMap()
{
	for (size_t i = 0; i < this->Columns; i++)
	{
		for(size_t j = 0; j < this->Rows; j++)
		{
			if(this->ppMap[i][j]->getSymbol() == '@')
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
			if(this->ppMap[i][j]->getSymbol() == '%')
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
			if(this->ppMap[i][j]->getSymbol() == '/')
			{
				this->ownHero.setRow(i);
				this->ownHero.setColumn(j);
				this->ppMap[i][j]->setSymbol('@');
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
	findFirstPosition();
	findMonsterInMap();
}
