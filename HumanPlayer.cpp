
#include "HumanPlayer.h"

HumanPlayer::HumanPlayer(PlayerSide color)
{
	this->color = color;
}

Move HumanPlayer::getMove(Board *board)
{
	
	return Move(board->getBoard()[1][0], board->getBoard()[2][0], color);
}