#include "App.h"

wxIMPLEMENT_APP(App);

App::App()
{

}

App::~App()
{

}


bool App::OnInit()
{
    frame = new StartFrame();
    frame->Show(true);
    return true;
}
