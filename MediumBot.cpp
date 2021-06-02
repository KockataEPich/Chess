#include "MediumBot.h"
#include <iostream>
#include <fstream>
#include <random>

MediumBot::MediumBot(PlayerSide color)
{
	this->color = color;
}

Move* MediumBot::getMove(Board* board) {
	//The input would be a on click input
	std::vector<std::shared_ptr<ChessPiece>> myPieces = board->getPieceList(color);

	int bestBoardValue = INT_MIN;
	Move* bestMove = nullptr;

	for (int i = 0; i < myPieces.size(); i++)
	{
		std::vector<std::shared_ptr<Square>>* legalMoves = myPieces[i]->getLegalMoves(board, color);
		for(int j = 0; j < legalMoves->size(); j++) {

			Board* newBoard = new Board(board->getBoard(),
				board->getPieceList(PlayerSide::WHITE),
				board->getPieceList(PlayerSide::BLACK));

			Move* move = new Move(
				myPieces[i]->getPosition(), legalMoves->at(j), color);

			newBoard->makeMove(move);

			int currentBoardValue = evaluator->evaluateBoard(newBoard, color);

			if (currentBoardValue > bestBoardValue)
			{
				bestBoardValue = currentBoardValue;
				bestMove = move;
			}
			delete(newBoard);
		}

	}

	return bestMove;

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