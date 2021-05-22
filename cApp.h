#pragma once

#include "wx/wx.h"
#include "cApp.h"
#include "cMain.h"

class cApp : public wxApp
{
private:
	cMain* m_frame1 = nullptr;
public:
	cApp();
	~cApp();
	virtual bool onInit();
};

