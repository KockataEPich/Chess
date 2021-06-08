#include "MediumBotEvaluator.h"

int MediumBotEvaluator::evaluateBoard(Board* board, PlayerSide pColor)
{
	int ourPiecesSum = 0;
	int enemyPiecesSum = 0;
	
	
	std::vector<std::shared_ptr<ChessPiece>>* pieces = board->getPieceList(pColor);

	for (int i = 0; i < pieces->size(); i++) {
		std::string name = pieces->at(i)->getName();
		if (name == "Pawn")
			ourPiecesSum += pawnPieceValue;
		if (name == "Rook")
			ourPiecesSum += rookPieceValue;
		if (name == "Knight")
			ourPiecesSum += knightPieceValue;
		if (name == "Bishop")
			ourPiecesSum += bishopPieceValue;
		if (name == "Queen")
			ourPiecesSum += queenPieceValue;
		if (name == "King")
			ourPiecesSum += kingPieceValue;
	}

	pieces = board->getPieceList(pColor.getOpposite());

	for (int i = 0; i < pieces->size(); i++) {
		std::string name = pieces->at(i)->getName();
		if (name == "Pawn")
			enemyPiecesSum += pawnPieceValue;
		if (name == "Rook")
			enemyPiecesSum += rookPieceValue;
		if (name == "Knight")
			enemyPiecesSum += knightPieceValue;
		if (name == "Bishop")
			enemyPiecesSum += bishopPieceValue;
		if (name == "Queen")
			enemyPiecesSum += queenPieceValue;
		if (name == "King")
			enemyPiecesSum += kingPieceValue;
	}

	return ourPiecesSum - enemyPiecesSum;
}
