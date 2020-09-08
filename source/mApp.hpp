#ifndef _mAPP_HPP_
#define _mAPP_HPP_

#include "wx/wx.h"

#include "mTrayIcon.hpp"

class mApp : public wxApp {
public:
	virtual bool OnInit() override;
};

#endif