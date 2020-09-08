#ifndef _mWINDOW_HPP_
#define _mWINDOW_HPP_

#include "wx/wx.h"

#include "version.h"

#include "mAbout.hpp"
#include "mTrayIcon.hpp"

#include "res/macroroni_128.xpm"

class mTray;
class makWindow : public wxFrame {
public:
	makWindow(const wxString &title);

	void OnOpen(wxCommandEvent &event);
	void OnQuit(wxCommandEvent &event);
	void OnAbout(wxCommandEvent &event);
	void OnHelp(wxCommandEvent &event);
	void OnCloseWindow(wxCloseEvent &event);

	void _setTray(mTray *t);

private:
	mTray *_tray;
	wxDECLARE_EVENT_TABLE();
};

#endif