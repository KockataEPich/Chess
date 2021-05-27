#pragma once
#include "ChessPiece.h"

class ChessPiece;

class Square
{
private:
	ChessPiece* chessPiece = nullptr;

	int x;
	int y;

public:
	Square(int x, int y, ChessPiece* chessPiece);
	~Square();
	ChessPiece* getPiece();
	int getX();
	int getY();
	void setPiece(ChessPiece* chessPiece);
	void removePiece();
};

