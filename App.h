#pragma once

#include "GLobalHeader.h"
#include "StartFrame.h"

class App : public wxApp
{
private:
	StartFrame* frame;
public:
	App();
	~App();
	virtual bool OnInit();
};
