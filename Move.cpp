#include "Move.h"


Move::Move(std::shared_ptr<Square> oldLocation, std::shared_ptr<Square> newLocation, PlayerSide side)
{

	this->oldLocation = oldLocation;

	this->newLocation = newLocation;

	this->side = side;



}

std::shared_ptr<Square> Move::getOldLocation()
{
	return oldLocation;
}

std::shared_ptr<Square> Move::getNewLocation()
{
	return newLocation;
}

PlayerSide Move::getSide() {
	return side;
}
