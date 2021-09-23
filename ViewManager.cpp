#include "ViewManager.h"
#include "StartFrame.h"

ViewManager::ViewManager(wxFrame* frame, wxGridSizer* grid) {
	wxImage image;
	wxPNGHandler* handler = new wxPNGHandler();

	image.AddHandler(handler);
	//bitmap.
	image.LoadFile("640px-Chess_Pieces_Sprite.svg.png");
	// Extract the images of the pieces from the larger image.
	wxBitmap b(image);

	m_blackKing = b.GetSubBitmap(wxRect(5, 113, 100, 100));
	m_blackQueen = b.GetSubBitmap(wxRect(110, 113, 100, 100));
	m_blackBishop = b.GetSubBitmap(wxRect(215, 113, 100, 100));
	m_blackKnight = b.GetSubBitmap(wxRect(323, 113, 100, 100));
	m_blackRook = b.GetSubBitmap(wxRect(433, 113, 100, 100));
	m_blackPawn = b.GetSubBitmap(wxRect(535, 113, 100, 100));

	m_whiteKing = b.GetSubBitmap(wxRect(5, 5, 100, 100));
	m_whiteQueen = b.GetSubBitmap(wxRect(110, 5, 100, 100));
	m_whiteBishop = b.GetSubBitmap(wxRect(215, 5, 100, 100));
	m_whiteKnight = b.GetSubBitmap(wxRect(323, 5, 100, 100));
	m_whiteRook = b.GetSubBitmap(wxRect(433, 5, 100, 100));
	m_whitePawn = b.GetSubBitmap(wxRect(535, 5, 100, 100));

	for (int x = 0; x < 8; x++) {
		std::vector<wxBitmapButton*> newVector;
		chessBoard.push_back(newVector);
		for (int y = 0; y < 8; y++) {
			chessBoard[x].push_back(new wxBitmapButton(frame, 10000 + (y * 8 + x), wxBitmap()));
			grid->Add(chessBoard[x][y], 1, wxEXPAND | wxALL);
			chessBoard[x][y]->Bind(wxEVT_COMMAND_BUTTON_CLICKED, &StartFrame::onButtonClicked, frame);
		}
	}
}