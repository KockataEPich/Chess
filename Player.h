#pragma once
#include <utility>
#include "Move.h"
#include "Board.h"
#include "PlayerEnum.h"

class Move;
class Board;

class Player
{
protected:
	PlayerSide color;
	// Strategy strategy

public:
	std::vector<std::shared_ptr<ChessPiece>> getPieces(Board* board);
	PlayerSide getColor();
	virtual Move getMove(Board* board) = 0;

};
