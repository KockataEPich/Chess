#pragma once
#include "Player.h"
#include "Evaluator.h"
#include "MediumBotEvaluator.h"


class HardBot : public Player{
private:
	Evaluator* evaluator = new MediumBotEvaluator();
	int depth;
	Move* currentBestMove;

public:
	HardBot(PlayerSide color);
	Move* getMove(Board* board);
	int MinMaxAlphaBeta(Board* board, PlayerSide currentSide, int currentDepth);
};


