#include "Board.h"
#include "Queen.h"
#include "Pawn.h"
#include "Rook.h"
#include "Knight.h"
#include "Bishop.h"
#include "King.h"

Board::Board()
{
	for (int i = 0; i < 8; i++){
		sqr_vec rowVector;
		board.push_back(rowVector);
		for (int j = 0; j < 8; j++) {
			shr_sqr newSquare = std::make_shared<Square>(i, j, nullptr);
			board.at(i).push_back(newSquare);
		}
	}
	/////////////////////////////////////////////// WHITE INIT ///////////////////////////////

	for (int y = 0; y < 8; y++){
		shr_piece newPiece = std::make_shared<Pawn>((*this)(6, y), PlayerSide::WHITE);
		(*this)(6, y)->setPiece(newPiece);
		whitePieces.push_back(newPiece);
	}

	shr_piece newPiece1 = std::make_shared<Rook>((*this)(7, 0), PlayerSide::WHITE);

	(*this)(7, 0)->setPiece(newPiece1);
	whitePieces.push_back(newPiece1);

	shr_piece newPiece2 = std::make_shared<Knight>((*this)(7, 1), PlayerSide::WHITE);

	(*this)(7,1)->setPiece(newPiece2);  
	whitePieces.push_back(newPiece2);

	shr_piece newPiece3 = std::make_shared<Bishop>((*this)(7, 2), PlayerSide::WHITE);

	(*this)(7, 2)->setPiece(newPiece3);
	whitePieces.push_back(newPiece3);

	shr_piece newPiece4 = std::make_shared<Queen>((*this)(7, 3), PlayerSide::WHITE);

	(*this)(7, 3)->setPiece(newPiece4);
	whitePieces.push_back(newPiece4);

	shr_piece newPiece5 = std::make_shared<King>((*this)(7, 4), PlayerSide::WHITE);

	(*this)(7, 4)->setPiece(newPiece5);
	whitePieces.push_back(newPiece5);

	shr_piece newPiece6 = std::make_shared<Bishop>((*this)(7, 5), PlayerSide::WHITE);

	(*this)(7, 5)->setPiece(newPiece6);
	whitePieces.push_back(newPiece6);


	shr_piece newPiece7 = std::make_shared<Knight>((*this)(7, 6), PlayerSide::WHITE);

	(*this)(7, 6)->setPiece(newPiece7);
	whitePieces.push_back(newPiece7);

	shr_piece newPiece8 = std::make_shared<Rook>((*this)(7, 7), PlayerSide::WHITE);

	(*this)(7, 7)->setPiece(newPiece8);
	whitePieces.push_back(newPiece8);




	//////////////////////////////////////////////////// BLACK INIT /////////////////////////////
	for (int y = 0; y < 8; y++)
	{
		shr_piece newPiece = std::make_shared<Pawn>((*this)(1, y), PlayerSide::BLACK);

		(*this)(1, y)->setPiece(newPiece);
		blackPieces.push_back(newPiece);
	}

	shr_piece newPiece9 = std::make_shared<Rook>((*this)(0, 0), PlayerSide::BLACK);

	(*this)(0, 0)->setPiece(newPiece9);
	blackPieces.push_back(newPiece9);

	shr_piece newPiece10 = std::make_shared<Knight>((*this)(0, 1), PlayerSide::BLACK);

	(*this)(0, 1)->setPiece(newPiece10);
	blackPieces.push_back(newPiece10);

	shr_piece newPiece11 = std::make_shared<Bishop>((*this)(0, 2), PlayerSide::BLACK);

	(*this)(0, 2)->setPiece(newPiece11);
	blackPieces.push_back(newPiece11);

	shr_piece newPiece12 = std::make_shared<Queen>((*this)(0, 3), PlayerSide::BLACK);

	(*this)(0, 3)->setPiece(newPiece12);
	blackPieces.push_back(newPiece12);

	shr_piece newPiece13 = std::make_shared<King>((*this)(0, 4), PlayerSide::BLACK);

	(*this)(0, 4)->setPiece(newPiece13);
	blackPieces.push_back(newPiece13);

	shr_piece newPiece14 = std::make_shared<Bishop>((*this)(0, 5), PlayerSide::BLACK);

	(*this)(0, 5)->setPiece(newPiece14);
	blackPieces.push_back(newPiece14);


	shr_piece newPiece15 = std::make_shared<Knight>((*this)(0, 6), PlayerSide::BLACK);

	(*this)(0, 6)->setPiece(newPiece15);
	blackPieces.push_back(newPiece15);

	shr_piece newPiece16 = std::make_shared<Rook>((*this)(0, 7), PlayerSide::BLACK);

	(*this)(0, 7)->setPiece(newPiece16);
	blackPieces.push_back(newPiece16);

}

