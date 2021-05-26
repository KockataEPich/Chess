#pragma once
#include "ChessPiece.h"
#include "Board.h"
class Queen : public ChessPiece
{

public:
	Queen();
	Queen(Square* position);
	std::vector<Square*> getLegalMoves(Board board);
};

