#include "HardBot.h"

HardBot::HardBot(PlayerSide color, int depth) { 
	this->color = color; 
	this->depth = depth;
	evaluator = new MediumBotEvaluator();
}

HardBot::~HardBot() {
	delete(evaluator);
}

Move* HardBot::getMove(Board* board) {
	MinMaxAlphaBeta(board, color, 0, INT_MIN, INT_MAX);
	return currentBestMove;
}
	
int HardBot::MinMaxAlphaBeta(Board* board, PlayerSide pColor, int currentDepth, int alpha, int beta){
	if (currentDepth == depth)
		return evaluator->evaluateBoard(board, color);

	//The input would be a on click input
	piece_vec* myPieces = board->getPieceList(pColor);
	int bestBoardValue;
	
	if(pColor == color)
		bestBoardValue = INT_MIN;
	else
		bestBoardValue = INT_MAX;

	shr_sqr bestInitMove = nullptr;
	shr_sqr bestSecondMove = nullptr;

	for (int i = 0; i < myPieces->size(); i++){
		sqr_vec* legalMoves = myPieces->at(i)->getLegalMoves(board, pColor);
		for (int j = 0; j < legalMoves->size(); j++) {
			Board* newBoard = new Board(board->getBoard());

			shr_sqr start_sqr = myPieces->at(i)->getPosition();
			shr_sqr end_sqr = legalMoves->at(j);

			Move* move = new Move(
				(*newBoard)(start_sqr->getX(), start_sqr->getY()),
				(*newBoard)(end_sqr->getX(), end_sqr->getY()), pColor);

			newBoard->makeMove(move);

			int currentBoardValue;

			if (newBoard->isOver())
				if (pColor == color)
					currentBoardValue = INT_MAX;
				else
					currentBoardValue = INT_MIN;
			else 
				currentBoardValue = MinMaxAlphaBeta(newBoard, pColor.getOpposite(),
					currentDepth + 1, alpha, beta);

			if (pColor == color && currentBoardValue > bestBoardValue ||
				pColor != color && currentBoardValue < bestBoardValue) {
				bestBoardValue = currentBoardValue;
				bestInitMove = myPieces->at(i)->getPosition();
				bestSecondMove = legalMoves->at(j);
			}

			if (pColor == color && bestBoardValue > alpha)
				alpha = bestBoardValue;

			if (pColor != color && bestBoardValue < beta)
				beta = bestBoardValue;

			// Stop the search if it is pointless
			if (alpha > beta) {
				delete(newBoard);
				delete(move);
				break;
			}
			delete(newBoard);
			delete(move);
		}
		if (alpha > beta) {
			delete(legalMoves);
			break;
		}
		delete(legalMoves);
	}
	if (currentDepth == 0)
		currentBestMove = new Move(bestInitMove, bestSecondMove, pColor);

	return bestBoardValue;
}

