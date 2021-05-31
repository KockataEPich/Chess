#pragma once
#include <memory>
#include "ChessPiece.h"
#include "Square.h"
#include "PlayerEnum.h"

class ChessPiece;
class Square;

class Move
{
private:
	std::weak_ptr<Square> oldLocation;
	std::weak_ptr<Square> newLocation;
	PlayerSide side;
public:
	Move(std::shared_ptr<Square> oldLocation, std::shared_ptr<Square> newLocation, PlayerSide side);
	~Move();
	std::shared_ptr<Square> getOldLocation();
	std::shared_ptr<Square> getNewLocation();
	PlayerSide getSide();
};

