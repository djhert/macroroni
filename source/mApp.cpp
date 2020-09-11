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
	MainWin = new makWindow("Macroroni and Keys");

	return true;
}

void mApp::Quit() {
	Tray->Destroy();
	MainWin->Destroy();
}