#include "ChessPiece.h"
#include "Pawn.h"
#include "King.h"
#include "Knight.h"
#include "Queen.h"
#include "Bishop.h"
#include "Rook.h"

std::string ChessPiece::getName()
{
	return name;
}

shr_sqr ChessPiece::getPosition()
{
	return position.lock();
}

void ChessPiece::setPosition(shr_sqr newPosition)
{
	position = newPosition;
	firstMove = false;
}

PlayerSide ChessPiece::getOwner()
{
	return owner;
}



void ChessPiece::addVertical(sqr_vec* legalMoves, Board* board, PlayerSide pColor){
	
	auto pos = position.lock();
	
	for (int i = pos->getX() + 1; i < 8; i++)
	{

		std::shared_ptr<Square> newSquare = board->getBoard()[i][pos->getY()];
		if (endSquare(newSquare, legalMoves, pColor))
			break;
	}

	for (int i = pos->getX() - 1; i >= 0; i--)
	{
		std::shared_ptr<Square> newSquare = board->getBoard()[i][pos->getY()];

		if (endSquare(newSquare, legalMoves, pColor))
			break;
	}
}


void ChessPiece::addHorizontal(sqr_vec* legalMoves, Board* board, PlayerSide pColor){
	auto pos = position.lock();
	for (int i = pos->getY() + 1; i < 8; i++)
	{
		std::shared_ptr<Square> newSquare = board->getBoard()[pos->getX()][i];

		if (endSquare(newSquare, legalMoves, pColor))
			break;
	}

	for (int i = pos->getY() - 1; i >= 0; i--)
	{
		std::shared_ptr<Square> newSquare = board->getBoard()[pos->getX()][i];

		if (endSquare(newSquare, legalMoves, pColor))
			break;
	}
}
void ChessPiece::addSideways(sqr_vec* legalMoves, Board* board, PlayerSide pColor){
	auto pos = position.lock();
	for (int i = pos->getX() + 1, j = pos->getY() - 1; i < 8 && j >= 0; i++, j--)
	{
		std::shared_ptr<Square> newSquare = board->getBoard()[i][j];
		if (endSquare(newSquare, legalMoves, pColor))
			break;
	}

	for (int i = pos->getX() - 1, j = pos->getY() + 1; i >= 0 && j < 8; i--, j++)
	{
		std::shared_ptr<Square> newSquare = board->getBoard()[i][j];
		if (endSquare(newSquare, legalMoves, pColor))
			break;
	}

	for (int i = pos->getX() + 1, j = pos->getY() + 1; i < 8 && j < 8; i++, j++)
	{
		std::shared_ptr<Square> newSquare = board->getBoard()[i][j];
		if (endSquare(newSquare, legalMoves, pColor))
			break;
	}

	for (int i = pos->getX() - 1, j = pos->getY() - 1; i >= 0 && j >= 0; i--, j--)
	{
		std::shared_ptr<Square> newSquare = board->getBoard()[i][j];
		if (endSquare(newSquare, legalMoves, pColor))
			break;
	}
}

bool ChessPiece::endSquare(shr_sqr newSquare, sqr_vec* legalMoves, PlayerSide pColor)
{
	if (newSquare->getPiece() != nullptr)
	{
		if(newSquare->getPiece()->getOwner() == pColor)
			return true;

		legalMoves->push_back(newSquare);
		return true;
	}

	legalMoves->push_back(newSquare);
	return false;

}

bool ChessPiece::hasMoved() {
	return !firstMove;
}

void ChessPiece::addSquareIfPossible(int xOff, int yOff, sqr_vec* legalMoves, Board* board, PlayerSide pColor) {
	auto pos = position.lock();
	if (!inRange(pos->getX() + xOff) || !inRange(pos->getY() + yOff))
		return;

	auto squareToMove = board->getBoard()[pos->getX() + xOff][pos->getY() + yOff];

	if (squareToMove->getPiece() == nullptr) {
		legalMoves->push_back(squareToMove);
		return;
	}

	if (squareToMove->getPiece()->getOwner() != pColor)
		legalMoves->push_back(squareToMove);

}

shr_piece ChessPiece::clonePiece(shr_piece piece, shr_sqr newPosition) {
	if (piece->getName() == "Pawn")
		return std::make_shared<Pawn>(newPosition, piece->getOwner());
	if (piece->getName() == "King")
		return std::make_shared<King>(newPosition, piece->getOwner());
	if (piece->getName() == "Knight")
		return std::make_shared<Knight>(newPosition, piece->getOwner());
	if (piece->getName() == "Queen")
		return std::make_shared<Queen>(newPosition, piece->getOwner());
	if (piece->getName() == "Rook")
		return std::make_shared<Rook>(newPosition, piece->getOwner());
	if (piece->getName() == "Bishop")
		return std::make_shared<Bishop>(newPosition, piece->getOwner());

}