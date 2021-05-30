#include "EasyBot.h"


EasyBot::EasyBot(PlayerSide color)
{
	this->color = color;
}

Move EasyBot::getMove(Board* board)
{		
	//The input would be a on click input
	//std::vector<std::shared_ptr<ChessPiece>> myPieces = board->getPieceList(color);

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

	return Move(board->getBoard()[1][0], board->getBoard()[2][0], color);
}
