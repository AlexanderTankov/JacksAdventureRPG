#pragma once

#include "Map.h"

class Game
{
public:
	void			startGame();
	void			loadGame();

private:
	Map				MapInGame;
};