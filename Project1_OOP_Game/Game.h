#pragma once
#include <fstream>
#include "Hero.h"
#include "Item.h"
#include "Map.h"

class Game
{
public:
	void			startGame();
	std::ostream&	saveGame() const;
	void			loadGame();

private:
	Hero			HeroInGame;
	Map				MapInGame;
};