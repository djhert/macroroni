#ifndef _mTRAYICON_HPP_
#define _mTRAYICON_HPP_

#include "res/macroroni_128.xpm"
#include "wx/taskbar.h"
#include "wx/wx.h"

#include "mWindow.hpp"

class makWindow;

class mTray : public wxTaskBarIcon {
public:
	mTray(wxTaskBarIconType iconType = wxTBI_DEFAULT_TYPE);

	void OnWindowClick(wxTaskBarIconEvent &event);

	void OnQuit(wxCommandEvent &event);
	void OnWindowShow(wxCommandEvent &event);

	wxMenu *CreatePopupMenu() override;

protected:
	makWindow *mainWin;

private:
	wxDECLARE_EVENT_TABLE();
};

#endif