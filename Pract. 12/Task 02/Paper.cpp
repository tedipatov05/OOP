
#include "Paper.h"

int Paper::playAgainst(const Player* player) const{
	return -(player->playAgainstPaper(this));
}

int Paper::playAgainstPaper(const Paper* paper) const{
	return 0;
}

int Paper::playAgainstRock(const Rock* rock) const{
	return 1;
}

int Paper::playAgainstScissors(const Scissors* scissors) const{
	return -1;
}





