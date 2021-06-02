#include "MediumBotEvaluator.h"

int MediumBotEvaluator::evaluateBoard(Board* board, PlayerSide side)
{
	int ourPiecesSum = 0;
	int enemyPiecesSum = 0;
	
	
	std::vector<std::shared_ptr<ChessPiece>> pieces = board->getPieceList(side);
	
	if (side == PlayerSide::WHITE){

		for (int i = 0; i < pieces.size(); i++) {
			if (pieces[i]->getName() == "Pawn")
				ourPiecesSum += pawnPieceValue;
			if (pieces[i]->getName() == "Rook")
				ourPiecesSum += rookPieceValue;
			if (pieces[i]->getName() == "Knight")
				ourPiecesSum += knightPieceValue;
			if (pieces[i]->getName() == "Bishop")
				ourPiecesSum += bishopPieceValue;
			if (pieces[i]->getName() == "Queen")
				ourPiecesSum += queenPieceValue;
			if (pieces[i]->getName() == "King")
				ourPiecesSum += kingPieceValue;
		}

		pieces = board->getPieceList(PlayerSide::BLACK);

		for (int i = 0; i < pieces.size(); i++) {
			if (pieces[i]->getName() == "Pawn")
				enemyPiecesSum += pawnPieceValue;
			if (pieces[i]->getName() == "Rook")
				enemyPiecesSum += rookPieceValue;
			if (pieces[i]->getName() == "Knight")
				enemyPiecesSum += knightPieceValue;
			if (pieces[i]->getName() == "Bishop")
				enemyPiecesSum += bishopPieceValue;
			if (pieces[i]->getName() == "Queen")
				enemyPiecesSum += queenPieceValue;
			if (pieces[i]->getName() == "King")
				enemyPiecesSum += kingPieceValue;
		}

		return ourPiecesSum - enemyPiecesSum;
	}

	

	for (int i = 0; i < pieces.size(); i++) {
		if (pieces[i]->getName() == "Pawn")
			ourPiecesSum += pawnPieceValue;
		if (pieces[i]->getName() == "Rook")
			ourPiecesSum += rookPieceValue;
		if (pieces[i]->getName() == "Knight")
			ourPiecesSum += knightPieceValue;
		if (pieces[i]->getName() == "Bishop")
			ourPiecesSum += bishopPieceValue;
		if (pieces[i]->getName() == "Queen")
			ourPiecesSum += queenPieceValue;
		if (pieces[i]->getName() == "King")
			ourPiecesSum += kingPieceValue;
	}

	pieces = board->getPieceList(PlayerSide::WHITE);

	for (int i = 0; i < pieces.size(); i++) {
		if (pieces[i]->getName() == "Pawn")
			enemyPiecesSum += pawnPieceValue;
		if (pieces[i]->getName() == "Rook")
			enemyPiecesSum += rookPieceValue;
		if (pieces[i]->getName() == "Knight")
			enemyPiecesSum += knightPieceValue;
		if (pieces[i]->getName() == "Bishop")
			enemyPiecesSum += bishopPieceValue;
		if (pieces[i]->getName() == "Queen")
			enemyPiecesSum += queenPieceValue;
		if (pieces[i]->getName() == "King")
			enemyPiecesSum += kingPieceValue;
	}

	return ourPiecesSum - enemyPiecesSum;
	
}
