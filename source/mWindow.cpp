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

	wxArrayString str = wxArrayString();
	for (int i = 0; i < 100; i++) {
		str.Add(_(".macro" + std::to_string(i)));
	}
	// Final Window Sizer
	wxBoxSizer *winSizer = new wxBoxSizer(wxHORIZONTAL);

	// Create Left side
	wxBoxSizer *hbox = new wxBoxSizer(wxHORIZONTAL);
	wxBoxSizer *vbox = new wxBoxSizer(wxVERTICAL);
	// label
	wxStaticText *label = new wxStaticText(this, 2001, _("Macros"));
	wxFont font = wxFont(wxFontInfo(12).Bold());
	label->SetFont(font);
	hbox->Add(label, wxSizerFlags().Proportion(0).Center().Border(wxALL, 4));
	//Spacer
	hbox->Add(-1, -1, wxSizerFlags().Proportion(1));
	//Add Button
	wxButton *add = new wxButton(this, 2002, _(""),
			wxDefaultPosition, wxSize(32, -1));
	add->SetBitmap(wxICON(add_22));
	hbox->Add(add, wxSizerFlags().Proportion(0).Center().Border(wxALL, 4));
	// Delete Button
	wxButton *del = new wxButton(this, 2003, _(""),
			wxDefaultPosition, wxSize(32, -1));
	del->SetBitmap(wxICON(delete_22));
	hbox->Add(del, wxSizerFlags().Proportion(0).Center().Border(wxALL, 4));
	// Add buttons to vbox
	vbox->Add(hbox, wxSizerFlags().Proportion(0));
	// List box
	_macros = new wxListBox(this, 2000);
	_macros->InsertItems(str, 0);
	vbox->Add(_macros, wxSizerFlags().Proportion(1).Expand().Border(wxALL, 4));
	// Finish Left
	winSizer->Add(vbox, wxSizerFlags().Proportion(0).Expand().Border(wxALL, 4));

	// Create Right Side
	hbox = new wxBoxSizer(wxHORIZONTAL);
	vbox = new wxBoxSizer(wxVERTICAL);
	// Label
	label = new wxStaticText(this, 4001, _("&Replacement Text"));
	label->SetFont(font);
	vbox->Add(label, wxSizerFlags().Proportion(0).Left().Border(wxUP | wxDOWN, 10));
	// Text Box
	_tbox = new wxTextCtrl(this, 4000, _(""),
			wxDefaultPosition, wxDefaultSize,
			wxTE_MULTILINE, wxDefaultValidator, wxTextCtrlNameStr);
	vbox->Add(_tbox, wxSizerFlags().Proportion(1).Expand().Border(wxALL, 4));
	// Bottom bar
	label = new wxStaticText(this, 4002, _("&Shortcut"));
	label->SetFont(font);
	hbox->Add(label, wxSizerFlags().Proportion(0).Center().Border(wxALL, 4));
	_sbox = new wxTextCtrl(this, 4003, _(""),
			wxDefaultPosition, wxSize(200, -1));
	hbox->Add(_sbox, wxSizerFlags().Proportion(0).Left().Center().Border(wxALL, 4));
	//Spacer2
	hbox->Add(-1, -1, wxSizerFlags().Proportion(1).Expand());
	// Delete Button
	wxButton *save = new wxButton(this, 4004, _("&Save"));
	save->SetBitmap(wxICON(save_22));
	hbox->Add(save, wxSizerFlags().Proportion(0).Border(wxALL, 4));
	vbox->Add(hbox, wxSizerFlags().Proportion(0).Expand().Border(wxALL, 4));
	// Finish Right
	winSizer->Add(vbox, wxSizerFlags().Proportion(1).Expand().Border(wxALL, 4));
	SetSizer(winSizer);
	Show(true);
}

wxBEGIN_EVENT_TABLE(makWindow, wxFrame)
		EVT_CLOSE(makWindow::OnCloseWindow)
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

void makWindow::OnQuit(wxCommandEvent &event) {
	mApp::App()->Quit();
}

void makWindow::OnAbout(wxCommandEvent &WXUNUSED(event)) {
	new mAbout(new wxBitmap(macroroni_128_xpm), this, "About MaK");
}

void makWindow::OnHelp(wxCommandEvent &WXUNUSED(event)) {
	wxLaunchDefaultBrowser("https://github.com/hlfstr/macroroni", wxBROWSER_NOBUSYCURSOR);
}

void makWindow::OnCloseWindow(wxCloseEvent &WXUNUSED(event)) {
	Destroy();
}