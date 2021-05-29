#pragma once
#include <memory>
#include "ChessPiece.h"
#include "Square.h"

class ChessPiece;
class Square;

class Move
{
private:
	std::shared_ptr<Square> oldLocation;
	std::shared_ptr<Square> newLocation;
public:
	Move(std::shared_ptr<Square> oldLocation, std::shared_ptr<Square> newLocation);
	std::shared_ptr<Square> getOldLocation();
	std::shared_ptr<Square> getNewLocation();
};

