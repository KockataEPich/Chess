#include "Move.h"
Move::Move(std::shared_ptr<Square> oldLocation, std::shared_ptr<Square> newLocation, PlayerSide side) {
	this->oldLocation = oldLocation;
	this->newLocation = newLocation;
	this->side = side;
}

Move::~Move() {
	newLocation = std::weak_ptr<Square>();
	oldLocation = std::weak_ptr<Square>();
}

std::shared_ptr<Square> Move::getOldLocation() { return oldLocation.lock(); }
std::shared_ptr<Square> Move::getNewLocation() { return newLocation.lock(); }
PlayerSide Move::getSide() { return side; }
void Move::set_captured_piece(std::shared_ptr<ChessPiece> piece) { captured_piece = piece; }
std::shared_ptr<ChessPiece> Move::get_captured_piece() { return captured_piece; }
void Move::setCastleUpTrue() {}
bool Move::isCastleUp() { return castle_up; }