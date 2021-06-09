#include "Board.h"
#include "Queen.h"
#include "Pawn.h"
#include "Rook.h"
#include "Knight.h"
#include "Bishop.h"
#include "King.h"

Board::Board()
{
	board = new board_vec();
	whitePieces = new piece_vec();
	blackPieces = new piece_vec();
	for (int i = 0; i < 8; i++)
	{
		sqr_vec* rowVector = new sqr_vec();
		board->push_back(rowVector);
		for (int j = 0; j < 8; j++) {
			shr_sqr newSquare = std::make_shared<Square>(i, j, nullptr);
			board->at(i)->push_back(newSquare);
		}
	}
	/////////////////////////////////////////////// WHITE INIT ///////////////////////////////

	for (int y = 0; y < 8; y++)
	{
		shr_piece newPiece = std::make_shared<Pawn>((*this)(6, y), PlayerSide::WHITE);

		(*this)(6, y)->setPiece(newPiece);
		whitePieces->push_back(newPiece);
	}

	shr_piece newPiece1 = std::make_shared<Rook>((*this)(7, 0), PlayerSide::WHITE);

	(*this)(7, 0)->setPiece(newPiece1);
	whitePieces->push_back(newPiece1);

	shr_piece newPiece2 = std::make_shared<Knight>((*this)(7, 1), PlayerSide::WHITE);

	(*this)(7,1)->setPiece(newPiece2);  
	whitePieces->push_back(newPiece2);

	shr_piece newPiece3 = std::make_shared<Bishop>((*this)(7, 2), PlayerSide::WHITE);

	(*this)(7, 2)->setPiece(newPiece3);
	whitePieces->push_back(newPiece3);

	shr_piece newPiece4 = std::make_shared<Queen>((*this)(7, 3), PlayerSide::WHITE);

	(*this)(7, 3)->setPiece(newPiece4);
	whitePieces->push_back(newPiece4);

	shr_piece newPiece5 = std::make_shared<King>((*this)(7, 4), PlayerSide::WHITE);

	(*this)(7, 4)->setPiece(newPiece5);
	whitePieces->push_back(newPiece5);

	shr_piece newPiece6 = std::make_shared<Bishop>((*this)(7, 5), PlayerSide::WHITE);

	(*this)(7, 5)->setPiece(newPiece6);
	whitePieces->push_back(newPiece6);


	shr_piece newPiece7 = std::make_shared<Knight>((*this)(7, 6), PlayerSide::WHITE);

	(*this)(7, 6)->setPiece(newPiece7);
	whitePieces->push_back(newPiece7);

	shr_piece newPiece8 = std::make_shared<Rook>((*this)(7, 7), PlayerSide::WHITE);

	(*this)(7, 7)->setPiece(newPiece8);
	whitePieces->push_back(newPiece8);




	//////////////////////////////////////////////////// BLACK INIT /////////////////////////////
	for (int y = 0; y < 8; y++)
	{
		shr_piece newPiece = std::make_shared<Pawn>((*this)(1, y), PlayerSide::BLACK);

		(*this)(1, y)->setPiece(newPiece);
		blackPieces->push_back(newPiece);
	}

	shr_piece newPiece9 = std::make_shared<Rook>((*this)(0, 0), PlayerSide::BLACK);

	(*this)(0, 0)->setPiece(newPiece9);
	blackPieces->push_back(newPiece9);

	shr_piece newPiece10 = std::make_shared<Knight>((*this)(0, 1), PlayerSide::BLACK);

	(*this)(0, 1)->setPiece(newPiece10);
	blackPieces->push_back(newPiece10);

	shr_piece newPiece11 = std::make_shared<Bishop>((*this)(0, 2), PlayerSide::BLACK);

	(*this)(0, 2)->setPiece(newPiece11);
	blackPieces->push_back(newPiece11);

	shr_piece newPiece12 = std::make_shared<Queen>((*this)(0, 3), PlayerSide::BLACK);

	(*this)(0, 3)->setPiece(newPiece12);
	blackPieces->push_back(newPiece12);

	shr_piece newPiece13 = std::make_shared<King>((*this)(0, 4), PlayerSide::BLACK);

	(*this)(0, 4)->setPiece(newPiece13);
	blackPieces->push_back(newPiece13);

	shr_piece newPiece14 = std::make_shared<Bishop>((*this)(0, 5), PlayerSide::BLACK);

	(*this)(0, 5)->setPiece(newPiece14);
	blackPieces->push_back(newPiece14);


	shr_piece newPiece15 = std::make_shared<Knight>((*this)(0, 6), PlayerSide::BLACK);

	(*this)(0, 6)->setPiece(newPiece15);
	blackPieces->push_back(newPiece15);

	shr_piece newPiece16 = std::make_shared<Rook>((*this)(0, 7), PlayerSide::BLACK);

	(*this)(0, 7)->setPiece(newPiece16);
	blackPieces->push_back(newPiece16);

}

