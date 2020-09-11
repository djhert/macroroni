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
	makWindow *MainWin;

private:
	static mApp *_instance;
};

#endif