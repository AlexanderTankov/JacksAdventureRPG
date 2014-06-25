#include <iostream>
#include "Game.h"

//Starting game
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

//Save game in flow
std::ostream& Game::saveGame() const
{
	ofstream Save("Load.txt");
	if (!Save)
	{
		cout << "The file is not open";
		//da hvurlq excep
	}
	MapInGame.saveMap(Save);
	HeroInGame.saveHero(Save);
	return Save;
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
	MapInGame.loadMap(fin);
	HeroInGame.loadHero(fin);
	MapInGame.setHero(HeroInGame);

	startGame();
}