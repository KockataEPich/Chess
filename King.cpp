#include "King.h"
// Constructor
King::King(std::shared_ptr<Square> position, PlayerSide playerSide){
	this->name = "King";
	this->position = position;
	this->owner = playerSide;
}

sqr_vec* King::getLegalMoves(Board* board, PlayerSide currentPlayerColor){
	sqr_vec* legalMoves = new std::vector<std::shared_ptr<Square>>();

	auto pos = position.lock();

	// Add the move on right,left,up and down positions
	addSquareIfPossible( 0,  1, legalMoves, board, currentPlayerColor);
	addSquareIfPossible( 0, -1, legalMoves, board, currentPlayerColor);
	addSquareIfPossible( 1,  0, legalMoves, board, currentPlayerColor);
	addSquareIfPossible(-1,  0, legalMoves, board, currentPlayerColor);
	
	// Add square of bottom right, top right, bottom left and top left
	addSquareIfPossible( 1,  1, legalMoves, board, currentPlayerColor);
	addSquareIfPossible(-1,  1, legalMoves, board, currentPlayerColor);
	addSquareIfPossible( 1, -1, legalMoves, board, currentPlayerColor);
	addSquareIfPossible(-1, -1, legalMoves, board, currentPlayerColor);

	// CastleUp
	addCastleUpIfPossible(legalMoves, board, pos);

	return legalMoves;
}

void King::addSquareIfPossible(int xOff, int yOff, sqr_vec* legalMoves, Board* board, PlayerSide pColor) {
	auto pos = position.lock();
	if (!inRange(pos->getX() + xOff) || !inRange(pos->getY() + yOff))
		return;

	auto squareToMove = board->getBoard()[pos->getX() + xOff][pos->getY() + yOff];

	if (squareToMove->getPiece() == nullptr) {
		legalMoves->push_back(squareToMove);
		return;
	}

	if(squareToMove->getPiece()->getOwner() != pColor)
		legalMoves->push_back(squareToMove);
}

void King::addCastleUpIfPossible(sqr_vec* legalMoves, Board* board, std::shared_ptr<Square> pos){
	if (firstMove) {
		auto sqrYOff = [](int y, Board* board, std::shared_ptr<Square> pos)
		{
			return board->getBoard()[pos->getX()][pos->getY() + y];
		};

		// Check if all the squares until the right rook are empty and if the rook has moved
		if (sqrYOff(1, board, pos)->getPiece() == nullptr &&
			sqrYOff(2, board, pos)->getPiece() == nullptr &&
			sqrYOff(3, board, pos)->getPiece() != nullptr &&
			sqrYOff(3, board, pos)->getPiece()->hasMoved() == false)
			legalMoves->push_back(sqrYOff(2, board, pos));

		// Check if all the squares until the left rook are empty and if the rook has moved
		if (sqrYOff(-1, board, pos)->getPiece() == nullptr &&
			sqrYOff(-2, board, pos)->getPiece() == nullptr &&
			sqrYOff(-3, board, pos)->getPiece() == nullptr &&
			sqrYOff(-4, board, pos)->getPiece() != nullptr &&
			sqrYOff(-4, board, pos)->getPiece()->hasMoved() == false)
			legalMoves->push_back(sqrYOff(-3, board, pos));
	}
}