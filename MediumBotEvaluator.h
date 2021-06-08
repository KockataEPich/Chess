#pragma once
#include "Evaluator.h"
class MediumBotEvaluator : public Evaluator
{
private:
	int pawnPieceValue = 20;
	int rookPieceValue = 200;
	int knightPieceValue = 160;
	int bishopPieceValue = 180;
	int queenPieceValue = 400;
	int kingPieceValue = 10000;
public:
	int evaluateBoard(Board* board, PlayerSide pColor);
};

