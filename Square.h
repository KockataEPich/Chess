#pragma once
#include "ChessPiece.h"
class Square
{
private:
	ChessPiece* chessPiece;

	std::pair<int, int> position;
	ChessPiece* chessPiece;

public:
	Square(int x, int y, ChessPiece* chessPiece);
	ChessPiece* getPiece();
	std::pair<char, int> getPosition();
	void setPiece(ChessPiece* chessPiece);
	void removePiece();
};

