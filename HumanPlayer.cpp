
#include "HumanPlayer.h"

HumanPlayer::HumanPlayer()
{
	//pieces = game.generateNewPieces

}

Move HumanPlayer::getMove(Board board)
{
	//The input would be a on click input
	return Move(board.getBoard()[1][0], board.getBoard()[2][0]);
}