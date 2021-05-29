#pragma once
#include <memory>
#include "ChessPiece.h"
#include "Square.h"

class ChessPiece;
class Square;

class Move
{
private:
	std::shared_ptr<ChessPiece> chessPiece;
	std::shared_ptr<Square> newLocation;
public:
	Move(std::shared_ptr<ChessPiece> chessPiece, std::shared_ptr<Square> newLocation);

};

