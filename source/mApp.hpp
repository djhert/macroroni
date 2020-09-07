#ifndef _mAPP_HPP_
#define _mAPP_HPP_

#include "wx/wx.h"

#include "mWindow.hpp"

class mApp : public wxApp {
public:
	virtual bool OnInit() override;
};

#endif