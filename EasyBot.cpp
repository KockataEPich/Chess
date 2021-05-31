#include "EasyBot.h"
#include <iostream>
#include <fstream>
#include <random>

EasyBot::EasyBot(PlayerSide color)
{
	this->color = color;
}

Move EasyBot::getMove(Board* board){		
	//The input would be a on click input
	std::vector<std::shared_ptr<ChessPiece>> myPieces = board->getPieceList(color);

	std::ofstream myfile;
	myfile.open("example.txt");
	myfile << myPieces.size();
	myfile.close();
	
	for (int i = 0; i < myPieces.size(); i++)
	{
		std::vector<std::shared_ptr<Square>>* legalMoves = myPieces[i]->getLegalMoves(board, color);

		if (legalMoves->size() > 0) {
			Move randomMove(myPieces[i]->getPosition(), legalMoves->at(rand() % legalMoves->size()), color);
			delete(legalMoves);
			return randomMove;
		}
	}

	//for (int i = 0; i < myPieces.size(); i++)
	//{

		//std::vector<std::shared_ptr<Square>> legalMoves = myPieces[i]->getLegalMoves(board, color);
		
		//myfile << legalMoves.size() << "\n";
		//myfile.close();
		
		//for(int j = 0; j < legalMoves.size(); j++)
		//	return Move(myPieces[i]->getPosition(), legalMoves[j], color);
	//}

	return Move(board->getBoard()[1][0], board->getBoard()[2][0], color);
}





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