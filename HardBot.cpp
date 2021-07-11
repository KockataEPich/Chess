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
	MinMaxAlphaBeta(color, 0, INT_MIN, INT_MAX);
	return currentBestMove;
}
	
int HardBot::MinMaxAlphaBeta(PlayerSide pColor, int currentDepth, int alpha, int beta){
	if (currentDepth == depth)
		return evaluator->evaluateBoard(board, color);

	//The input would be a on click input
	piece_vec myPieces = board.getPieceList(pColor);
	int bestBoardValue;
	
	if(pColor == color)
		bestBoardValue = INT_MIN;
	else
		bestBoardValue = INT_MAX;

	shr_sqr bestInitMove = nullptr;
	shr_sqr bestSecondMove = nullptr;

	for (int i = 0; i < myPieces.size(); i++){
		sqr_vec legalMoves = myPieces[i]->getLegalMoves(board, pColor);
		for (int j = 0; j < legalMoves.size(); j++) {
			
			shr_sqr start_sqr = myPieces[i]->getPosition();
			shr_sqr end_sqr = legalMoves.at(j);

			Move move(
				board(start_sqr->getX(), start_sqr->getY()),
				board(end_sqr->getX(), end_sqr->getY()), pColor);

			board.makeMove(move);

			int currentBoardValue;

			if (board.isOver())
				if (pColor == color)
					currentBoardValue = INT_MAX;
				else
					currentBoardValue = INT_MIN;
			else 
				currentBoardValue = MinMaxAlphaBeta(pColor.getOpposite(),
					currentDepth + 1, alpha, beta);

			if (pColor == color && currentBoardValue > bestBoardValue ||
				pColor != color && currentBoardValue < bestBoardValue) {
				bestBoardValue = currentBoardValue;
				bestInitMove = start_sqr;
				bestSecondMove = end_sqr;
			}

			if (pColor == color && bestBoardValue > alpha)
				alpha = bestBoardValue;

			if (pColor != color && bestBoardValue < beta)
				beta = bestBoardValue;

			board.unmakeMove(move);
			// Stop the search if it is pointless
			if (alpha > beta) 
				break;
		}
		if (alpha > beta)
			break;
	}
	
	if (currentDepth == 0)
		currentBestMove = Move(bestInitMove, bestSecondMove, pColor);

	return bestBoardValue;
}

