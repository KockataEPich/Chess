#pragma once
#include <utility>
#include "Move.h"
#include "Board.h"
class Player
{
public:
	virtual Move getMove(Board board) = 0;

private:
	//virtual Piece pieces*;
};

