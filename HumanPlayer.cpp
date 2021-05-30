
#include "HumanPlayer.h"

HumanPlayer::HumanPlayer(PlayerSide color)
{
	this->color = color;
}

Move HumanPlayer::getMove(Board *board)
{
	
	return Move(getFirstClicked(), getSecondClickedSquare(), color);
}


std::shared_ptr<Square> HumanPlayer::getFirstClicked() {
	return firstClickedSquare.lock();
}
void HumanPlayer::setFirstClicked(std::shared_ptr<Square> square)
{
	firstClickedSquare = square;
}

std::shared_ptr<Square> HumanPlayer::getSecondClickedSquare(){
	return secondClickedSquare.lock();
}

void HumanPlayer::setSecondClickedSquare(std::shared_ptr<Square> square) {
	secondClickedSquare = square;
}

void HumanPlayer::clearPoints()
{
	firstClickedSquare = std::weak_ptr<Square>();
	secondClickedSquare = std::weak_ptr<Square>();

}