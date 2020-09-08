#include "mApp.hpp"

wxIMPLEMENT_APP(mApp);

bool mApp::OnInit() {
	if (!wxApp::OnInit())
		return false;

	new mTray();

	return true;
}