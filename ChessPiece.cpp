#include "ChessPiece.h"
#include "Pawn.h"
#include "King.h"
#include "Knight.h"
#include "Queen.h"
#include "Bishop.h"
#include "Rook.h"

std::string ChessPiece::getName(){ return name;				}
shr_sqr ChessPiece::getPosition(){ return position.lock();	}
PlayerSide ChessPiece::getOwner(){ return owner;			}
bool ChessPiece::hasMoved()		 { return !firstMove;		}
bool ChessPiece::inRange(int x)  { return x < 8 && x >= 0;  }

void ChessPiece::setPosition(shr_sqr newPosition){
	position = newPosition;
	firstMove = false;
}

void ChessPiece::addVertical(sqr_vec* legalMoves, Board* board, PlayerSide pColor){
	auto pos = position.lock();
	// Down
	for (int i = pos->getX() + 1; i < 8; i++)
		if (endSquare(i, pos->getY(), legalMoves, board, pColor))
			break;
	// Up
	for (int i = pos->getX() - 1; i >= 0; i--) 
		if (endSquare(i, pos->getY(), legalMoves, board, pColor))
			break;
}

void ChessPiece::addHorizontal(sqr_vec* legalMoves, Board* board, PlayerSide pColor){
	auto pos = position.lock();
	// Left
	for (int i = pos->getY() + 1; i < 8; i++)
		if (endSquare(pos->getX(), i, legalMoves, board, pColor))
			break;
	// Right
	for (int i = pos->getY() - 1; i >= 0; i--)
		if (endSquare(pos->getX(), i, legalMoves, board, pColor))
			break;
}
void ChessPiece::addSideways(sqr_vec* legalMoves, Board* board, PlayerSide pColor){
	auto pos = position.lock();
	// Down Right
	for (int i = pos->getX() + 1, j = pos->getY() + 1; i < 8 && j < 8; i++, j++)
		if (endSquare(i, j, legalMoves, board, pColor))
			break;

	// Down Left
	for (int i = pos->getX() + 1, j = pos->getY() - 1; i < 8 && j >= 0; i++, j--)
			if (endSquare(i, j, legalMoves, board, pColor))
				break;

	// Up Right
	for (int i = pos->getX() - 1, j = pos->getY() + 1; i >= 0 && j < 8; i--, j++)
		if (endSquare(i, j, legalMoves, board, pColor))
			break;

	// Up Left
	for (int i = pos->getX() - 1, j = pos->getY() - 1; i >= 0 && j >= 0; i--, j--)
		if (endSquare(i, j, legalMoves, board, pColor))
			break;
}

bool ChessPiece::endSquare(int x, int y, sqr_vec* legalMoves, Board* board, PlayerSide pColor){
	shr_sqr newSquare = board->getBoard()[x][y];
	if (newSquare->getPiece() != nullptr){
		if(newSquare->getPiece()->getOwner() == pColor)
			return true;
		legalMoves->push_back(newSquare);
		return true;
	}
	legalMoves->push_back(newSquare);
	return false;
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