Board::Board(board_vec* givenBoard) {
	board = new board_vec();
	whitePieces = new piece_vec();
	blackPieces = new piece_vec();

	for (int i = 0; i < 8; i++)
	{
		sqr_vec* rowVector = new sqr_vec();
		board->push_back(rowVector);
		for (int j = 0; j < 8; j++) {
			shr_sqr newSquare = std::make_shared<Square>(i, j, nullptr);
			board->at(i)->push_back(newSquare);
		}
	}

	for (int i = 0; i < 8; i++) {
		for (int j = 0; j < 8; j++) {
			if (givenBoard->at(i)->at(j)->getPiece() != nullptr) {
				shr_piece piece = givenBoard->at(i)->at(j)->getPiece()->clonePiece(
					givenBoard->at(i)->at(j)->getPiece(), board->at(i)->at(j));

				board->at(i)->at(j)->setPiece(piece);
				if (piece->getOwner() == PlayerSide::WHITE)
					whitePieces->push_back(piece);
				else
					blackPieces->push_back(piece);
			}
		}
	}
}

Board::~Board() {
	for (int i = 0; i < board->size(); i++) {
		board->at(i)->clear();
		delete(board->at(i));
	}
		
	board->clear();

	for (int i = 0; i < whitePieces->size(); i++){
		whitePieces->at(i).reset();
	}

	for (int i = 0; i < blackPieces->size(); i++) {
		blackPieces->at(i).reset();
	}

	whitePieces->clear();

	blackPieces->clear();

	delete(board);
	delete(whitePieces);
	delete(blackPieces);
}

board_vec* Board::getBoard()			{ return board;					}
std::string Board::getWinner()			{ return winner;				}
bool Board::isOver()					{ return gameIsOver;			} 
shr_sqr Board::operator()(int x, int y) { return board->at(x)->at(y);	}

piece_vec* Board::getPieceList(PlayerSide side){ 
	return (side == PlayerSide::WHITE) ? whitePieces : blackPieces;
}

void Board::makeMove(Move* move){
	auto newSquare = [](Move* move, Board* board){
		return (*board)(move->getNewLocation()->getX(), move->getNewLocation()->getY());
	};

	shr_piece NextSquarePiece = newSquare(move, this)->getPiece();

	checkPieceAndDeleteIfNecessary(NextSquarePiece, move);
	checkForCastleUp(move, newSquare(move, this));

	newSquare(move, this)->setPiece(move->getOldLocation()->getPiece());
	newSquare(move, this)->getPiece()->setPosition(newSquare(move, this));
	move->getOldLocation()->removePiece();

	handlePiecePromotion(newSquare(move, this), move);
}

void Board::eraseElement(shr_piece pieceToDelete, PlayerSide color) {
	if (color == PlayerSide::WHITE)
		for (int i = 0; i < whitePieces->size(); i++)
			if (pieceToDelete == whitePieces->at(i)) {
				whitePieces->erase(whitePieces->begin() + i);
				return;
			}

	for (int i = 0; i < blackPieces->size(); i++)
		if (pieceToDelete == blackPieces->at(i)) {
			blackPieces->erase(blackPieces->begin() + i);
			break;
		}
	return;
}

void Board::checkPieceAndDeleteIfNecessary(shr_piece newPiece, Move* move) {
	if (newPiece != nullptr) {
		if (newPiece->getName() == "King") {
			gameIsOver = true;
			winner = newPiece->getOwner().getOpposite().toString() + " Wins!";
		}
		else
			eraseElement(newPiece, move->getSide().getOpposite());
	}
}

// Method that checks if the move is intended to be a castleUp
void Board::checkForCastleUp(Move* move, shr_sqr newSquare) {
	shr_piece piece = move->getOldLocation()->getPiece();

	auto sqrYOff = [](int y, Move* move, board_vec* board) {
		return board->at(move->getOldLocation()->getX())->at(y);
	};

	if (piece->hasMoved() == false && piece->getName() == "King"){
		if (move->getOldLocation()->getY() - newSquare->getY() == -2) {
			Move* rookMove = new Move(sqrYOff(7, move, board),
				sqrYOff(5, move, board), move->getSide());
			this->makeMove(rookMove);
			delete rookMove;
		}
		if (move->getOldLocation()->getY() - newSquare->getY() == 3) {
			Move* rookMove = new Move(sqrYOff(0, move, board),
				sqrYOff(2, move, board), move->getSide());
			this->makeMove(rookMove);
			delete rookMove;
		}
	}
}

// Method that promotes the pawn when it reaches the end of the opposite side.
// Currently only promotes to a Queen
void Board::handlePiecePromotion(shr_sqr newSquare, Move* move) {
	auto movedPiece = newSquare->getPiece();
	int x = movedPiece->getPosition()->getX();
	if (movedPiece->getName() == "Pawn" && (x == 7 || x == 0)) {
		shr_piece promotedPiece = std::make_shared<Queen>(newSquare, move->getSide());
		newSquare->setPiece(promotedPiece);

		if (move->getSide() == PlayerSide::WHITE)
			whitePieces->push_back(promotedPiece);
		else
			blackPieces->push_back(promotedPiece);
	}
}












