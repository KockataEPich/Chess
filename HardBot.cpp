#include "HardBot.h"

HardBot::HardBot(PlayerSide color) { 
	this->color = color; 
	this->depth = 2;
}

Move* HardBot::getMove(Board* board) {
	MinMaxAlphaBeta(board, color, depth);
	return currentBestMove;
}
	
int HardBot::MinMaxAlphaBeta(Board* board, PlayerSide pColor, int currentDepth)
{
	if (depth == 0)
		return evaluator->evaluateBoard(board, color);

	//The input would be a on click input
	piece_vec myPieces = board->getPieceList(pColor);

	int bestBoardValue;
	
	if(pColor == color)
		bestBoardValue = INT_MIN;
	else
		bestBoardValue = INT_MAX;

	//Move* bestMove = nullptr;
	shr_sqr bestInitMove = nullptr;
	shr_sqr bestSecondMove = nullptr;

	for (int i = 0; i < myPieces.size(); i++)
	{
		sqr_vec* legalMoves = myPieces[i]->getLegalMoves(board, pColor);
		for (int j = 0; j < legalMoves->size(); j++) {

			Board* newBoard = new Board(board->getBoard());

			Move* move = new Move(
				newBoard->getBoard()[myPieces[i]->getPosition()->getX()]
				[myPieces[i]->getPosition()->getY()],
				newBoard->getBoard()[legalMoves->at(j)->getX()]
				[legalMoves->at(j)->getY()], color);

			newBoard->makeMove(move);

			int currentBoardValue = MinMaxAlphaBeta(newBoard, pColor.getOpposite(), --depth);
				
				//evaluator->evaluateBoard(newBoard, color);

			if (pColor == color && currentBoardValue > bestBoardValue){
				bestBoardValue = currentBoardValue;
				bestInitMove = myPieces[i]->getPosition();
				bestSecondMove = legalMoves->at(j);
			}

			if (pColor != color && currentBoardValue < bestBoardValue) {
				bestBoardValue = currentBoardValue;
				bestInitMove = myPieces[i]->getPosition();
				bestSecondMove = legalMoves->at(j);
			}
			delete(newBoard);
			delete(move);
		}
	}
	if (currentDepth == depth)
		currentBestMove = new Move(bestInitMove, bestSecondMove, pColor);

	return bestBoardValue;
}

