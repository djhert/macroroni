#include "mApp.hpp"

wxIMPLEMENT_APP(mApp);

mApp *mApp::_instance = NULL;

mApp *mApp::App() {
	return _instance;
}

bool mApp::OnInit() {
	if (!wxApp::OnInit())
		return false;

	_instance = this;

	MainWin = new makWindow("Macroroni and Keys");

	Tray = new makTray();

#ifdef __WXOSX__
	Dock = new makTray(wxTBI_DOCK);
#endif

	if (_file.IsEmpty())
		_file = wxGetHomeDir() + "/.mak";
#ifdef _DEBUG
	std::cout << "Using: " << _file << std::endl;
#endif

	if (Storage.Set(_file))
		Storage.Empty != Storage.Open();

	return true;
}

void mApp::Quit() {
	MainWin->Destroy();
	Tray->Destroy();
#ifdef __WXOSX__
	Dock->Destroy();
#endif
}

#ifndef __WXMSW__
void mApp::OnInitCmdLine(wxCmdLineParser &parser) {
	parser.SetDesc(cmdLineDesc);
	parser.SetSwitchChars(wxT("-"));
}

bool mApp::OnCmdLineParsed(wxCmdLineParser &parser) {
	if (parser.Parse() == -1)
		return false;

	parser.Found(wxT("f"), &_file);

	return true;
}
#endif