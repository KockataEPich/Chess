#pragma once
#include "ChessPiece.h"
#include "Queen.h"

class ChessPiece;

class Square
{
private:
	ChessPiece* chessPiece = nullptr;

	int x;
	int y;

public:
	Square(int x, int y, ChessPiece* chessPiece);
	ChessPiece* getPiece();
	int getX();
	int getY();
	void setPiece(ChessPiece* chessPiece);
	void removePiece();
};

