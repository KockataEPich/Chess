#pragma once
#include "Player.h"
#include "Evaluator.h"
#include "MediumBotEvaluator.h"


class HardBot : public Player{
private:
	Evaluator* evaluator; 
	int depth;
	Move* currentBestMove;

public:
	HardBot(PlayerSide color, int depth);
	~HardBot();
	Move* getMove(Board* board);
	int MinMaxAlphaBeta(Board* board, PlayerSide currentSide, int currentDepth, 
		int alpha, int beta);
};


