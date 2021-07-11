#pragma once
#include "Player.h"
#include "Evaluator.h"
#include "MediumBotEvaluator.h"


class HardBot : public Player{
private:
	Evaluator* evaluator; 
	int depth;
	Move currentBestMove;
	Board board;

public:
	HardBot(PlayerSide color, int depth, Evaluator* evaluator, Board& board);
	~HardBot();
	Move getMove(Board& board);
	int MinMaxAlphaBeta(PlayerSide currentSide, int currentDepth, int alpha, int beta);
};


