
#include "HumanPlayer.h"

HumanPlayer::HumanPlayer()
{
	//pieces = game.generateNewPieces

}

std::pair<char, int> HumanPlayer::getMove()
{
	return std::make_pair('a', 5);
}