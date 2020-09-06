#ifndef _mWindow_HPP_
#define _mWINDOW_HPP_

#include "wx/wxprec.h"

#ifndef WX_PRECOMP
#include "wx/wx.h"
#endif

#include "version.h"

#ifndef wxHAS_IMAGES_IN_RESOURCES
#include "../res/macroroni_128.xpm"
#endif

class makWindow : public wxFrame {
public:
	makWindow(const wxString &title);

	void OnQuit(wxCommandEvent &event);
	void OnAbout(wxCommandEvent &event);
	void OnHelp(wxCommandEvent &event);

private:
	wxDECLARE_EVENT_TABLE();
};

#endif