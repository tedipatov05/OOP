#pragma once
#include "Player.h"

class Paper : public Player{
public:

	int playAgainst(const Player* player) const override;
	int playAgainstPaper(const Paper* paper) const override;
	int playAgainstRock(const Rock* rock) const override;
	int playAgainstScissors(const Scissors* scissors) const override;

};

