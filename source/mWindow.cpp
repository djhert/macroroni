#include "mWindow.hpp"

makWindow::makWindow(const wxString &title) :
		wxFrame(NULL, wxID_ANY, title, wxDefaultPosition, wxSize(800, 600)) {

	SetIcon(wxICON(macroroni_128));

	wxMenu *fileMenu = new wxMenu;
	fileMenu->Append(wxID_EXIT, "Exit");

	wxMenu *helpMenu = new wxMenu;
	helpMenu->Append(wxID_HELP, "Help");
	helpMenu->Append(wxID_ABOUT, "About");

	wxMenuBar *menuBar = new wxMenuBar();
	menuBar->Append(fileMenu, "&File");
	menuBar->Append(helpMenu, "&Help");
	SetMenuBar(menuBar);
}

wxBEGIN_EVENT_TABLE(makWindow, wxFrame)
		EVT_MENU(wxID_EXIT, makWindow::OnQuit)
				EVT_MENU(wxID_ABOUT, makWindow::OnAbout)
						EVT_MENU(wxID_HELP, makWindow::OnHelp)
								wxEND_EVENT_TABLE();

void makWindow::OnQuit(wxCommandEvent &WXUNUSED(event)) {
	Close(true);
}

void makWindow::OnAbout(wxCommandEvent &WXUNUSED(event)) {
	wxMessageBox(wxString::Format(
						 "Macroroni and Keys v%s\n"
						 "A cross-platform text expander\n\n"
						 "Copyright: David Hertenstein (hlfstr) 2020\n\n"
						 "Running on: %s.",
						 _VERSION_STRING,
						 wxGetOsDescription()),
			"About MaK",
			wxOK | wxICON_INFORMATION,
			this);
}

void makWindow::OnHelp(wxCommandEvent &WXUNUSED(event)) {
	wxLaunchDefaultBrowser("https://github.com/hlfstr/macroroni", wxBROWSER_NOBUSYCURSOR);
}