Board::~Board() {
	for (int i = 0; i < board.size(); i++) {
		board.at(i).clear();
	}
		
	board.clear();

	for (int i = 0; i < whitePieces.size(); i++){
		whitePieces.at(i).reset();
	}

	for (int i = 0; i < blackPieces.size(); i++) {
		blackPieces.at(i).reset();
	}

	whitePieces.clear();
	blackPieces.clear();
}

board_vec Board::getBoard()			{ return board;					}
std::string Board::getWinner()			{ return winner;				}
bool Board::isOver()					{ return gameIsOver;			} 
shr_sqr Board::operator()(int x, int y) { return board[x][y];	}

piece_vec Board::getPieceList(PlayerSide side){ 
	return (side == PlayerSide::WHITE) ? whitePieces : blackPieces;
}

void Board::makeMove(Move& move){
	auto newSquare = [](Move& move, Board* board){
		return board->getBoard()[move.getNewLocation()->getX()][move.getNewLocation()->getY()];
	};

	shr_piece NextSquarePiece = board[move.getNewLocation()->getX()][move.getNewLocation()->getY()]->getPiece();

	checkPieceAndDeleteIfNecessary(NextSquarePiece, move);
	checkForCastleUp(move, board[move.getNewLocation()->getX()][move.getNewLocation()->getY()]);

	newSquare(move, this)->setPiece(move.getOldLocation()->getPiece());
	newSquare(move, this)->getPiece()->setPosition(newSquare(move, this));

	if (!newSquare(move, this)->getPiece()->hasMoved()) {
		newSquare(move, this)->getPiece()->setFirstMove(false);
		move.changeFirstMoveOfPiece();
	}
	move.getOldLocation()->removePiece();

	handlePiecePromotion(board[move.getNewLocation()->getX()][move.getNewLocation()->getY()], move);
}

void Board::removePiece(shr_piece& pieceToDelete) {
	if (pieceToDelete->getOwner() == PlayerSide::WHITE)
		for (int i = 0; i < whitePieces.size(); i++)
			if (pieceToDelete == whitePieces.at(i)) {
				whitePieces.erase(whitePieces.begin() + i);
				return;
			}

	for (int i = 0; i < blackPieces.size(); i++)
		if (pieceToDelete == blackPieces[i]) {
			blackPieces.erase(blackPieces.begin() + i);
			break;
		}
	return;
}

void Board::checkPieceAndDeleteIfNecessary(shr_piece& newPiece, Move& move) {
	if (newPiece == nullptr)
		return;
	
	if (newPiece->getName() == "King") {
		move.set_captured_piece(newPiece);
		removePiece(newPiece);
		gameIsOver = true;
		winner = newPiece->getOwner().getOpposite().toString() + " Wins!";
	}
	else {
		move.set_captured_piece(newPiece);
		removePiece(newPiece);
	}
}

