#pragma once
#include "GLobalHeader.h"

class ViewManager{
public:
  ViewManager(wxFrame* frame, wxGridSizer* grid);

private:
  std::vector<std::vector<wxBitmapButton*>> chessBoard;

  wxGridSizer* grid;

  wxBitmap m_blackKing;
  wxBitmap m_blackQueen;
  wxBitmap m_blackBishop;
  wxBitmap m_blackKnight;
  wxBitmap m_blackRook;
  wxBitmap m_blackPawn;

  wxBitmap m_whiteKing;
  wxBitmap m_whiteQueen;
  wxBitmap m_whiteBishop;
  wxBitmap m_whiteKnight;
  wxBitmap m_whiteRook;
  wxBitmap m_whitePawn;
};

