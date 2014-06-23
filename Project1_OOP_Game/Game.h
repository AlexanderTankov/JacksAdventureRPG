#pragma once
#include <fstream>
#include "Hero.h"
#include "Item.h"
#include "Map.h"

class Game
{
public:
	void startGame();
	std::ostream& saveGame(std::ofstream& fout) const;
	void loadGame();

private:
	Hero	HeroInGame;
	Map		MapInGame;
};

void Game::startGame()
{
	system("cls");
	MapInGame.printMap();
	while (this->MapInGame.getOwnHero().getLife() != 0)
	{
		char move;
		cin >> move;
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
		default:
			break;
		}
	}
}

std::ostream& Game::saveGame(std::ofstream& fout) const
{
	HeroInGame.saveHero(fout);
	MapInGame.saveMap(fout);
	return fout;
}

void Game::loadGame()
{
	ifstream din("Load.txt", ios::out);
	if (!din)
	{
		cout << "The file is not open";
		return;
	}
	HeroInGame.loadHero(din);
	MapInGame.loadMap(din);
}