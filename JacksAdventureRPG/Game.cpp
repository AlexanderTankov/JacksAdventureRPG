#include <iostream>
#include <fstream>
#include <conio.h>
#include "Game.h"
#include "Hero.h"

//Starting game
void Game::startGame()
{
	system("cls");
	MapInGame.printMap();
	while (this->MapInGame.getOwnHero()->getLife() != 0)
	{
		char move;
		move = getch();
		switch (move)
		{
		case 'a':
			this->MapInGame.moveHeroLeft();
			break;
		case 'w':
			this->MapInGame.moveHeroUp();
			break;
		case 's':
			this->MapInGame.moveHeroDown();
			break;
		case 'd':
			this->MapInGame.moveHeroRight();
			break;
		case 'c':
			system("cls");
			this->MapInGame.getOwnHero()->printHero();
			this->MapInGame.getOwnHero()->getGear().printGear();
			break;
		case 'b':
			system("cls");
			if (this->MapInGame.getOwnHero()->getOwnBag().isValid())
			{
				this->MapInGame.getOwnHero()->getOwnBag().printBag();
				cout << "If you want to equip any item click 'Y' or 'N': ";
				char tempChar;
				cin >> tempChar;
				if (tempChar == 'Y' || tempChar == 'y')
				{
					cout << "Enter position of item in your bag: ";
					int temp;
					cin >> temp;
					if ((temp - 1) >= 0 && (temp - 1) < this->MapInGame.getOwnHero()->getOwnBagRef().getFilledCells())
						this->MapInGame.getOwnHero()->setItemToGearFromBag
						(this->MapInGame.getOwnHero()->getOwnBagRef().pullOutItem(temp - 1));
					else
						cout << "You dont have Item with this number!" << endl;
				}
			}
			break;
		default:
			break;
		}
	}
}

//Load game from flow
void Game::loadGame()
{
	ifstream fin("Load.txt");
	if (!fin)
	{
		cout << "The file is not open";
		return;
	}
	size_t MapLevel;
	fin >> MapLevel;
	MapInGame.setLevel(MapLevel);
	MapInGame.loadMap(fin);
	MapInGame.setHero(new Hero(fin));

	startGame();
}