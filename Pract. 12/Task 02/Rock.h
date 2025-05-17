#pragma once
#include "Player.h"

class Rock : public Player{

public:

	int playAgainst(const Player* player) const override;
	int playAgainstRock(const Rock* rock) const override;
	int playAgainstScissors(const Scissors* scissors) const override;
	int playAgainstPaper(const Paper* paper) const override;
};

