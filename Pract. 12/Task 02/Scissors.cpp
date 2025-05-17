#include "Scissors.h"

int Scissors::playAgainst(const Player* player) const{
	return -(player->playAgainstScissors(this));
}

int Scissors::playAgainstPaper(const Paper* paper) const{
	return 1;
}

int Scissors::playAgainstRock(const Rock* rock) const{
	return -1;
}

int Scissors::playAgainstScissors(const Scissors* scissors) const{
	return 0;
}




