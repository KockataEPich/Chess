#include "Player.h"

void Player::setColor(PlayerSide color){
	this->color = color;
}

void Player::setPieces(std::vector<std::shared_ptr<ChessPiece>> pieces){
	this->pieces = pieces;
}

std::vector<std::shared_ptr<ChessPiece>> Player::getPieces() {
	return pieces;
}

PlayerSide Player::getColor() {
	return color;
}