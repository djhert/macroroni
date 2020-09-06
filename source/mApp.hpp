#ifndef _mAPP_HPP_
#define _mAPP_HPP_

#include "wx/wxprec.h"

#ifndef WX_PRECOMP
#include "wx/wx.h"
#endif

#include "mWindow.hpp"

class mApp : public wxApp {
public:
	virtual bool OnInit() override;
};

#endif