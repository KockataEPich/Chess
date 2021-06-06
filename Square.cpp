#include "Square.h"

Square::Square(int x, int y, shr_piece chessPiece){
	this->x = x;
	this->y = y;
	this->chessPiece = chessPiece;
}
Square::~Square(){}
int Square::getX(){	return x; }
int Square::getY(){	return y; }
shr_piece Square::getPiece(){ return chessPiece; }
void Square::setPiece(shr_piece chessPiece){ this->chessPiece = chessPiece; }
void Square::removePiece(){	this->chessPiece = nullptr;}

