#pragma once

class Paper;
class Scissors;
class Rock;

class Player{
public:

	virtual int playAgainst(const Player* player) const = 0;
	virtual int playAgainstPaper(const Paper* paper) const = 0;
	virtual int playAgainstRock(const Rock* rock) const = 0;
	virtual int playAgainstScissors(const Scissors* scissors) const = 0;

	virtual ~Player() = default;
};

