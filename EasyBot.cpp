#include "EasyBot.h"


EasyBot::EasyBot()
{
	//pieces = game.generateNewPieces
}

Move EasyBot::getMove(Board* board)
{		
	return Move(board->getBoard()[1][0], board->getBoard()[2][0]);
}
