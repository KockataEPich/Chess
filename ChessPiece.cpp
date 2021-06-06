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

std::shared_ptr<Square> ChessPiece::getPosition()
{
	return position.lock();
}

void ChessPiece::setPosition(std::shared_ptr<Square> newPosition)
{
	position = newPosition;
	firstMove = false;
}

PlayerSide ChessPiece::getOwner()
{
	return owner;
}



void ChessPiece::addVertical(std::vector<std::shared_ptr<Square>>* legalMoves, Board* board, PlayerSide currentPlayerColor){
	
	auto currentPosition = position.lock();
	
	for (int i = currentPosition->getX() + 1; i < 8; i++)
	{

		std::shared_ptr<Square> newSquare = board->getBoard()[i][currentPosition->getY()];
		if (endSquare(newSquare, legalMoves, currentPlayerColor))
			break;
	}

	for (int i = currentPosition->getX() - 1; i >= 0; i--)
	{
		std::shared_ptr<Square> newSquare = board->getBoard()[i][currentPosition->getY()];

		if (endSquare(newSquare, legalMoves, currentPlayerColor))
			break;
	}
}


void ChessPiece::addHorizontal(std::vector<std::shared_ptr<Square>>* legalMoves, Board* board, PlayerSide currentPlayerColor){
	auto currentPosition = position.lock();
	for (int i = currentPosition->getY() + 1; i < 8; i++)
	{
		std::shared_ptr<Square> newSquare = board->getBoard()[currentPosition->getX()][i];

		if (endSquare(newSquare, legalMoves, currentPlayerColor))
			break;
	}

	for (int i = currentPosition->getY() - 1; i >= 0; i--)
	{
		std::shared_ptr<Square> newSquare = board->getBoard()[currentPosition->getX()][i];

		if (endSquare(newSquare, legalMoves, currentPlayerColor))
			break;
	}
}
void ChessPiece::addSideways(std::vector<std::shared_ptr<Square>>* legalMoves, Board* board, PlayerSide currentPlayerColor){
	auto currentPosition = position.lock();
	for (int i = currentPosition->getX() + 1, j = currentPosition->getY() - 1; i < 8 && j >= 0; i++, j--)
	{
		std::shared_ptr<Square> newSquare = board->getBoard()[i][j];
		if (endSquare(newSquare, legalMoves, currentPlayerColor))
			break;
	}

	for (int i = currentPosition->getX() - 1, j = currentPosition->getY() + 1; i >= 0 && j < 8; i--, j++)
	{
		std::shared_ptr<Square> newSquare = board->getBoard()[i][j];
		if (endSquare(newSquare, legalMoves, currentPlayerColor))
			break;
	}

	for (int i = currentPosition->getX() + 1, j = currentPosition->getY() + 1; i < 8 && j < 8; i++, j++)
	{
		std::shared_ptr<Square> newSquare = board->getBoard()[i][j];
		if (endSquare(newSquare, legalMoves, currentPlayerColor))
			break;
	}

	for (int i = currentPosition->getX() - 1, j = currentPosition->getY() - 1; i >= 0 && j >= 0; i--, j--)
	{
		std::shared_ptr<Square> newSquare = board->getBoard()[i][j];
		if (endSquare(newSquare, legalMoves, currentPlayerColor))
			break;
	}
}

bool ChessPiece::endSquare(std::shared_ptr<Square> newSquare, std::vector<std::shared_ptr<Square>>* legalMoves,
	PlayerSide currentPlayerColor)
{
	if (newSquare->getPiece() != nullptr)
	{
		if(newSquare->getPiece()->getOwner() == currentPlayerColor)
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

std::shared_ptr<ChessPiece> ChessPiece::clonePiece(std::shared_ptr<ChessPiece> piece, 
												std::shared_ptr<Square> newPosition) {
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