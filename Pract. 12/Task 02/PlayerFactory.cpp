
#include "PlayerFactory.h"

#include "Paper.h"
#include "Rock.h"
#include "Scissors.h"

Player* PlayerFactory::createPlayer(char playerType) {
	switch (playerType) {
		case 'r':
			return new Rock();
			break;
		case 's':
			return new Scissors();
			break;
		case 'p':
			return new Paper();
			break;
		default:
			return nullptr;
	}
}

