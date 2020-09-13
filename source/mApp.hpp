#ifndef _mAPP_HPP_
#define _mAPP_HPP_

#include "wx/wx.h"

#include "mTray.hpp"
#include "mWindow.hpp"

class makTray;
class makWindow;
class mApp : public wxApp {
public:
	~mApp() = default;

	virtual bool OnInit() override;
	void Quit();

	static mApp *App();

	makTray *Tray;
#if defined(__WXOSX__) && wxOSX_USE_COCOA
	makTray *Dock;
#endif

	makWindow *MainWin;

private:
	static mApp *_instance;
};

#endif