#include "HardEvaluator.h"

int HardEvaluator::evaluateBoard(Board& board, PlayerSide pColor) {
	int ourPiecesSum = 0;
	int enemyPiecesSum = 0;



	piece_vec pieces = board.getPieceList(pColor);

	for (int i = 0; i < pieces.size(); i++) {
		std::string name = pieces.at(i)->getName();
		if (name == "Pawn") {
			ourPiecesSum += pawnPieceValue;
			continue;
		}
		if (name == "Rook") {
			ourPiecesSum += rookPieceValue;
			continue;
		}

		if (name == "Knight") {
			ourPiecesSum += knightPieceValue;
			continue;
		}
		if (name == "Bishop") {
			ourPiecesSum += bishopPieceValue;
			continue;
		}
		if (name == "Queen") {
			ourPiecesSum += queenPieceValue;
			continue;
		}
		if (name == "King")
			ourPiecesSum += kingPieceValue;
	}

	pieces = board.getPieceList(pColor.getOpposite());

	for (int i = 0; i < pieces.size(); i++) {
		std::string name = pieces.at(i)->getName();
		if (name == "Pawn") {
			enemyPiecesSum += (int)(pawnPieceValue * enemyOffSet);
			continue;
		}
		if (name == "Rook") {
			enemyPiecesSum += (int)(rookPieceValue * enemyOffSet);
			continue;
		}
		if (name == "Knight") {
			enemyPiecesSum += (int)(knightPieceValue * enemyOffSet);
			continue;
		}
		if (name == "Bishop") {
			enemyPiecesSum += (int)(bishopPieceValue * enemyOffSet);
			continue;
		}
		if (name == "Queen") {
			enemyPiecesSum += (int)(queenPieceValue * enemyOffSet);
			continue;
		}
		if (name == "King")
			enemyPiecesSum += (int)(kingPieceValue / enemyOffSet);
	}

	return ourPiecesSum - enemyPiecesSum;
}
