#pragma once
#include "Board.h"
#include "PlayerEnum.h"


class Evaluator
{
public:
	virtual int evaluateBoard(Board* board, PlayerSide side) = 0;
};

