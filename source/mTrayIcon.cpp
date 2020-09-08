#include "mTrayIcon.hpp"

mTray::mTray(wxTaskBarIconType iconType) :
		wxTaskBarIcon(iconType) {
	SetIcon(wxICON(macroroni_128), _("Makroroni and Keys"));

	// Create Application Window
	mainWin = new makWindow("Macroroni and Keys");
	mainWin->_setTray(this);
}

wxBEGIN_EVENT_TABLE(mTray, wxTaskBarIcon)
		EVT_MENU(wxID_EXIT, mTray::OnQuit)
				EVT_MENU(20, mTray::OnWindowShow)
						EVT_TASKBAR_LEFT_DCLICK(mTray::OnWindowClick)
								wxEND_EVENT_TABLE();

void mTray::OnWindowClick(wxTaskBarIconEvent &WXUNUSED(event)) {
	PopupMenu(CreatePopupMenu());
}

void mTray::OnQuit(wxCommandEvent &WXUNUSED(event)) {
	mainWin->Destroy();
	Destroy();
}

void mTray::OnWindowShow(wxCommandEvent &WXUNUSED(event)) {
	mainWin->Show(!mainWin->IsShown());
}

wxMenu *mTray::CreatePopupMenu() {
	wxMenu *menu = new wxMenu;
	if (mainWin->IsShown())
		menu->Append(20, "&Hide Window");
	else
		menu->Append(20, "&Show Window");
	menu->AppendSeparator();
	menu->Append(wxID_EXIT, "&Exit");
	return menu;
}