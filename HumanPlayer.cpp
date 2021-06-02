
#include "HumanPlayer.h"

HumanPlayer::HumanPlayer(PlayerSide color)
{
	this->color = color;
}

Move* HumanPlayer::getMove(Board *board)
{
	
	return new Move(getFirstClicked(), getSecondClickedSquare(), color);
}
