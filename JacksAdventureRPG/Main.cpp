#include <iostream>
#include "Game.h"
#include "Hero.h"
#include "Monster.h"
#include "Gear.h"
#include "Item.h"
#include "Map.h"

using namespace std;

int main()
{
	Game GoodGame;
	size_t temp;
	cout << "1:New game.\n2:Load game.\n3:Tutorial.\n4:Exit" << endl;
	cout << "your solution is: ";
	cin >> temp;
	switch (temp)
	{
	case 1:
		GoodGame.startGame();
		break;
	case 2:
		GoodGame.loadGame();
		break;
	case 3:
		system("cls");
		cout << "d - moving right!\ns - moving down!\na - moving left!\nw - moving up!" << endl;
		GoodGame.startGame();
		break;
	case 4:
		return 0;
	default:
		break;
	}
	
	cout << "================ YOU DIEEE ===============" << endl;
	return 0;
}
