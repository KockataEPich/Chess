#include "Player.h"

std::vector<std::shared_ptr<ChessPiece>> Player::getPieces(Board* board) {
	return board->getPieceList(color);
}

PlayerSide Player::getColor() {
	return color;
}