#include "VeryHardBot.h"


//VeryHardBot::VeryHardBot(PlayerSide color, int depth, Evaluator* evaluator) {
//	this->color = color;
//	this->depth = depth;
//	this->evaluator = evaluator;
//}
//
//VeryHardBot::~VeryHardBot() {
//	delete(evaluator);
//}
//
//Move* VeryHardBot::getMove(Board* board) {
//	MinMaxAlphaBeta(board, color, 0, INT_MIN, INT_MAX);
//	return currentBestMove;
//}
//
//int VeryHardBot::MinMaxAlphaBeta(Board* board, PlayerSide pColor, int currentDepth, int alpha, int beta) {
//	if (currentDepth == depth)
//		return evaluator->evaluateBoard(board, color);
//
//	int bestBoardValue;
//
//	if (pColor == color)
//		bestBoardValue = INT_MIN;
//	else
//		bestBoardValue = INT_MAX;
//
//	shr_sqr bestInitMove = nullptr;
//	shr_sqr bestSecondMove = nullptr;
//
//
//	std::list<Move*> allMoves = getAllPlayerMoves(board, pColor);
//	//sqr_vec* movesWhoGetPieces = new sqr_vec();
//	for (auto &i : allMoves) {
//		Board* newBoard = new Board(board->getBoard());
//		newBoard->makeMove(i);
//
//		int currentBoardValue;
//
//		if (newBoard->isOver())
//			if (pColor == color)
//				currentBoardValue = INT_MAX;
//			else
//				currentBoardValue = INT_MIN;
//		else
//			currentBoardValue = MinMaxAlphaBeta(newBoard, pColor.getOpposite(),
//				currentDepth + 1, alpha, beta);
//
//		if (pColor == color && currentBoardValue > bestBoardValue ||
//			pColor != color && currentBoardValue < bestBoardValue) {
//			bestBoardValue = currentBoardValue;
//			bestInitMove = i->getOldLocation();;
//			bestSecondMove = i->getNewLocation();
//		}
//
//		if (pColor == color && bestBoardValue > alpha)
//			alpha = bestBoardValue;
//
//		if (pColor != color && bestBoardValue < beta)
//			beta = bestBoardValue;
//
//		// Stop the search if it is pointless
//		delete(newBoard);
//		if (alpha > beta)
//			break;
//	}
//
//	allMoves.clear();
//	
//	if (currentDepth == 0)
//		currentBestMove = new Move(bestInitMove, bestSecondMove, pColor);
//
//	return bestBoardValue;
//}
//
//std::list<Move*> VeryHardBot::getAllPlayerMoves(Board* board, PlayerSide pColor) {
//	piece_vec* myPieces = board->getPieceList(pColor);
//	std::list<Move*> allMoves;
//	for (int i = 0; i < myPieces->size(); i++) {
//		sqr_vec* legalMoves = myPieces->at(i)->getLegalMoves(board, pColor);
//		for (int j = 0; j < legalMoves->size(); j++) {
//			if (legalMoves->at(j)->getPiece() == nullptr)
//				allMoves.push_back(new Move(myPieces->at(i)->getPosition(), legalMoves->at(j), pColor));
//			else
//				allMoves.insert(allMoves.begin(), new Move(myPieces->at(i)->getPosition(), legalMoves->at(j), pColor));
//		}
//
//		delete(legalMoves);
//	}
//	delete(myPieces);
//
//	return allMoves;
//}