// Method that checks if the move is intended to be a castleUp
void Board::checkForCastleUp(Move& move, shr_sqr& newSquare) {
	shr_piece piece = move.getOldLocation()->getPiece();

	auto sqrYOff = [](int y, Move& move, board_vec& board) {
		return board[move.getOldLocation()->getX()][y];
	};

	if (piece->hasMoved() == false && piece->getName() == "King"){
		if (move.getOldLocation()->getY() - newSquare->getY() == -2) {
			move.setCastleUpTrue();
			Move rookMove(sqrYOff(7, move, board),
				sqrYOff(5, move, board), move.getSide());
			this->makeMove(rookMove);
		}
		else if (move.getOldLocation()->getY() - newSquare->getY() == 3) {
			move.setCastleUpTrue();
			Move rookMove(sqrYOff(0, move, board),
				sqrYOff(2, move, board), move.getSide());
			this->makeMove(rookMove);
		}
	}
}

// Method that promotes the pawn when it reaches the end of the opposite side.
// Currently only promotes to a Queen
void Board::handlePiecePromotion(shr_sqr& newSquare, Move& move) {
	auto movedPiece = newSquare->getPiece();
	int x = movedPiece->getPosition()->getX();
	if (movedPiece->getName() == "Pawn" && (x == 7 || x == 0)) {
		move.isPromoting();
		shr_piece promotedPiece = std::make_shared<Queen>(newSquare, move.getSide());
		newSquare->setPiece(promotedPiece);

		move.setPromotedPiece(promotedPiece);

		if (move.getSide() == PlayerSide::WHITE)
			whitePieces.push_back(promotedPiece);
		else
			blackPieces.push_back(promotedPiece);

		removePiece(movedPiece);
	}
}

void Board::unmakeMove(Move& move) {
	auto sqrYOff = [](int y, Move& move, board_vec& board) {
		return board[move.getOldLocation()->getX()][y];
	};

	Move backwards_move(move.getNewLocation(), move.getOldLocation(), move.getSide());
	this->makeMove(backwards_move);

	if (move.hasPromoted()) {
		shr_piece promoted_piece = move.getPromotedPiece();
		removePiece(promoted_piece);


		shr_piece pawnPiece = std::make_shared<Pawn>(move.getOldLocation(), move.getSide());
		if (move.getSide() == PlayerSide::WHITE)
			whitePieces.push_back(pawnPiece);
		else
			blackPieces.push_back(pawnPiece);

		pawnPiece->setFirstMove(false);
		move.getOldLocation()->setPiece(pawnPiece);
	}

	if (move.hasChangedFirstMoveOfPiece())
		move.getOldLocation()->getPiece()->setFirstMove(true);

	if (move.get_captured_piece() != nullptr) {
		move.getNewLocation()->setPiece(move.get_captured_piece());
		move.get_captured_piece()->setPosition(move.getNewLocation());
		this->getPieceList(move.getSide().getOpposite()).push_back(move.get_captured_piece());
	}

	if (move.isCastleUp()){
		if (move.getOldLocation()->getY() - move.getNewLocation()->getY() == -2) {
			Move rookMove(sqrYOff(5, move, board),
				sqrYOff(7, move, board), move.getSide());
			this->makeMove(rookMove);
			sqrYOff(7, move, board)->getPiece()->setFirstMove(true);
		}
		else if (move.getOldLocation()->getY() - move.getNewLocation()->getY() == 3) {
			Move rookMove(sqrYOff(2, move, board),
				sqrYOff(0, move, board), move.getSide());
			this->makeMove(rookMove);
			sqrYOff(0, move, board)->getPiece()->setFirstMove(true);
		}
	}
}

move_vec Board::getAllLegalMovesForPlayer(PlayerSide side) {
	piece_vec myPieces = this->getPieceList(side);
	move_vec all_legal_moves;
	for (auto& i : myPieces) {
		move_vec current_legal_moves = i->getLegalMoves(*this, side);
		for (auto& j : current_legal_moves)
			all_legal_moves.push_back(j);
	}
	return all_legal_moves;
}














