#pragma once
#include "ChessPiece.h"
#include "Board.h"
class Queen : public ChessPiece
{

public:
	Queen(Square position);
	virtual std::string getName();
	virtual Square getPosition();
	virtual std::vector<Square> getLegalMoves(Board board);
};

