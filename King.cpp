#include "King.h"
// Constructor
King::King(shr_sqr position, PlayerSide playerSide) {
	this->name = "King";
	this->position = position;
	this->owner = playerSide;
}

move_vec King::getLegalMoves(Board& board, PlayerSide pColor) {
	sqr_vec legalMoves;

	// Add the move on right,left,up and down positions
	addSquareIfPossible(0, 1, legalMoves, board, pColor);
	addSquareIfPossible(0, -1, legalMoves, board, pColor);
	addSquareIfPossible(1, 0, legalMoves, board, pColor);
	addSquareIfPossible(-1, 0, legalMoves, board, pColor);

	// Add square of bottom right, top right, bottom left and top left
	addSquareIfPossible(1, 1, legalMoves, board, pColor);
	addSquareIfPossible(-1, 1, legalMoves, board, pColor);
	addSquareIfPossible(1, -1, legalMoves, board, pColor);
	addSquareIfPossible(-1, -1, legalMoves, board, pColor);

	// CastleUp
	addCastleUpIfPossible(legalMoves, board);

	return makeMovesOutOfEndPosition(legalMoves);
}

void King::addCastleUpIfPossible(sqr_vec& legalMoves, Board& board) {
	auto pos = position.lock();
	if (firstMove) {
		auto sqrYOff = [](int y, Board& board, shr_sqr& pos)
		{
			return board(pos->getX(), pos->getY() + y);
		};

		// Check if all the squares until the right rook are empty and if the rook has moved
		if (sqrYOff(1, board, pos)->getPiece() == nullptr &&
			sqrYOff(2, board, pos)->getPiece() == nullptr &&
			sqrYOff(3, board, pos)->getPiece() != nullptr &&
			sqrYOff(3, board, pos)->getPiece()->hasMoved() == false)
			legalMoves.push_back(sqrYOff(2, board, pos));

		// Check if all the squares until the left rook are empty and if the rook has moved
		if (sqrYOff(-1, board, pos)->getPiece() == nullptr &&
			sqrYOff(-2, board, pos)->getPiece() == nullptr &&
			sqrYOff(-3, board, pos)->getPiece() == nullptr &&
			sqrYOff(-4, board, pos)->getPiece() != nullptr &&
			sqrYOff(-4, board, pos)->getPiece()->hasMoved() == false)
			legalMoves.push_back(sqrYOff(-3, board, pos));
	}
}