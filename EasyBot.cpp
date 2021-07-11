#include "EasyBot.h"
#include <iostream>
#include <fstream>
#include <random>

EasyBot::EasyBot(PlayerSide color)
{
	this->color = color;
}

Move EasyBot::getMove(Board& board){		
	//The input would be a on click input
	//piece_vec myPieces = board.getPieceList(color);
	//
	//for (int i = 0; i < myPieces.size(); i++)
	//{
	//	sqr_vec legalMoves = myPieces[i]->getLegalMoves(board, color);

	//	if (legalMoves.size() > 0) {
	//		Move randomMove(myPieces[i]->getPosition(), legalMoves[rand() % legalMoves.size()], color);
	//		return randomMove;
	//	}
	//}

	return Move(board(1, 0), board(2, 0), color);
}


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