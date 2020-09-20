#include "mTray.hpp"

makTray::makTray(wxTaskBarIconType iconType) :
		wxTaskBarIcon(iconType) {
#ifdef __WXOSX__
	if (iconType == wxTBI_DOCK)
		SetIcon(wxICON(macroroni_128), _("Macroroni and Keys"));
	else
#endif
		SetIcon(wxICON(macroroni_32), _("Macroroni and Keys"));
}

wxBEGIN_EVENT_TABLE(makTray, wxTaskBarIcon)
		EVT_MENU(wxID_EXIT, makTray::OnQuit)
				EVT_MENU(20, makTray::OnWindowShow)
						EVT_TASKBAR_LEFT_DCLICK(makTray::OnWindowClick)
								wxEND_EVENT_TABLE();

void makTray::OnWindowClick(wxTaskBarIconEvent &WXUNUSED(event)) {
	PopupMenu(CreatePopupMenu());
}

void makTray::OnQuit(wxCommandEvent &WXUNUSED(event)) {
	mApp::App()->Quit();
}

void makTray::OnWindowShow(wxCommandEvent &WXUNUSED(event)) {
	mApp::App()->MainWin->ShowWindow(!mApp::App()->MainWin->IsShown());
}

wxMenu *makTray::CreatePopupMenu() {
	wxMenu *menu = new wxMenu;
	if (mApp::App()->MainWin->IsShown())
		menu->Append(20, "&Hide Window");
	else
		menu->Append(20, "&Show Window");
	menu->AppendSeparator();
	menu->Append(wxID_EXIT, "&Exit");
	return menu;
}