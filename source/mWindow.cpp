#include "mWindow.hpp"

makWindow::makWindow(const wxString &title) :
		wxFrame(NULL, wxID_ANY, title, wxDefaultPosition, wxSize(800, 600)) {

	SetIcon(wxICON(macroroni_128));

	wxMenu *fileMenu = new wxMenu;
	fileMenu->Append(wxID_NEW, "&New", "&New blank file");
	fileMenu->Append(wxID_OPEN, "&Open", "&Open MaK file");
	fileMenu->Append(wxID_SAVE, "&Save", "&Save file as ~/.mak");
	fileMenu->AppendSeparator();
	fileMenu->Append(wxID_EXIT, "&Exit");

	wxMenu *helpMenu = new wxMenu;
	helpMenu->Append(wxID_HELP, "&Help");
	helpMenu->AppendSeparator();
	helpMenu->Append(wxID_ABOUT, "&About");

	wxMenuBar *menuBar = new wxMenuBar();
	menuBar->Append(fileMenu, "&File");
	menuBar->Append(helpMenu, "&Help");
	SetMenuBar(menuBar);
}

wxBEGIN_EVENT_TABLE(makWindow, wxFrame)
		EVT_MENU(wxID_OPEN, makWindow::OnOpen)
				EVT_MENU(wxID_EXIT, makWindow::OnQuit)
						EVT_MENU(wxID_ABOUT, makWindow::OnAbout)
								EVT_MENU(wxID_HELP, makWindow::OnHelp)
										wxEND_EVENT_TABLE();

void makWindow::OnOpen(wxCommandEvent &WXUNUSED(event)) {
	wxFileDialog *dg = new wxFileDialog(this, _("Choose a file"),
			wxEmptyString, wxEmptyString, wxEmptyString,
			wxFD_OPEN, wxDefaultPosition);

	if (dg->ShowModal() == wxID_OK) {
		wxString doc = dg->GetPath();
		SetTitle(wxString("Macroroni and Keys - ") << dg->GetFilename());
	}
	dg->Destroy();
}

void makWindow::OnQuit(wxCommandEvent &WXUNUSED(event)) {
	Close(true);
}

void makWindow::OnAbout(wxCommandEvent &WXUNUSED(event)) {
	new mAbout(new wxBitmap(macroroni_128_xpm), this, "About MaK");
}

void makWindow::OnHelp(wxCommandEvent &WXUNUSED(event)) {
	wxLaunchDefaultBrowser("https://github.com/hlfstr/macroroni", wxBROWSER_NOBUSYCURSOR);
}
