#include "HardBot.h"
#include "HardEvaluator.h"

HardBot::HardBot(PlayerSide color, int depth, Evaluator* evaluator, Board& board) {
	this->color = color; 
	this->depth = depth;
	this->evaluator = evaluator;
	this->board = board;
}

HardBot::~HardBot() {
	delete(evaluator);
}

Move HardBot::getMove(Board& board) {
	this->board = board;
	MinMaxAlphaBeta(color, 0, INT_MIN + 5, INT_MAX - 5);
	return currentBestMove;
}
	
int HardBot::MinMaxAlphaBeta(PlayerSide pColor, int currentDepth, int alpha, int beta){
	if (currentDepth == depth)
		return evaluator->evaluateBoard(board, pColor);

	move_vec all_legal_moves = board.getAllLegalMovesForPlayer(pColor);
	Move bestMoveSoFar;

	for (auto& move : all_legal_moves){
			board.makeMove(move);
			int currentBoardValue = -MinMaxAlphaBeta(pColor.getOpposite(),
				currentDepth + 1, -beta, -alpha);;
			board.unmakeMove(move);

			if (currentBoardValue >= beta)
				return beta;

			if (alpha < currentBoardValue) {
				alpha = currentBoardValue;
				bestMoveSoFar = move;
			}
	}
	
	if (currentDepth == 0)
		currentBestMove = bestMoveSoFar;

	return alpha;
}

