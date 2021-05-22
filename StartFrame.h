#pragma once
#include "GLobalHeader.h"

class StartFrame : public wxFrame
{
    
public:
    StartFrame();

public:
    wxButton* startButton = nullptr;

    void onStartButtonClicked(wxCommandEvent& evt);

    void startGame();

    void playChessGame();

    wxDECLARE_EVENT_TABLE();


    
};

