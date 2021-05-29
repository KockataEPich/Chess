#pragma once
#include "ChessPiece.h"
#include "Board.h"

class Queen : public ChessPiece
{

public:
	Queen(std::shared_ptr<Square> position, PlayerSide playerSide);
	std::vector<std::shared_ptr<Square>> getLegalMoves(Board board, PlayerSide currentPlayerColor);
};

