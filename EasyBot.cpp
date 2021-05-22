#include "EasyBot.h"


EasyBot::EasyBot()
{
	//pieces = game.generateNewPieces
}

std::pair<char, int> EasyBot::getMove()
{		
	return generateBestMove();
}


std::pair<char, int> EasyBot::generateBestMove()
{
	return std::make_pair('e', 8);
}