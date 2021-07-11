#include "MediumBot.h"
#include <iostream>
#include <fstream>
#include <random>

//MediumBot::MediumBot(PlayerSide color)	{ this->color = color;	}
//MediumBot::~MediumBot()					{ delete(evaluator);	}

//Move* MediumBot::getMove(Board* board) {
//	//The input would be a on click input
//	piece_vec* myPieces = board->getPieceList(color);
//
//	int bestBoardValue = INT_MIN;
//	//Move* bestMove = nullptr;
//	shr_sqr bestInitMove = nullptr;
//	shr_sqr bestSecondMove = nullptr;
//
//
//	for (int i = 0; i < myPieces->size(); i++)
//	{
//		sqr_vec* legalMoves = myPieces->at(i)->getLegalMoves(board, color);
//		for(int j = 0; j < legalMoves->size(); j++) {
//
//			Board* newBoard = new Board(board->getBoard());
//
//			Move* move = new Move(
//				(*newBoard)(myPieces->at(i)->getPosition()->getX(),
//					myPieces->at(i)->getPosition()->getY()),
//				(*newBoard)(legalMoves->at(j)->getX(),
//					legalMoves->at(j)->getY()), color);
//
//			newBoard->makeMove(move);
//
//			int currentBoardValue = evaluator->evaluateBoard(newBoard, color);
//
//			if (currentBoardValue > bestBoardValue)
//			{
//				bestBoardValue = currentBoardValue;
//				bestInitMove = myPieces->at(i)->getPosition();
//				bestSecondMove = legalMoves->at(j);
//			}
//			delete(newBoard);
//			delete(move);
//		}
//		delete(legalMoves);
//	}
//	return new Move(bestInitMove, bestSecondMove, color);
//	//return new Move(board->getBoard()[1][0], board->getBoard()[2][0], color);
//}




//print to file

//std::ofstream myfile;
//myfile.open("example.txt");
//myfile << myPieces.size();
//myfile.close();


// SKELETON FOR ALPHA BETA MIN MAX
	// EvaluationStrategy.evaluate(board, color);
//	for (auto& i : myPieces) {
		//for (auto& j : i->getLegalMoves(board, color)) {
		//	Move move = Move(i->getPosition(), j, color);
			//Board* newBoard = board->duplicateBoard();
			//evaluate = newBoard->makeMove(move);

			//if (evaluate > currentMax)
			//	bestMove = currentBestMove;
		//}

	//}

	//return currentBestMove