#include "mTray.hpp"

makTray::makTray(wxTaskBarIconType iconType) :
		wxTaskBarIcon(iconType) {
#if defined(__WXOSX__) && wxOSX_USE_COCOA
	if (iconType == wxTBI_DOCK)
		SetIcon(wxICON(macroroni_128), _("Makroroni and Keys"));
	else
#endif
		SetIcon(wxICON(macroroni_32), _("Makroroni and Keys"));
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
	if (!mApp::App()->MainWin) {
		mApp::App()->MainWin = new makWindow("Macroroni and Keys");
		return;
	}
	if (mApp::App()->MainWin->IsBeingDeleted())
		mApp::App()->MainWin = new makWindow("Macroroni and Keys");
	else
		mApp::App()->MainWin->Destroy();
}

wxMenu *makTray::CreatePopupMenu() {
	wxMenu *menu = new wxMenu;
	// If pointer is valid
	if (mApp::App()->MainWin) {
		if (mApp::App()->MainWin->IsBeingDeleted()) {
			menu->Append(20, "&Show Window");
		} else {
			menu->Append(20, "&Hide Window");
		}
	} else
		menu->Append(20, "&Show Window");
	menu->AppendSeparator();
	menu->Append(wxID_EXIT, "&Exit");
	return menu;
}