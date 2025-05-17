#pragma once
#include "Player.h"

class PlayerFactory{

public:
	PlayerFactory() = delete;

	static Player* createPlayer(char playerType);
};

