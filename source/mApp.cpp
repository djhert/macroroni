#include "mApp.hpp"

wxIMPLEMENT_APP(mApp);

bool mApp::OnInit() {
	if (!wxApp::OnInit())
		return false;

	makWindow *win = new makWindow("Macroroni and Keys");

	win->Show(true);

	return true;
}