#ifndef _mTRAYICON_HPP_
#define _mTRAYICON_HPP_

#include "res/macroroni_24.xpm"
#include "wx/taskbar.h"
#include "wx/wx.h"

#include "mApp.hpp"

class makWindow;

class makTray : public wxTaskBarIcon {
public:
	makTray(wxTaskBarIconType iconType = wxTBI_DEFAULT_TYPE);
	~makTray() = default;

	void OnWindowClick(wxTaskBarIconEvent &event);

	void OnQuit(wxCommandEvent &event);
	void OnWindowShow(wxCommandEvent &event);

	wxMenu *CreatePopupMenu() override;

private:
	wxDECLARE_EVENT_TABLE();
};

#endif