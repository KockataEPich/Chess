#include "Move.h"


Move::Move(std::shared_ptr<Square> oldLocation, std::shared_ptr<Square> newLocation)
{
	this->oldLocation = oldLocation;
	this->newLocation = newLocation;
}

std::shared_ptr<Square> Move::getOldLocation()
{
	return oldLocation;
}

std::shared_ptr<Square> Move::getNewLocation()
{
	return newLocation;
}
