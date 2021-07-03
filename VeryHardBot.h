#pragma once
#include "Player.h"
#include "Evaluator.h"
#include <list>


class VeryHardBot : public Player {
private:
	Evaluator* evaluator;
	int depth;
	Move* currentBestMove;

public:
	VeryHardBot(PlayerSide color, int depth, Evaluator* evaluator);
	~VeryHardBot();
	Move* getMove(Board* board);
	int MinMaxAlphaBeta(Board* board, PlayerSide currentSide, int currentDepth,
		int alpha, int beta);
	std::list<Move*> getAllPlayerMoves(Board* board, PlayerSide pColor);
};


