#ifndef _mWINDOW_HPP_
#define _mWINDOW_HPP_

#include "wx/wx.h"

#include "version.h"

#include "mAbout.hpp"

#include "res/macroroni_128.xpm"

class makWindow : public wxFrame {
public:
	makWindow(const wxString &title);

	void OnOpen(wxCommandEvent &event);
	void OnQuit(wxCommandEvent &event);
	void OnAbout(wxCommandEvent &event);
	void OnHelp(wxCommandEvent &event);

private:
	wxDECLARE_EVENT_TABLE();
};

#endif