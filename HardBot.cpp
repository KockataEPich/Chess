#include "HardBot.h"

HardBot::HardBot(PlayerSide color) { 
	this->color = color; 
	this->depth = 2;
}

Move* HardBot::getMove(Board* board) {
	MinMaxAlphaBeta(board, color, depth, INT_MIN, INT_MAX);
	return currentBestMove;
}
	
int HardBot::MinMaxAlphaBeta(Board* board, PlayerSide pColor, int currentDepth,
	int givenAlpha, int givenBeta)
{
	
	if (currentDepth == 0)
		return evaluator->evaluateBoard(board, color);

	//The input would be a on click input
	piece_vec* myPieces = board->getPieceList(pColor);

	int bestBoardValue;
	
	if(pColor == color)
		bestBoardValue = INT_MIN;
	else
		bestBoardValue = INT_MAX;

	int alpha = givenAlpha;
	int beta = givenBeta;

	//Move* bestMove = nullptr;
	shr_sqr bestInitMove = nullptr;
	shr_sqr bestSecondMove = nullptr;

	for (int i = 0; i < myPieces->size(); i++)
	{
		sqr_vec* legalMoves = myPieces->at(i)->getLegalMoves(board, pColor);
		for (int j = 0; j < legalMoves->size(); j++) {

			Board* newBoard = new Board(board->getBoard());

			Move* move = new Move(
				(*newBoard)(myPieces->at(i)->getPosition()->getX(),
					myPieces->at(i)->getPosition()->getY()),
				(*newBoard)(legalMoves->at(j)->getX(),
					legalMoves->at(j)->getY()), pColor);

			newBoard->makeMove(move);

			int currentBoardValue = MinMaxAlphaBeta(newBoard, pColor.getOpposite(), currentDepth - 1,
				alpha, beta);

			//evaluator->evaluateBoard(newBoard, color);

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
	if (currentDepth == depth)
		currentBestMove = new Move(bestInitMove, bestSecondMove, pColor);

	return bestBoardValue;
}

