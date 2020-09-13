#ifndef _mWINDOW_HPP_
#define _mWINDOW_HPP_

#include "wx/wx.h"

#include "version.h"

#include "mAbout.hpp"
#include "mApp.hpp"

#include "res/add_22.xpm"
#include "res/delete_22.xpm"
#include "res/macroroni_128.xpm"
#include "res/save_22.xpm"

class makWindow : public wxFrame {
public:
	makWindow(const wxString &title);
	~makWindow() = default;

	void OnOpen(wxCommandEvent &event);
	void OnQuit(wxCommandEvent &event);
	void OnAbout(wxCommandEvent &event);
	void OnHelp(wxCommandEvent &event);
	void OnCloseWindow(wxCloseEvent &event);

private:
	wxDECLARE_EVENT_TABLE();
	wxListBox *_macros;
	wxTextCtrl *_tbox;
	wxTextCtrl *_sbox;
};

#endif