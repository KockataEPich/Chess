#include "cApp.h"
wxIMPLEMENT_APP(cApp);

cApp::cApp()
{

}

cApp::~cApp()
{

}


bool cApp::onInit()
{
	m_frame1 = new cMain();
	m_frame1->Show();
	return true;
}