// Task 02.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

#include "Player.h"
#include "PlayerFactory.h"

int main()
{
    Player* scissors = PlayerFactory::createPlayer('s');
    Player* paper = PlayerFactory::createPlayer('p');
    Player* rock = PlayerFactory::createPlayer('r');

    std::cout << "Paper vs Scissors " << paper->playAgainst(scissors) << std::endl;
    std::cout << "Paper vs Paper " << paper->playAgainst(paper) << std::endl;
    std::cout << "Rock vs Scissors " << rock->playAgainst(scissors) << std::endl;


}

