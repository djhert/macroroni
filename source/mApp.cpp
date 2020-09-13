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

	Tray = new makTray();

#if defined(__WXOSX__) && wxOSX_USE_COCOA
	Dock = new makTray();
#endif

	MainWin = new makWindow("Macroroni and Keys");

	return true;
}

void mApp::Quit() {
	MainWin->Destroy();
	Tray->Destroy();
#if defined(__WXOSX__) && wxOSX_USE_COCOA
	Dock->Destroy();
#endif
}