#include "Player.h"

std::vector<std::shared_ptr<ChessPiece>> Player::getPieces(Board* board) {
	return board->getPieceList(color);
}

PlayerSide Player::getColor() {
	return color;
}

std::shared_ptr<Square> Player::getFirstClicked() {
	return firstClickedSquare.lock();
}
void Player::setFirstClicked(std::shared_ptr<Square> square)
{
	firstClickedSquare = square;
}

std::shared_ptr<Square> Player::getSecondClickedSquare() {
	return secondClickedSquare.lock();
}

void Player::setSecondClickedSquare(std::shared_ptr<Square> square) {
	secondClickedSquare = square;
}

void Player::clearPoints()
{
	firstClickedSquare = std::weak_ptr<Square>();
	secondClickedSquare = std::weak_ptr<Square>();

}